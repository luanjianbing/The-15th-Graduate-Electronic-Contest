#include "CameraDrive.h"
#include <mutex>

std::mutex cameraGet;
Camera::Camera() {
	stop = false;
}

void Camera::camStart() {
	//if (capture1.open(source1, cv::CAP_FFMPEG)) 
	//if (capture1.open(0, cv::CAP_DSHOW))	// 不加cv::CAP_DSHOW退出时会报warning
	//	startthread1();
	//else
	//	throw "Camera Open Failed";
	if (this->Init())
	{
		if (this->Login("58.199.166.90", "admin", "tongxint704", 8000))//用户名以及密码，根据此系列博客一中的方法查看或设置
		{
			std::cout << "login successfully" << std::endl;
			this->show();
			//startthread1();
		}
		else
			throw "camera login error";
	}
	else
		throw "camera init error";
}

LONG g_nPort;
cv::Mat g_BGRImage;
cv::Mat lastImage;
bool isOnConvertingImage = false;
bool newImage = true;
//std::mutex mtxImg;
//数据解码回调函数，
//功能：将YV_12格式的视频数据流转码为可供opencv处理的BGR类型的图片数据，并实时显示。
Solution solution;
void CALLBACK DecCBFun(long nPort, char* pBuf, long nSize, FRAME_INFO* pFrameInfo, long nUser, long nReserved2)
{

	if (pFrameInfo->nType == T_YV12)
	{
		//if (!newImage)
		//	return;
		//newImage = false;
		isOnConvertingImage = true;
		cameraGet.lock();
		if (g_BGRImage.empty())
		{
			g_BGRImage.create(pFrameInfo->nHeight, pFrameInfo->nWidth, CV_8UC3);
		}
		cv::Mat YUVImage(pFrameInfo->nHeight + pFrameInfo->nHeight / 2, pFrameInfo->nWidth, CV_8UC1, (unsigned char*)pBuf);

		cvtColor(YUVImage, g_BGRImage, cv::COLOR_YUV2BGR_YV12);

		//cv::flip(g_BGRImage, g_BGRImage, 1);
		cameraGet.unlock();
		//cv::imshow("", g_BGRImage);
		//cv::waitKey(1);
		isOnConvertingImage = false;
		lastImage = g_BGRImage;
		YUVImage.~Mat();
	}
}

//实时视频码流数据获取 回调函数
void CALLBACK g_RealDataCallBack_V30(LONG lPlayHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser)
{
	if (dwDataType == NET_DVR_STREAMDATA)//码流数据
	{
		if (dwBufSize > 0 && g_nPort != -1)
		{
			if (!PlayM4_InputData(g_nPort, pBuffer, dwBufSize))
			{
				//std::cout << "fail input data" << std::endl;
			}
			else
			{
				//std::cout << "success input data" << std::endl;
			}

		}
	}
}

bool Camera::Login(char* sDeviceAddress, char* sUserName, char* sPassword, WORD wPort)            //登陆
{
	NET_DVR_USER_LOGIN_INFO pLoginInfo = { 0 };
	NET_DVR_DEVICEINFO_V40 lpDeviceInfo = { 0 };

	pLoginInfo.bUseAsynLogin = 0;     //同步登录方式
	strcpy_s(pLoginInfo.sDeviceAddress, sDeviceAddress);
	strcpy_s(pLoginInfo.sUserName, sUserName);
	strcpy_s(pLoginInfo.sPassword, sPassword);
	pLoginInfo.wPort = wPort;

	lUserID = NET_DVR_Login_V40(&pLoginInfo, &lpDeviceInfo);

	if (lUserID < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Camera::Init()
{
	if (NET_DVR_Init())
	{
		return true;
	}
	else
	{
		return false;
	}
}

//视频流显示函数
void Camera::show()
{
	if (PlayM4_GetPort(&g_nPort))            //获取播放库通道号
	{
		if (PlayM4_SetStreamOpenMode(g_nPort, STREAME_REALTIME))      //设置流模式
		{
			if (PlayM4_OpenStream(g_nPort, NULL, 0, 3840 * 2160))         //打开流
			{
				if (PlayM4_SetDecCallBackExMend(g_nPort, DecCBFun, NULL, 0, NULL))
				{
					if (PlayM4_Play(g_nPort, NULL))
					{
						std::cout << "success to set play mode" << std::endl;
					}
					else
					{
						std::cout << "fail to set play mode" << std::endl;
					}
				}
				else
				{
					std::cout << "fail to set dec callback " << std::endl;
				}
			}
			else
			{
				std::cout << "fail to open stream" << std::endl;
			}
		}
		else
		{
			std::cout << "fail to set stream open mode" << std::endl;
		}
	}
	else
	{
		std::cout << "fail to get port" << std::endl;
	}
	//启动预览并设置回调数据流
	NET_DVR_PREVIEWINFO struPlayInfo = { 0 };
	struPlayInfo.hPlayWnd = NULL; //窗口为空，设备SDK不解码只取流
	struPlayInfo.lChannel = 1; //Channel number 设备通道
	struPlayInfo.dwStreamType = 1;// 码流类型，0-主码流，1-子码流，2-码流3，3-码流4, 4-码流5,5-码流6,7-码流7,8-码流8,9-码流9,10-码流10
	struPlayInfo.dwLinkMode = 0;// 0：TCP方式,1：UDP方式,2：多播方式,3 - RTP方式，4-RTP/RTSP,5-RSTP/HTTP 
	struPlayInfo.bBlocked = 1; //0-非阻塞取流, 1-阻塞取流, 如果阻塞SDK内部connect失败将会有5s的超时才能够返回,不适合于轮询取流操作.

	if (NET_DVR_RealPlay_V40(lUserID, &struPlayInfo, g_RealDataCallBack_V30, NULL))
	{
		cv::namedWindow("RGBImage2");
	}
}

void Camera::startthread1() {

	std::thread task(&video_capture_thread1, (void*)this);

	task.detach();
}

void *Camera::video_capture_thread1(void *arg) {
	Camera *came = (Camera *)arg;

	while (!came->stop)
	{
		came->getImage(1);
		
	}

	delete came;
	return 0;
}

void Camera::getImage(int threadId) {
	switch (threadId)
	{
	case 1:
	{
		capture1 >> frame;
		//cv::resize(frame, frame, cv::Size(1280, 720), CV_INTER_AREA);
		break;
	}
	default:
		break;
	}
}

void Camera::getImage(cv::Mat &getImg)
{
	//if (isOnConvertingImage)
	//	getImg = lastImage;
	//else
	cameraGet.lock();
		getImg = g_BGRImage;
		//newImage = true;
		cameraGet.unlock();
	
}

void Camera::camStop() {
	stop = true;
	capture1.release();
	//std::cout << capture1.isOpened() << std::endl;
}

Camera::~Camera() {
	camStop();
}