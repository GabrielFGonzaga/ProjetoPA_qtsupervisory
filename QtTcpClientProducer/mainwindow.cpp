#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    tcpConnect();

    connect(ui->pushButtonConnect,
            SIGNAL(clicked(bool)),
            this,
            SLOT(tcpConnect()));

    connect(ui->pushButtonDisconnect,
            SIGNAL(clicked(bool)),
            this,
            SLOT(tcpDisconnect()));

    connect(ui->pushButtonStart,
            SIGNAL(clicked(bool)),
            this,
            SLOT(controlDataStart()));

    connect(ui->pushButtonStop,
            SIGNAL(clicked(bool)),
            this,
            SLOT(controlDataStop()));
}

void MainWindow::tcpConnect(){
    QString ip = ui->lineEditIp->text();

    socket->connectToHost(ip,1234);
    if(socket->waitForConnected(3000)){
        qDebug() << "Connected";
    }
    else{
        qDebug() << "Disconnected";
    }
}

void MainWindow::tcpDisconnect()
{
    if(socket->state() != QAbstractSocket::ConnectedState){
        return;
    }
    socket->disconnectFromHost();
}

void MainWindow::putData(){
    QDateTime datetime;
    QString str;
    qint64 msecdate;


    int min = ui->horizontalSliderMin->value();
    int max = ui->horizontalSliderMax->value();
    int randon = min + std::rand() % (max - min +1);
    if(socket->state()== QAbstractSocket::ConnectedState){

        msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();
        str = "set "+ QString::number(msecdate) + " " +
              QString::number(randon)+"\r\n";

        qDebug() << str;
        qDebug() << socket->write(str.toStdString().c_str())
                 << " bytes written";
        if(socket->waitForBytesWritten(3000)){
            qDebug() << "wrote";
        }
    }
}

void MainWindow::controlDataStart(){
    temp = startTimer(ui->horizontalSlider->value()*1000);
}

void MainWindow::controlDataStop()
{
    killTimer(temp);
}

void MainWindow::timerEvent(QTimerEvent *timer)
{
    putData();
}

MainWindow::~MainWindow(){
    delete socket;
    delete ui;
}
