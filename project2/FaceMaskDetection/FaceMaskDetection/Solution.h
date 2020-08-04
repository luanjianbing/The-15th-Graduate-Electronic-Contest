#pragma once
#ifndef SOLUTION_H
#define SOLUTION_H

#include "stdafx.h"
#include <opencv2\dnn\dnn.hpp>
//// 人脸特侦提取
#include "face_detection.h"
#include "face_alignment.h"
#include "face_identification.h"

#include "common.h"
#include "math.h"
#include "time.h"

#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

#include <QString>

//#include <future>
//#include <chrono>  
#include <thread>
#include <mutex>

#define EXPECT_NE(a, b) if ((a) == (b)) std::cout << "ERROR: "
#define EXPECT_EQ(a, b) if ((a) != (b)) std::cout << "ERROR: "

#include "anchor.h"

class Solution
{
public:
	Solution();
	~Solution();

	bool initialParam();

	// 口罩佩戴检测
	const int ssdFaceMaskDetect(cv::Mat& inMat, std::vector<ObjInfo>& vReList);

	//
	bool extractFaceFeature(cv::Mat dstMat, std::vector<ObjInfo> listInfo, std::vector<std::string> &name);
	
	void extractFaceFeatureAndSave(cv::Mat vectFace, std::string &name);

	std::vector<std::vector<std::string>> csvData;
	float *allFeature;
	void readFeatureCSV();
	inline float string_to_float(std::string str);

private:
	std::string modelPath;
	cv::Mat frame;

	cv::dnn::Net m_mapNet;

	// 创建线程锁对象
	std::mutex mtx;

#define totalDefaultBox  7756
	int priorNum[5] = { 5776, 1444, 400, 100, 36 };

	std::vector<ObjInfo> decode_bbox(cv::Mat& rawBox, cv::Mat& rawCls);
	float rectOverlap(cv::Rect2f rect_1, cv::Rect2f rect_2);

	seeta::FaceDetection *detector;
	seeta::FaceAlignment *point_detector;
	seeta::FaceIdentification *face_recognizer;
	
	bool hasFirstRes = false;
	bool hasLastRes = false;
	bool threadFlags = false;
	std::vector<int> nameGet;
	std::vector<int> lastNameGet;

	void softmax(cv::Mat &x, int row, int column);
};

#endif