#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QListWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
public slots:
    void tcpConnect();
    void getData();
    void ipSelecionado(QListWidgetItem *item);
    void Disconnect();
    void setIP();
    void Update();
    void Start();
    void Stop();
    void timerEvent(QTimerEvent *timer);

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  unsigned int temp;
  QString selectIP;
  int timerId;
  std::vector<long long> timeData;
  std::vector<int> valueData;
};

#endif // MAINWINDOW_H
