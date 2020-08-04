/********************************************************************************
** Form generated from reading UI file 'FaceMaskDetection.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACEMASKDETECTION_H
#define UI_FACEMASKDETECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_FaceMaskDetectionClass
{
public:
    QGridLayout *gridLayout;
    QWidget *widgetTitle;
    QGridLayout *gridLayout_4;
    QLabel *labelName;
    QSpacerItem *horizontalSpacer_3;
    QLabel *labelTime;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelIcon;
    QPushButton *buttonMenu;
    QWidget *widgetMain;
    QGridLayout *gridLayout_2;
    QWidget *WidgetDataAnalyse;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QListWidget *listWidgetLog;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_10;
    QLabel *labelUnknownTimeDis;
    QLabel *labelUnknownTime;
    QLabel *labelUnknownMask;
    QLabel *labelUnknownMaskDis;
    QLabel *labelUnknownImage;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_11;
    QChartView *widgetChart;
    QWidget *WidgetRecordDisplay;
    QHBoxLayout *horizontalLayout_2;
    QWidget *wRecordDisplay_1;
    QGridLayout *gridLayout_6;
    QLabel *labelNameDis_1;
    QLabel *labelName_1;
    QLabel *labelMask_1;
    QLabel *labelMaskDis_1;
    QLabel *labelImage_1;
    QWidget *wRecordDisplay_2;
    QGridLayout *gridLayout_7;
    QLabel *labelNameDis_2;
    QLabel *labelName_2;
    QLabel *labelMask_2;
    QLabel *labelMaskDis_2;
    QLabel *labelImage_2;
    QWidget *wRecordDisplay_3;
    QGridLayout *gridLayout_8;
    QLabel *labelName_3;
    QLabel *labelNameDis_3;
    QLabel *labelMask_3;
    QLabel *labelMaskDis_3;
    QLabel *labelImage_3;
    QWidget *wRecordDisplay_4;
    QGridLayout *gridLayout_9;
    QLabel *labelName_4;
    QLabel *labelNameDis_4;
    QLabel *labelMask_4;
    QLabel *labelMaskDis_4;
    QLabel *labelImage_4;
    QWidget *widgetVideoStream;
    QGridLayout *gridLayout_3;
    QLabel *labelVideoStream;

    void setupUi(QWidget *FaceMaskDetectionClass)
    {
        if (FaceMaskDetectionClass->objectName().isEmpty())
            FaceMaskDetectionClass->setObjectName(QString::fromUtf8("FaceMaskDetectionClass"));
        FaceMaskDetectionClass->resize(1500, 1000);
        FaceMaskDetectionClass->setStyleSheet(QString::fromUtf8("background:#020d2c"));
        gridLayout = new QGridLayout(FaceMaskDetectionClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widgetTitle = new QWidget(FaceMaskDetectionClass);
        widgetTitle->setObjectName(QString::fromUtf8("widgetTitle"));
        gridLayout_4 = new QGridLayout(widgetTitle);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        labelName = new QLabel(widgetTitle);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font.setPointSize(11);
        labelName->setFont(font);
        labelName->setStyleSheet(QString::fromUtf8("color:white"));

        gridLayout_4->addWidget(labelName, 0, 1, 2, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        labelTime = new QLabel(widgetTitle);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));
        labelTime->setStyleSheet(QString::fromUtf8("color:gray"));
        labelTime->setFrameShape(QFrame::WinPanel);
        labelTime->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelTime, 0, 3, 2, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        labelIcon = new QLabel(widgetTitle);
        labelIcon->setObjectName(QString::fromUtf8("labelIcon"));
        labelIcon->setPixmap(QPixmap(QString::fromUtf8("icon/titleIco.png")));
        labelIcon->setScaledContents(false);
        labelIcon->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelIcon, 0, 0, 2, 1);

        buttonMenu = new QPushButton(widgetTitle);
        buttonMenu->setObjectName(QString::fromUtf8("buttonMenu"));
        buttonMenu->setStyleSheet(QString::fromUtf8("color:gray"));

        gridLayout_4->addWidget(buttonMenu, 0, 5, 1, 1);

        gridLayout_4->setColumnStretch(0, 1);
        gridLayout_4->setColumnStretch(1, 1);
        gridLayout_4->setColumnStretch(2, 1);
        gridLayout_4->setColumnStretch(3, 3);
        gridLayout_4->setColumnStretch(4, 2);
        gridLayout_4->setColumnStretch(5, 1);

        gridLayout->addWidget(widgetTitle, 0, 0, 1, 1);

        widgetMain = new QWidget(FaceMaskDetectionClass);
        widgetMain->setObjectName(QString::fromUtf8("widgetMain"));
        gridLayout_2 = new QGridLayout(widgetMain);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        WidgetDataAnalyse = new QWidget(widgetMain);
        WidgetDataAnalyse->setObjectName(QString::fromUtf8("WidgetDataAnalyse"));
        verticalLayout = new QVBoxLayout(WidgetDataAnalyse);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(WidgetDataAnalyse);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("background:#162e6c;color:gray"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        listWidgetLog = new QListWidget(groupBox);
        listWidgetLog->setObjectName(QString::fromUtf8("listWidgetLog"));

        gridLayout_5->addWidget(listWidgetLog, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(WidgetDataAnalyse);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("background:#162e6c;color:gray"));
        gridLayout_10 = new QGridLayout(groupBox_2);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        labelUnknownTimeDis = new QLabel(groupBox_2);
        labelUnknownTimeDis->setObjectName(QString::fromUtf8("labelUnknownTimeDis"));

        gridLayout_10->addWidget(labelUnknownTimeDis, 0, 2, 1, 1);

        labelUnknownTime = new QLabel(groupBox_2);
        labelUnknownTime->setObjectName(QString::fromUtf8("labelUnknownTime"));

        gridLayout_10->addWidget(labelUnknownTime, 0, 1, 1, 1);

        labelUnknownMask = new QLabel(groupBox_2);
        labelUnknownMask->setObjectName(QString::fromUtf8("labelUnknownMask"));

        gridLayout_10->addWidget(labelUnknownMask, 1, 1, 1, 1);

        labelUnknownMaskDis = new QLabel(groupBox_2);
        labelUnknownMaskDis->setObjectName(QString::fromUtf8("labelUnknownMaskDis"));

        gridLayout_10->addWidget(labelUnknownMaskDis, 1, 2, 1, 1);

        labelUnknownImage = new QLabel(groupBox_2);
        labelUnknownImage->setObjectName(QString::fromUtf8("labelUnknownImage"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelUnknownImage->sizePolicy().hasHeightForWidth());
        labelUnknownImage->setSizePolicy(sizePolicy);
        labelUnknownImage->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(labelUnknownImage, 0, 0, 2, 1);

        gridLayout_10->setColumnStretch(0, 4);
        gridLayout_10->setColumnStretch(1, 2);
        gridLayout_10->setColumnStretch(2, 4);

        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(WidgetDataAnalyse);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setStyleSheet(QString::fromUtf8("background:#162e6c;color:gray"));
        gridLayout_11 = new QGridLayout(groupBox_3);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        widgetChart = new QChartView(groupBox_3);
        widgetChart->setObjectName(QString::fromUtf8("widgetChart"));

        gridLayout_11->addWidget(widgetChart, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_3);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(2, 2);

        gridLayout_2->addWidget(WidgetDataAnalyse, 0, 1, 2, 1);

        WidgetRecordDisplay = new QWidget(widgetMain);
        WidgetRecordDisplay->setObjectName(QString::fromUtf8("WidgetRecordDisplay"));
        horizontalLayout_2 = new QHBoxLayout(WidgetRecordDisplay);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        wRecordDisplay_1 = new QWidget(WidgetRecordDisplay);
        wRecordDisplay_1->setObjectName(QString::fromUtf8("wRecordDisplay_1"));
        wRecordDisplay_1->setStyleSheet(QString::fromUtf8("background:#162e6c;color:gray"));
        gridLayout_6 = new QGridLayout(wRecordDisplay_1);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        labelNameDis_1 = new QLabel(wRecordDisplay_1);
        labelNameDis_1->setObjectName(QString::fromUtf8("labelNameDis_1"));

        gridLayout_6->addWidget(labelNameDis_1, 0, 2, 1, 1);

        labelName_1 = new QLabel(wRecordDisplay_1);
        labelName_1->setObjectName(QString::fromUtf8("labelName_1"));

        gridLayout_6->addWidget(labelName_1, 0, 1, 1, 1);

        labelMask_1 = new QLabel(wRecordDisplay_1);
        labelMask_1->setObjectName(QString::fromUtf8("labelMask_1"));

        gridLayout_6->addWidget(labelMask_1, 1, 1, 1, 1);

        labelMaskDis_1 = new QLabel(wRecordDisplay_1);
        labelMaskDis_1->setObjectName(QString::fromUtf8("labelMaskDis_1"));

        gridLayout_6->addWidget(labelMaskDis_1, 1, 2, 1, 1);

        labelImage_1 = new QLabel(wRecordDisplay_1);
        labelImage_1->setObjectName(QString::fromUtf8("labelImage_1"));
        sizePolicy.setHeightForWidth(labelImage_1->sizePolicy().hasHeightForWidth());
        labelImage_1->setSizePolicy(sizePolicy);
        labelImage_1->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(labelImage_1, 0, 0, 2, 1);

        gridLayout_6->setColumnStretch(0, 4);
        gridLayout_6->setColumnStretch(1, 2);
        gridLayout_6->setColumnStretch(2, 4);

        horizontalLayout_2->addWidget(wRecordDisplay_1);

        wRecordDisplay_2 = new QWidget(WidgetRecordDisplay);
        wRecordDisplay_2->setObjectName(QString::fromUtf8("wRecordDisplay_2"));
        wRecordDisplay_2->setStyleSheet(QString::fromUtf8("background:#162e6c;color:gray"));
        gridLayout_7 = new QGridLayout(wRecordDisplay_2);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        labelNameDis_2 = new QLabel(wRecordDisplay_2);
        labelNameDis_2->setObjectName(QString::fromUtf8("labelNameDis_2"));

        gridLayout_7->addWidget(labelNameDis_2, 0, 2, 1, 1);

        labelName_2 = new QLabel(wRecordDisplay_2);
        labelName_2->setObjectName(QString::fromUtf8("labelName_2"));

        gridLayout_7->addWidget(labelName_2, 0, 1, 1, 1);

        labelMask_2 = new QLabel(wRecordDisplay_2);
        labelMask_2->setObjectName(QString::fromUtf8("labelMask_2"));

        gridLayout_7->addWidget(labelMask_2, 1, 1, 1, 1);

        labelMaskDis_2 = new QLabel(wRecordDisplay_2);
        labelMaskDis_2->setObjectName(QString::fromUtf8("labelMaskDis_2"));

        gridLayout_7->addWidget(labelMaskDis_2, 1, 2, 1, 1);

        labelImage_2 = new QLabel(wRecordDisplay_2);
        labelImage_2->setObjectName(QString::fromUtf8("labelImage_2"));
        sizePolicy.setHeightForWidth(labelImage_2->sizePolicy().hasHeightForWidth());
        labelImage_2->setSizePolicy(sizePolicy);
        labelImage_2->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(labelImage_2, 0, 0, 2, 1);

        gridLayout_7->setColumnStretch(0, 4);
        gridLayout_7->setColumnStretch(1, 2);
        gridLayout_7->setColumnStretch(2, 4);

        horizontalLayout_2->addWidget(wRecordDisplay_2);

        wRecordDisplay_3 = new QWidget(WidgetRecordDisplay);
        wRecordDisplay_3->setObjectName(QString::fromUtf8("wRecordDisplay_3"));
        wRecordDisplay_3->setStyleSheet(QString::fromUtf8("background:#162e6c;color:gray"));
        gridLayout_8 = new QGridLayout(wRecordDisplay_3);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        labelName_3 = new QLabel(wRecordDisplay_3);
        labelName_3->setObjectName(QString::fromUtf8("labelName_3"));

        gridLayout_8->addWidget(labelName_3, 0, 1, 1, 1);

        labelNameDis_3 = new QLabel(wRecordDisplay_3);
        labelNameDis_3->setObjectName(QString::fromUtf8("labelNameDis_3"));

        gridLayout_8->addWidget(labelNameDis_3, 0, 2, 1, 1);

        labelMask_3 = new QLabel(wRecordDisplay_3);
        labelMask_3->setObjectName(QString::fromUtf8("labelMask_3"));

        gridLayout_8->addWidget(labelMask_3, 1, 1, 1, 1);

        labelMaskDis_3 = new QLabel(wRecordDisplay_3);
        labelMaskDis_3->setObjectName(QString::fromUtf8("labelMaskDis_3"));

        gridLayout_8->addWidget(labelMaskDis_3, 1, 2, 1, 1);

        labelImage_3 = new QLabel(wRecordDisplay_3);
        labelImage_3->setObjectName(QString::fromUtf8("labelImage_3"));
        sizePolicy.setHeightForWidth(labelImage_3->sizePolicy().hasHeightForWidth());
        labelImage_3->setSizePolicy(sizePolicy);
        labelImage_3->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(labelImage_3, 0, 0, 2, 1);

        gridLayout_8->setColumnStretch(0, 4);
        gridLayout_8->setColumnStretch(1, 2);
        gridLayout_8->setColumnStretch(2, 4);

        horizontalLayout_2->addWidget(wRecordDisplay_3);

        wRecordDisplay_4 = new QWidget(WidgetRecordDisplay);
        wRecordDisplay_4->setObjectName(QString::fromUtf8("wRecordDisplay_4"));
        wRecordDisplay_4->setStyleSheet(QString::fromUtf8("background:#162e6c;color:gray"));
        gridLayout_9 = new QGridLayout(wRecordDisplay_4);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        labelName_4 = new QLabel(wRecordDisplay_4);
        labelName_4->setObjectName(QString::fromUtf8("labelName_4"));

        gridLayout_9->addWidget(labelName_4, 0, 1, 1, 1);

        labelNameDis_4 = new QLabel(wRecordDisplay_4);
        labelNameDis_4->setObjectName(QString::fromUtf8("labelNameDis_4"));

        gridLayout_9->addWidget(labelNameDis_4, 0, 2, 1, 1);

        labelMask_4 = new QLabel(wRecordDisplay_4);
        labelMask_4->setObjectName(QString::fromUtf8("labelMask_4"));

        gridLayout_9->addWidget(labelMask_4, 1, 1, 1, 1);

        labelMaskDis_4 = new QLabel(wRecordDisplay_4);
        labelMaskDis_4->setObjectName(QString::fromUtf8("labelMaskDis_4"));

        gridLayout_9->addWidget(labelMaskDis_4, 1, 2, 1, 1);

        labelImage_4 = new QLabel(wRecordDisplay_4);
        labelImage_4->setObjectName(QString::fromUtf8("labelImage_4"));
        sizePolicy.setHeightForWidth(labelImage_4->sizePolicy().hasHeightForWidth());
        labelImage_4->setSizePolicy(sizePolicy);
        labelImage_4->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(labelImage_4, 0, 0, 2, 1);

        gridLayout_9->setColumnStretch(0, 4);
        gridLayout_9->setColumnStretch(1, 2);
        gridLayout_9->setColumnStretch(2, 4);

        horizontalLayout_2->addWidget(wRecordDisplay_4);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 1);

        gridLayout_2->addWidget(WidgetRecordDisplay, 1, 0, 1, 1);

        widgetVideoStream = new QWidget(widgetMain);
        widgetVideoStream->setObjectName(QString::fromUtf8("widgetVideoStream"));
        gridLayout_3 = new QGridLayout(widgetVideoStream);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        labelVideoStream = new QLabel(widgetVideoStream);
        labelVideoStream->setObjectName(QString::fromUtf8("labelVideoStream"));
        sizePolicy.setHeightForWidth(labelVideoStream->sizePolicy().hasHeightForWidth());
        labelVideoStream->setSizePolicy(sizePolicy);
        labelVideoStream->setStyleSheet(QString::fromUtf8("background:black;color:gray"));
        labelVideoStream->setFrameShape(QFrame::WinPanel);
        labelVideoStream->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(labelVideoStream, 0, 0, 1, 1);


        gridLayout_2->addWidget(widgetVideoStream, 0, 0, 1, 1);

        gridLayout_2->setRowStretch(0, 8);
        gridLayout_2->setRowStretch(1, 2);
        gridLayout_2->setColumnStretch(0, 7);
        gridLayout_2->setColumnStretch(1, 3);

        gridLayout->addWidget(widgetMain, 1, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 9);

        retranslateUi(FaceMaskDetectionClass);

        QMetaObject::connectSlotsByName(FaceMaskDetectionClass);
    } // setupUi

    void retranslateUi(QWidget *FaceMaskDetectionClass)
    {
        FaceMaskDetectionClass->setWindowTitle(QApplication::translate("FaceMaskDetectionClass", "FaceMaskDetection", nullptr));
        labelName->setText(QApplication::translate("FaceMaskDetectionClass", "\345\217\243\347\275\251\344\275\251\346\210\264\346\243\200\346\265\213\347\263\273\347\273\237", nullptr));
        labelTime->setText(QString());
        labelIcon->setText(QString());
        buttonMenu->setText(QApplication::translate("FaceMaskDetectionClass", "\350\217\234\345\215\225", nullptr));
        groupBox->setTitle(QApplication::translate("FaceMaskDetectionClass", "\351\242\204\350\255\246", nullptr));
        groupBox_2->setTitle(QApplication::translate("FaceMaskDetectionClass", "\346\234\252\345\270\246\345\217\243\347\275\251\346\212\245\350\255\246", nullptr));
        labelUnknownTimeDis->setText(QString());
        labelUnknownTime->setText(QApplication::translate("FaceMaskDetectionClass", "\346\227\266\351\227\264\357\274\232", nullptr));
        labelUnknownMask->setText(QApplication::translate("FaceMaskDetectionClass", "\345\217\243\347\275\251\357\274\232", nullptr));
        labelUnknownMaskDis->setText(QString());
        labelUnknownImage->setText(QString());
        groupBox_3->setTitle(QApplication::translate("FaceMaskDetectionClass", "\347\273\237\350\256\241", nullptr));
        labelNameDis_1->setText(QString());
        labelName_1->setText(QApplication::translate("FaceMaskDetectionClass", "\345\247\223\345\220\215\357\274\232", nullptr));
        labelMask_1->setText(QApplication::translate("FaceMaskDetectionClass", "\345\217\243\347\275\251\357\274\232", nullptr));
        labelMaskDis_1->setText(QString());
        labelImage_1->setText(QString());
        labelNameDis_2->setText(QString());
        labelName_2->setText(QApplication::translate("FaceMaskDetectionClass", "\345\247\223\345\220\215\357\274\232", nullptr));
        labelMask_2->setText(QApplication::translate("FaceMaskDetectionClass", "\345\217\243\347\275\251\357\274\232", nullptr));
        labelMaskDis_2->setText(QString());
        labelImage_2->setText(QString());
        labelName_3->setText(QApplication::translate("FaceMaskDetectionClass", "\345\247\223\345\220\215\357\274\232", nullptr));
        labelNameDis_3->setText(QString());
        labelMask_3->setText(QApplication::translate("FaceMaskDetectionClass", "\345\217\243\347\275\251\357\274\232", nullptr));
        labelMaskDis_3->setText(QString());
        labelImage_3->setText(QString());
        labelName_4->setText(QApplication::translate("FaceMaskDetectionClass", "\345\247\223\345\220\215\357\274\232", nullptr));
        labelNameDis_4->setText(QString());
        labelMask_4->setText(QApplication::translate("FaceMaskDetectionClass", "\345\217\243\347\275\251\357\274\232", nullptr));
        labelMaskDis_4->setText(QString());
        labelImage_4->setText(QString());
        labelVideoStream->setText(QApplication::translate("FaceMaskDetectionClass", "Video Stream", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FaceMaskDetectionClass: public Ui_FaceMaskDetectionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACEMASKDETECTION_H
