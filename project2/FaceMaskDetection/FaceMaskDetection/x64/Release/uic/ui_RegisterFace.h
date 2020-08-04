/********************************************************************************
** Form generated from reading UI file 'RegisterFace.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERFACE_H
#define UI_REGISTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterFaceClass
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QPushButton *buttonStartRecord;
    QGroupBox *groupBoxName;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEditName;
    QSpacerItem *verticalSpacer;
    QPushButton *buttonClose;
    QLabel *labelVideoStreamRegister;

    void setupUi(QWidget *RegisterFaceClass)
    {
        if (RegisterFaceClass->objectName().isEmpty())
            RegisterFaceClass->setObjectName(QString::fromUtf8("RegisterFaceClass"));
        RegisterFaceClass->resize(800, 600);
        RegisterFaceClass->setStyleSheet(QString::fromUtf8("background:#020d2c"));
        gridLayout = new QGridLayout(RegisterFaceClass);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(RegisterFaceClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        buttonStartRecord = new QPushButton(widget);
        buttonStartRecord->setObjectName(QString::fromUtf8("buttonStartRecord"));
        buttonStartRecord->setStyleSheet(QString::fromUtf8("background:#162e6c;color:gray"));

        gridLayout_2->addWidget(buttonStartRecord, 2, 0, 1, 1);

        groupBoxName = new QGroupBox(widget);
        groupBoxName->setObjectName(QString::fromUtf8("groupBoxName"));
        groupBoxName->setStyleSheet(QString::fromUtf8("background:#162e6c;color:gray"));
        gridLayout_3 = new QGridLayout(groupBoxName);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        lineEditName = new QLineEdit(groupBoxName);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));

        gridLayout_3->addWidget(lineEditName, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBoxName, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 448, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);

        buttonClose = new QPushButton(widget);
        buttonClose->setObjectName(QString::fromUtf8("buttonClose"));
        buttonClose->setStyleSheet(QString::fromUtf8("background:#162e6c;color:gray"));

        gridLayout_2->addWidget(buttonClose, 3, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 1, 1, 1);

        labelVideoStreamRegister = new QLabel(RegisterFaceClass);
        labelVideoStreamRegister->setObjectName(QString::fromUtf8("labelVideoStreamRegister"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelVideoStreamRegister->sizePolicy().hasHeightForWidth());
        labelVideoStreamRegister->setSizePolicy(sizePolicy);
        labelVideoStreamRegister->setLayoutDirection(Qt::LeftToRight);
        labelVideoStreamRegister->setStyleSheet(QString::fromUtf8("background:black;color:gray"));
        labelVideoStreamRegister->setFrameShape(QFrame::WinPanel);
        labelVideoStreamRegister->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelVideoStreamRegister, 0, 0, 1, 1);

        gridLayout->setColumnStretch(0, 8);
        gridLayout->setColumnStretch(1, 2);

        retranslateUi(RegisterFaceClass);

        QMetaObject::connectSlotsByName(RegisterFaceClass);
    } // setupUi

    void retranslateUi(QWidget *RegisterFaceClass)
    {
        RegisterFaceClass->setWindowTitle(QApplication::translate("RegisterFaceClass", "\346\263\250\345\206\214\346\226\260\347\224\250\346\210\267", nullptr));
        buttonStartRecord->setText(QApplication::translate("RegisterFaceClass", "\345\274\200\345\247\213\345\275\225\345\205\245", nullptr));
        groupBoxName->setTitle(QApplication::translate("RegisterFaceClass", "\350\257\267\350\276\223\345\205\245\345\247\223\345\220\215", nullptr));
        buttonClose->setText(QApplication::translate("RegisterFaceClass", "\345\205\263\351\227\255", nullptr));
        labelVideoStreamRegister->setText(QApplication::translate("RegisterFaceClass", "Vider Stream", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterFaceClass: public Ui_RegisterFaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERFACE_H
