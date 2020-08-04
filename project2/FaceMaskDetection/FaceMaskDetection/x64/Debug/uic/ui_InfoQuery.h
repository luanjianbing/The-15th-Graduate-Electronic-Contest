/********************************************************************************
** Form generated from reading UI file 'InfoQuery.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOQUERY_H
#define UI_INFOQUERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoQueryClass
{
public:
    QGridLayout *gridLayout;
    QPushButton *buttonClose;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QWidget *tabRegisterInfo;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollAreaRg;
    QWidget *scrollAreaWidgetContentsRg;
    QGridLayout *gridLayoutRg;
    QWidget *tabRecordInfo;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollAreaRd;
    QWidget *scrollAreaWidgetContentsRd;
    QGridLayout *gridLayoutRd;

    void setupUi(QWidget *InfoQueryClass)
    {
        if (InfoQueryClass->objectName().isEmpty())
            InfoQueryClass->setObjectName(QString::fromUtf8("InfoQueryClass"));
        InfoQueryClass->resize(900, 600);
        InfoQueryClass->setStyleSheet(QString::fromUtf8("background:#020d2c"));
        gridLayout = new QGridLayout(InfoQueryClass);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonClose = new QPushButton(InfoQueryClass);
        buttonClose->setObjectName(QString::fromUtf8("buttonClose"));
        buttonClose->setStyleSheet(QString::fromUtf8("background:#162e6c;color:gray"));

        gridLayout->addWidget(buttonClose, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        tabWidget = new QTabWidget(InfoQueryClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8("background:#162e6c;color:gray"));
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setIconSize(QSize(32, 32));
        tabRegisterInfo = new QWidget();
        tabRegisterInfo->setObjectName(QString::fromUtf8("tabRegisterInfo"));
        gridLayout_2 = new QGridLayout(tabRegisterInfo);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        scrollAreaRg = new QScrollArea(tabRegisterInfo);
        scrollAreaRg->setObjectName(QString::fromUtf8("scrollAreaRg"));
        scrollAreaRg->setWidgetResizable(true);
        scrollAreaWidgetContentsRg = new QWidget();
        scrollAreaWidgetContentsRg->setObjectName(QString::fromUtf8("scrollAreaWidgetContentsRg"));
        scrollAreaWidgetContentsRg->setGeometry(QRect(0, 0, 814, 513));
        scrollAreaWidgetContentsRg->setMinimumSize(QSize(0, 200));
        gridLayoutRg = new QGridLayout(scrollAreaWidgetContentsRg);
        gridLayoutRg->setObjectName(QString::fromUtf8("gridLayoutRg"));
        scrollAreaRg->setWidget(scrollAreaWidgetContentsRg);

        gridLayout_2->addWidget(scrollAreaRg, 0, 0, 1, 1);

        QIcon icon;
        icon.addFile(QString::fromUtf8("icon/face.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tabRegisterInfo, icon, QString());
        tabRecordInfo = new QWidget();
        tabRecordInfo->setObjectName(QString::fromUtf8("tabRecordInfo"));
        gridLayout_3 = new QGridLayout(tabRecordInfo);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        scrollAreaRd = new QScrollArea(tabRecordInfo);
        scrollAreaRd->setObjectName(QString::fromUtf8("scrollAreaRd"));
        scrollAreaRd->setWidgetResizable(true);
        scrollAreaWidgetContentsRd = new QWidget();
        scrollAreaWidgetContentsRd->setObjectName(QString::fromUtf8("scrollAreaWidgetContentsRd"));
        scrollAreaWidgetContentsRd->setGeometry(QRect(0, 0, 814, 513));
        scrollAreaWidgetContentsRd->setMinimumSize(QSize(0, 200));
        gridLayoutRd = new QGridLayout(scrollAreaWidgetContentsRd);
        gridLayoutRd->setObjectName(QString::fromUtf8("gridLayoutRd"));
        scrollAreaRd->setWidget(scrollAreaWidgetContentsRd);

        gridLayout_3->addWidget(scrollAreaRd, 0, 0, 1, 1);

        QIcon icon1;
        icon1.addFile(QString::fromUtf8("icon/record.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tabRecordInfo, icon1, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 2);


        retranslateUi(InfoQueryClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(InfoQueryClass);
    } // setupUi

    void retranslateUi(QWidget *InfoQueryClass)
    {
        InfoQueryClass->setWindowTitle(QApplication::translate("InfoQueryClass", "\344\277\241\346\201\257\346\237\245\350\257\242", nullptr));
        buttonClose->setText(QApplication::translate("InfoQueryClass", "\345\205\263\351\227\255", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabRegisterInfo), QString());
        tabWidget->setTabText(tabWidget->indexOf(tabRecordInfo), QString());
    } // retranslateUi

};

namespace Ui {
    class InfoQueryClass: public Ui_InfoQueryClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOQUERY_H
