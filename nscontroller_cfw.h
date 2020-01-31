#ifndef NSCONTROLLER_CFW_H
#define NSCONTROLLER_CFW_H
#include <QTcpSocket>
#include <QString>

class nscontroller_cfw {
 public:
  nscontroller_cfw();
  bool connect(QString IP);
  void press(QString button);
  void click(QString button);
  void release(QString button);
  void LStick(short x, short y);
  void RStick(short x, short y);
  short LS_X = 0, LS_Y = 0, RS_X = 0, RS_Y = 0;
  void close();

 public slots:
  void onReadyRead();

 private:
  QTcpSocket ts;
  QByteArray buffer;
};

#endif  // NSCONTROLLER_CFW_H
