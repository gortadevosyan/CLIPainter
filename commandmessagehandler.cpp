#include "commandmessagehandler.h"
#include <QString>
#include <QtCore>
QString CommandMessageHandler::handleCommand(QString command){
    QStringList list = command.split("-");
    if(list.first()=="create")
        return handleCreateCommand(list);
    //TODO
    return NULL;
}

QString CommandMessageHandler::handleCreateCommand(QStringList list){
    //TODO
    return NULL;
}

QString handleConnectCommand(QStringList list){
    //TODO
    return NULL;
}
QString handleExecuteCommand(QStringList list){
    //TODO
    return NULL;
}
