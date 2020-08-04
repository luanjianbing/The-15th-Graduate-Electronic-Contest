#pragma once

#include <QMessageBox>
#include <QTimer>

#include "ui_RegisterFace.h"

#include "CameraDrive.h"
#include "Solution.h"


class RegisterFace : public QWidget
{
	Q_OBJECT

	public:
		RegisterFace(Camera *cam, QWidget *parent = Q_NULLPTR);
		~RegisterFace();

	private:
		Ui::RegisterFaceClass ui;

		Camera *myCameraRegister;
		void clonePic(cv::Mat &dst);
		QTimer *timerForRegister;

		std::string toRegisterUserName = "";

		cv::Size CameraSize = cv::Size(640, 480);	// ±¾»úÉãÏñÍ·ÏñËØ
		cv::Rect faceArea;
		int faceImportCnt = 100 * 3 + 1;

	private slots:
		void onButtonCloseClicked();

		void onButtonStartRecordClicked();

		void camShot();
};
