/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "plotter.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *textIP;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *ButtonConnect;
    QPushButton *ButtonDisconnect;
    QLabel *WarningList;
    QListWidget *listIP;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *ButtonUpdate;
    QLabel *TimingLabel;
    QSplitter *splitter;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QSlider *TimeSlider;
    QLabel *TimingCounter;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *ButtonStart;
    QPushButton *ButtonStop;
    Plotter *graphic;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(593, 450);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout_6 = new QHBoxLayout(centralWidget);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        textIP = new QLineEdit(centralWidget);
        textIP->setObjectName("textIP");

        verticalLayout->addWidget(textIP);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        ButtonConnect = new QPushButton(centralWidget);
        ButtonConnect->setObjectName("ButtonConnect");

        horizontalLayout_3->addWidget(ButtonConnect);

        ButtonDisconnect = new QPushButton(centralWidget);
        ButtonDisconnect->setObjectName("ButtonDisconnect");

        horizontalLayout_3->addWidget(ButtonDisconnect);


        verticalLayout_2->addLayout(horizontalLayout_3);

        WarningList = new QLabel(centralWidget);
        WarningList->setObjectName("WarningList");

        verticalLayout_2->addWidget(WarningList);

        listIP = new QListWidget(centralWidget);
        listIP->setObjectName("listIP");

        verticalLayout_2->addWidget(listIP);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(128, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ButtonUpdate = new QPushButton(centralWidget);
        ButtonUpdate->setObjectName("ButtonUpdate");

        horizontalLayout->addWidget(ButtonUpdate);


        verticalLayout_3->addLayout(horizontalLayout);

        TimingLabel = new QLabel(centralWidget);
        TimingLabel->setObjectName("TimingLabel");

        verticalLayout_3->addWidget(TimingLabel);

        splitter = new QSplitter(centralWidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Orientation::Horizontal);
        widget = new QWidget(splitter);
        widget->setObjectName("widget");
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        TimeSlider = new QSlider(widget);
        TimeSlider->setObjectName("TimeSlider");
        TimeSlider->setMinimum(1);
        TimeSlider->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_4->addWidget(TimeSlider);

        TimingCounter = new QLabel(widget);
        TimingCounter->setObjectName("TimingCounter");

        horizontalLayout_4->addWidget(TimingCounter);

        splitter->addWidget(widget);

        verticalLayout_3->addWidget(splitter);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        ButtonStart = new QPushButton(centralWidget);
        ButtonStart->setObjectName("ButtonStart");

        horizontalLayout_2->addWidget(ButtonStart);

        ButtonStop = new QPushButton(centralWidget);
        ButtonStop->setObjectName("ButtonStop");

        horizontalLayout_2->addWidget(ButtonStop);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_5->addLayout(verticalLayout_3);

        graphic = new Plotter(centralWidget);
        graphic->setObjectName("graphic");

        horizontalLayout_5->addWidget(graphic);

        horizontalLayout_5->setStretch(0, 40);
        horizontalLayout_5->setStretch(1, 60);

        horizontalLayout_6->addLayout(horizontalLayout_5);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 593, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(TimeSlider, &QSlider::valueChanged, TimingCounter, qOverload<int>(&QLabel::setNum));
        QObject::connect(ButtonConnect, SIGNAL(clicked()), MainWindow, SLOT(tcpConnect()));
        QObject::connect(listIP, SIGNAL(activated(QModelIndex)), MainWindow, SLOT(setIP()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "IP do Servidor", nullptr));
        textIP->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        ButtonConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        ButtonDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        WarningList->setText(QString());
        ButtonUpdate->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        TimingLabel->setText(QCoreApplication::translate("MainWindow", "Timing", nullptr));
        TimingCounter->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        ButtonStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        ButtonStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
