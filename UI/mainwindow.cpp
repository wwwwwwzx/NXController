#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "nscontroller.h"
#include <QSerialPortInfo>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  RefreshDeviceList();
  connect(ui->B_Refresh, SIGNAL(released()), this, SLOT(RefreshDeviceList()));
  connect(ui->B_Connect, SIGNAL(released()), this, SLOT(Connect()));
  connect(ui->B_Disconnect, SIGNAL(released()), this, SLOT(Disconnect()));
  ui->B_Disconnect->setEnabled(false);
  Connect();
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

void MainWindow::Connect() {
  if (ui->RB_Serial->isChecked()) {
    if (!c.connect(ui->devicelist->currentText()))
      return;
  } else {
    if (!b.connect(ui->ipaddress->toPlainText()))
      return;
  }
  ui->B_Connect->setEnabled(false);
  ui->B_Disconnect->setEnabled(true);
  ui->devicelist->setEnabled(false);
  ui->ipaddress->setEnabled(false);
  ui->RB_Serial->setEnabled(false);
  ui->RB_Socket->setEnabled(false);
}

void MainWindow::Disconnect() {
  if (ui->RB_Serial->isChecked())
    c.close();
  else
    b.close();
  ui->B_Connect->setEnabled(true);
  ui->B_Disconnect->setEnabled(false);
  ui->devicelist->setEnabled(true);
  ui->ipaddress->setEnabled(true);
  ui->RB_Serial->setEnabled(true);
  ui->RB_Socket->setEnabled(true);
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
  if (ui->B_Connect->isEnabled())
    return;
  Qt::Key key = (Qt::Key)event->key();
  if (ui->RB_Serial->isChecked()) {
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
  } else {
    if (key == keytable.A)
      b.press("A");
    else if (key == keytable.B)
      b.press("B");
    else if (key == keytable.X)
      b.press("X");
    else if (key == keytable.Y)
      b.press("Y");
    else if (key == keytable.D_Up)
      b.press("DUP");
    else if (key == keytable.D_Down)
      b.press("DDOWN");
    else if (key == keytable.D_Left)
      b.press("DLEFT");
    else if (key == keytable.D_Right)
      b.press("DRIGHT");
    else if (key == keytable.Home)
      b.press("HOME");
    else if (key == keytable.Capture)
      b.press("CAPTURE");
    else if (key == keytable.Plus)
      b.press("PLUS");
    else if (key == keytable.Minus)
      b.press("MINUS");
    else if (key == keytable.L)
      b.press("L");
    else if (key == keytable.R)
      b.press("R");
    else if (key == keytable.ZL)
      b.press("ZL");
    else if (key == keytable.ZR)
      b.press("ZR");
    else if (key == keytable.LS)
      b.press("LSTICK");
    else if (key == keytable.RS)
      b.press("RSTICK");
  }
}

void MainWindow::keyReleaseEvent(QKeyEvent* event) {
  if (ui->B_Connect->isEnabled())
    return;
  Qt::Key key = (Qt::Key)event->key();
  if (ui->RB_Serial->isChecked()) {
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
  } else {
    if (key == keytable.A)
      b.release("A");
    else if (key == keytable.B)
      b.release("B");
    else if (key == keytable.X)
      b.release("X");
    else if (key == keytable.Y)
      b.release("Y");
    else if (key == keytable.D_Up)
      b.release("DUP");
    else if (key == keytable.D_Down)
      b.release("DDOWN");
    else if (key == keytable.D_Left)
      b.release("DLEFT");
    else if (key == keytable.D_Right)
      b.release("DRIGHT");
    else if (key == keytable.Home)
      b.release("HOME");
    else if (key == keytable.Capture)
      b.release("CAPTURE");
    else if (key == keytable.Plus)
      b.release("PLUS");
    else if (key == keytable.Minus)
      b.release("MINUS");
    else if (key == keytable.L)
      b.release("L");
    else if (key == keytable.R)
      b.release("R");
    else if (key == keytable.ZL)
      b.release("ZL");
    else if (key == keytable.ZR)
      b.release("ZR");
    else if (key == keytable.LS)
      b.release("LSTICK");
    else if (key == keytable.RS)
      b.release("RSTICK");
  }
}
