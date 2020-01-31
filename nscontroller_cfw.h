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
  void close();

 public slots:
  void onReadyRead();

 private:
  QTcpSocket ts;
  QByteArray buffer;
};

#endif  // NSCONTROLLER_CFW_H
