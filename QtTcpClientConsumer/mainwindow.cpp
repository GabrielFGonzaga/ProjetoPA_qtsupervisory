#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <vector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);

    connect(ui->ButtonConnect,
            SIGNAL(clicked(bool)),
            this,
            SLOT(tcpConnect()));
    connect(ui->listIP, &QListWidget::itemClicked,
            this, &MainWindow::ipSelecionado);

    connect(ui->ButtonDisconnect,
            SIGNAL(clicked(bool)),
            this,
            SLOT(Disconnect()));
    connect(ui->ButtonUpdate,
            SIGNAL(clicked(bool)),
            this,
            SLOT(Update()));
    connect(ui->ButtonStart,
            SIGNAL(clicked(bool)),
            this,
            SLOT(Start()));
    connect(ui->ButtonStop,
            SIGNAL(clicked(bool)),
            this,
            SLOT(Stop()));
}

void MainWindow::tcpConnect() {
    QString ip = ui->textIP->text();

    socket->connectToHost(ip,1234);
    if(socket->waitForConnected(3000)){
        ui->WarningList->setText("Conectado");
    }
    else{
        ui->WarningList->setText("Erro ao conectar");
    }
}

void MainWindow::getData() {
    QString str, get_command;
    QByteArray aux;
    QStringList list;

    if (socket->state() != QAbstractSocket::ConnectedState)
    {
        return;
    }

    get_command = "get " + ui->textIP->text() + " 4\r\n";
    aux = get_command.toLatin1();

    socket->write(aux);
    socket->waitForBytesWritten();
    socket->waitForReadyRead();

    while (socket->bytesAvailable())
    {
        str = socket->readLine().replace("\n","").replace("\r","");
        list = str.split(" ");

        if (list.size() == 2)
        {
            long t = list.at(0).toLongLong();
            int v = list.at(1).toInt();

            qDebug() << "pontoem t=" << t << " v=" << v;

            if (!timeData.empty() && t <= timeData.back()) {
                continue;
            }

            timeData.push_back(t);
            valueData.push_back(v);
        }
    }

    const size_t MAX_POINTS = 10;
    if (timeData.size() > MAX_POINTS) {
        timeData.erase(timeData.begin(), timeData.end() - MAX_POINTS);
        valueData.erase(valueData.begin(), valueData.end() - MAX_POINTS);
    }

    qDebug() << "setData com" << timeData.size() << "pontos";
    ui->graphic->setData(timeData, valueData);
}

void MainWindow::ipSelecionado(QListWidgetItem *item)
{
    if (item) {
        ui->textIP->setText(item->text());
    }
}

void MainWindow::Disconnect()
{
    if(socket->state() != QAbstractSocket::ConnectedState){
        return;
    }
    ui->WarningList->setText("Desconectado");
    socket->disconnectFromHost();
}

void MainWindow::timerEvent(QTimerEvent *timer)
{
    getData();
}

void MainWindow::Update()
{
    QString str;

    if(socket->state() != QAbstractSocket::ConnectedState)
    {
        return;
    }

    ui->listIP->clear();

    socket->write("list\r\n");
    socket->waitForBytesWritten();
    socket->waitForReadyRead();

    while(socket->bytesAvailable())
    {
        str = socket->readLine().replace("\n","").replace("\r","");
        ui->listIP->addItem(str);

    }
}

void MainWindow::setIP()
{
    if(socket->state() != QAbstractSocket::ConnectedState)
    {
        return;
    }

    this->selectIP = ui->textIP->selectedText();
}

void MainWindow::Start()
{
    this->temp = startTimer(ui->TimeSlider->value() * 1000);
}

void MainWindow::Stop()
{
    killTimer(this->temp);
}

MainWindow::~MainWindow()
{
    delete socket;
    delete ui;
}
