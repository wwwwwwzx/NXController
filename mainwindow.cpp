#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "nscontroller.h"
#include <QSerialPortInfo>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  RefreshDeviceList();
  connect(ui->B_Refresh, SIGNAL(released()), this, SLOT(RefreshDeviceList()));
  connect(ui->B_Connect, SIGNAL(released()), this, SLOT(ConnectSerial()));
  connect(ui->B_Disconnect, SIGNAL(released()), this, SLOT(DisconnectSerial()));
  ui->B_Disconnect->setEnabled(false);
  ConnectSerial();
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::RefreshDeviceList() {
  ui->devicelist->clear();
  Q_FOREACH (QSerialPortInfo port, QSerialPortInfo::availablePorts())
    if (port.hasProductIdentifier())
      ui->devicelist->addItem((port.portName()));
}

void MainWindow::ConnectSerial() {
  if (c.connect(ui->devicelist->currentText())) {
    ui->B_Connect->setEnabled(false);
    ui->B_Disconnect->setEnabled(true);
    ui->devicelist->setEnabled(false);
  }
}

void MainWindow::DisconnectSerial() {
  c.close();
  ui->B_Connect->setEnabled(true);
  ui->B_Disconnect->setEnabled(false);
  ui->devicelist->setEnabled(true);
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
  if (ui->B_Connect->isEnabled())
    return;
  Qt::Key key = (Qt::Key)event->key();
  if (key == keytable.A)
    c.A(-1);
  else if (key == keytable.B)
    c.B(-1);
  else if (key == keytable.X)
    c.X(-1);
  else if (key == keytable.Y)
    c.Y(-1);
  else if (key == keytable.LS_Up)
    c.LS_Up(-1);
  else if (key == keytable.LS_Down)
    c.LS_Down(-1);
  else if (key == keytable.LS_Left)
    c.LS_Left(-1);
  else if (key == keytable.LS_Right)
    c.LS_Right(-1);
  else if (key == keytable.RS_Up)
    c.RS_Up(-1);
  else if (key == keytable.RS_Down)
    c.RS_Down(-1);
  else if (key == keytable.RS_Left)
    c.RS_Left(-1);
  else if (key == keytable.RS_Right)
    c.RS_Right(-1);
  else if (key == keytable.D_Up)
    c.Up(-1);
  else if (key == keytable.D_Down)
    c.Down(-1);
  else if (key == keytable.D_Left)
    c.Left(-1);
  else if (key == keytable.D_Right)
    c.Right(-1);
  else if (key == keytable.Home)
    c.Home();
  else if (key == keytable.Capture)
    c.Capture(-1);
  else if (key == keytable.Plus)
    c.Plus(-1);
  else if (key == keytable.Minus)
    c.Minus(-1);
  else if (key == keytable.L)
    c.L(-1);
  else if (key == keytable.R)
    c.R(-1);
  else if (key == keytable.ZL)
    c.ZL(-1);
  else if (key == keytable.ZR)
    c.ZR(-1);
  else if (key == keytable.LS)
    c.PressLeftStick(-1);
  else if (key == keytable.RS)
    c.PressRightStick(-1);
}

void MainWindow::keyReleaseEvent(QKeyEvent* event) {
  if (ui->B_Connect->isEnabled())
    return;
  Qt::Key key = (Qt::Key)event->key();
  if (key == keytable.A)
    c.A(-1);
  else if (key == keytable.B)
    c.B(-1);
  else if (key == keytable.X)
    c.X(-1);
  else if (key == keytable.Y)
    c.Y(-1);
  else if (key == keytable.LS_Left || key == keytable.LS_Right)
    c.LS_XCenter();
  else if (key == keytable.LS_Up || key == keytable.LS_Down)
    c.LS_YCenter();
  else if (key == keytable.RS_Left || key == keytable.RS_Right)
    c.RS_XCenter();
  else if (key == keytable.RS_Up || key == keytable.RS_Down)
    c.RS_YCenter();
  else if (key == keytable.D_Up || keytable.D_Down || keytable.D_Left || keytable.D_Right)
    c.Dpad_Center();
  else if (key == keytable.Capture)
    c.Capture(-1);
  else if (key == keytable.Plus)
    c.Plus(-1);
  else if (key == keytable.Minus)
    c.Minus(-1);
  else if (key == keytable.L)
    c.L(-1);
  else if (key == keytable.R)
    c.R(-1);
  else if (key == keytable.ZL)
    c.ZL(-1);
  else if (key == keytable.ZR)
    c.ZR(-1);
  else if (key == keytable.LS)
    c.PressLeftStick(-1);
  else if (key == keytable.RS)
    c.PressRightStick(-1);
}
