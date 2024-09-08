#ifndef COMMANDMESSAGEHANDLER_H
#define COMMANDMESSAGEHANDLER_H
#include <QString>
#include <QObject>
class CommandMessageHandler : public QObject
{
    Q_OBJECT
public:
    CommandMessageHandler(QObject *parent = nullptr) : QObject(parent){}
    QString handleCommand(QString command);
private:
    QString handleCreateCommand(QStringList &list);
    QString handleConnectCommand(QStringList &list);
    QString handleExecuteCommand(QStringList &list);
    QString handleCreateLineCommand(QStringList &list, QString name);
    QString handleCreateRectangleCommand(QStringList &list, QString name);
    QString handleCreateSquareCommand(QStringList &list, QString name);
    QString handleCreateTriangleCommand(QStringList &list, QString name);
public:

signals:
    void lineRequested(QString name, qreal x1, qreal y1, qreal x2, qreal y2);
    void rectangleRequested(QString name, qreal x1, qreal y1, qreal x2, qreal y2);
    void rectangleRequested_4(QString name, qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3, qreal x4, qreal y4);
    void squareRequested_4(QString name, qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3, qreal x4, qreal y4);
    void squareRequested(QString name, qreal x1, qreal y1, qreal x2, qreal y2);
    void triangleRequested(QString name, qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3);
    void connectRequested();
};

#endif // COMMANDMESSAGEHANDLER_H
