#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
  void tcpConnect();
  void tcpDisconnect();
public slots:
  void putData();
  void controlDataStart();
  void controlDataStop();
  void timerEvent(QTimerEvent *timer);
private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  unsigned int temp;
};

#endif // MAINWINDOW_H
