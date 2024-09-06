#include "commandmessagehandler.h"
#include <QString>
#include <QtCore>
QString CommandMessageHandler::handleCommand(QString command){
    QStringList list = command.split(" ");
    QStringList firstCommand = list.first().split("_");
    if(firstCommand.first()=="create")
        return handleCreateCommand(list);
    else if(firstCommand.first()=="connect")
        return handleConnectCommand(list);
    else if(firstCommand.first()=="execute")
        return handleExecuteCommand(list);
    else return "Invalid Command";
}

QString CommandMessageHandler::handleCreateCommand(QStringList &list){
    if(list.first() == "create_line")
        return handleCreateLineCommand(list);
    else if(list.first() == "create_rectangle")
        return handleCreateRectangleCommand(list);
    else if(list.first() == "create_square")
        return handleCreateSquareCommand(list);
    else if(list.first() == "create_triangle")
        return handleCreateTriangleCommand(list);
    else return "Invalid Command";
}

QString CommandMessageHandler::handleCreateLineCommand(QStringList &list){
    list.removeFirst();
    QString name;
    qreal coord1x, coord1y, coord2x, coord2y;
    if(list.first()=="-name"){
        list.removeFirst();
        name = list.first();
        if(name.endsWith('}') && name.startsWith('{')){
            name.removeFirst();
            name.removeLast();
        }
        else return "Invalid formatting for parameter -name";
    }
    else return "Invalid formatting, -name parameter expected";
    list.removeFirst();
    if(list.first() == "-coord_1"){
        list.removeFirst();
        QString coord = list.first();
        coord.removeFirst();
        coord.removeLast();
        QStringList crds = coord.split(',');
        coord1x = crds.first().toDouble();
        coord1y  = crds.last().toDouble();
    }
    else return "Invalid formatting, -cord_1 parameter expected";
    list.removeFirst();
    if(list.first() == "-coord_2"){
        list.removeFirst();
        QString coord = list.first();
        coord.removeFirst();
        coord.removeLast();
        QStringList crds = coord.split(',');
        coord2x = crds.first().toDouble();
        coord2y  = crds.last().toDouble();
    }
    else return "Invalid formatting, -cord_1 parameter expected";
    emit(lineRequested(name, coord1x, coord1y, coord2x, coord2y));
    return "Success, line will be created";
}
QString CommandMessageHandler::handleCreateRectangleCommand(QStringList &list){
    list.removeFirst();
    QString name;
    qreal coord1x, coord1y, coord2x, coord2y, coord3x, coord3y, coord4x, coord4y;
    if(list.first()=="-name"){
        list.removeFirst();
        name = list.first();
        if(name.endsWith('}') && name.startsWith('{')){
            name.removeFirst();
            name.removeLast();
        }
        else return "Invalid formatting for parameter -name";
    }
    else return "Invalid formatting, -name parameter expected";
    list.removeFirst();
    if(list.first() == "-coord_1"){
        list.removeFirst();
        QString coord = list.first();
        coord.removeFirst();
        coord.removeLast();
        QStringList crds = coord.split(',');
        coord1x = crds.first().toDouble();
        coord1y  = crds.last().toDouble();
    }
    else return "Invalid formatting, -cord_1 parameter expected";
    list.removeFirst();
    if(list.first() == "-coord_2"){
        list.removeFirst();
        QString coord = list.first();
        coord.removeFirst();
        coord.removeLast();
        QStringList crds = coord.split(',');
        coord2x = crds.first().toDouble();
        coord2y  = crds.last().toDouble();
    }
    else return "Invalid formatting, -cord_1 parameter expected";
    emit(rectangleRequested(name, coord1x, coord1y, coord2x, coord2y));
    return "Success, rectangle will be created";
}
QString CommandMessageHandler::handleCreateSquareCommand(QStringList &list){
    return NULL;
}
QString CommandMessageHandler::handleCreateTriangleCommand(QStringList &list){
    return NULL;
}

QString CommandMessageHandler::handleConnectCommand(QStringList &list){
    //TODO
    return NULL;
}
QString  CommandMessageHandler::handleExecuteCommand(QStringList &list){
    //TODO
    return NULL;
}
