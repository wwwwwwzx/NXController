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
  ts.write(("click " + button + "\n").toUtf8());
}

void nscontroller_cfw::press(QString button) {
  ts.write(("press " + button + "\n").toUtf8());
}

void nscontroller_cfw::release(QString button) {
  ts.write(("release " + button + "\n").toUtf8());
}

void nscontroller_cfw::close() {
  ts.close();
}
