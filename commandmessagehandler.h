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
    QString handleCreateCommand(QStringList &list);
    QString handleConnectCommand(QStringList &list);
    QString handleExecuteCommand(QStringList &list);
    QString handleCreateLineCommand(QStringList &list);
    QString handleCreateRectangleCommand(QStringList &list);
    QString handleCreateSquareCommand(QStringList &list);
    QString handleCreateTriangleCommand(QStringList &list);
signals:
    void lineRequested(QString name, qreal x1, qreal y1, qreal x2, qreal y2);
    void rectangleRequested(QString name, qreal x1, qreal y1, qreal x2, qreal y2);
    void squareRequested();
    void triangleRequested();
    void connectRequested();
private:
    QString errMessage = "Invalid Command";
};

#endif // COMMANDMESSAGEHANDLER_H
