#pragma once
#ifndef CAMERADRIVE_H
#define CAMERADRIVE_H

#include "stdafx.h"
#include <thread>
#include <mutex>

#include<HCNetSDK.h>
#include<plaympeg4.h>
#include<PlayM4.h>
#include "Solution.h"
class Camera {
public:
	Camera();
	~Camera();

	cv::Mat frame;

	void camStart();
	bool stop;
	void camStop();

	void getImage(int threadId);

	void show();
	void getImage(cv::Mat &getImg);

private:
	//std::string source1 = "rtsp://admin:tongxint704@192.168.1.64:554/h265/ch1/main/av_stream/1";
	cv::VideoCapture capture1;

	void startthread1();

	LONG lUserID;
	bool Init();
	bool Login(char* sDeviceAddress, char* sUserName, char* sPassword, WORD wPort);            //µÇÂ½
	
	static void *video_capture_thread1(void *arg);
};

#endif // CAMERADRIVE_H