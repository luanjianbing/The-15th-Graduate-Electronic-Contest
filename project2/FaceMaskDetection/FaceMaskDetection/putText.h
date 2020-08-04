#ifndef PUTTEXT_H_
#define PUTTEXT_H_

#include <windows.h>
#include <string>
#include <opencv2/opencv.hpp>

void GetStringSize(HDC hDC, const char* str, int* w, int* h);
void putTextZH(cv::Mat &dst, const char* str, cv::Point org, cv::Scalar color, int fontSize,
    const char *fn = "Arial", bool italic = false, bool underline = false);

#endif // PUTTEXT_H_
