#include "nscontroller_cfw.h"
#include <QString>
#include <QTcpSocket>
#include <QHostAddress>

nscontroller_cfw::nscontroller_cfw() {}

bool nscontroller_cfw::connect(QString IP) {
  ts.connectToHost(QHostAddress(IP), 6000);
  return ts.open(QIODevice::ReadWrite);
}

void nscontroller_cfw::click(QString button) {
  ts.write(("click " + button + "\r\n").toUtf8());
  ts.waitForBytesWritten();
}

void nscontroller_cfw::press(QString button) {
  ts.write(("press " + button + "\r\n").toUtf8());
  ts.waitForBytesWritten();
}

void nscontroller_cfw::release(QString button) {
  ts.write(("release " + button + "\r\n").toUtf8());
  ts.waitForBytesWritten();
}

void nscontroller_cfw::LStick(short x, short y) {
  LS_X = x;
  LS_Y = y;
  QString xsign = x < 0 ? "-" : "";
  QString ysign = y < 0 ? "-" : "";
  QString output = "setStick LEFT " + xsign + "0x" + QString::number(abs(x), 16) + " " + ysign + "0x" + QString::number(abs(y), 16) + "\r\n";
  ts.write(output.toUtf8());
  ts.waitForBytesWritten();
}

void nscontroller_cfw::RStick(short x, short y) {
  RS_X = x;
  RS_Y = y;
  QString xsign = x < 0 ? "-" : "";
  QString ysign = y < 0 ? "-" : "";
  QString output = "setStick RIGHT " + xsign + "0x" + QString::number(abs(x), 16) + " " + ysign + "0x" + QString::number(abs(y), 16) + "\r\n";
  ts.write(output.toUtf8());
  ts.waitForBytesWritten();
}

void nscontroller_cfw::close() {
  ts.close();
}
