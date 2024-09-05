#ifndef COMMANDMESSAGEHANDLER_H
#define COMMANDMESSAGEHANDLER_H
#include <QString>
#include <QObject>
class CommandMessageHandler : public QObject
{
    Q_OBJECT
public:
    CommandMessageHandler(QObject *parent = nullptr) : QObject(parent){}
    static QString handleCommand(QString command);
    static QString handleCreateCommand(QStringList list);
    static QString handleConnectCommand(QStringList list);
    static QString handleExecuteCommand(QStringList list);
signals:
    void lineRequested();
    void rectangleRequested();
    void squareRequested();
    void triangleRequested();
    void connectRequested();

};

#endif // COMMANDMESSAGEHANDLER_H
