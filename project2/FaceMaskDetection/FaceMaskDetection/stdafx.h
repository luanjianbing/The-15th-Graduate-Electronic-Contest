#pragma once
#ifndef COMMON_H
#define COMMON_H

#include <iostream>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

typedef struct _ObjInfo
{
	cv::Rect2f _faceLoc;	// 坐标
	float _conf;	// 置信度
	int _faceCla;	// 判断结果
} ObjInfo;

#endif // COMMON_H
