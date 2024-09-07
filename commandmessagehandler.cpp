#include "commandmessagehandler.h"
#include <QString>
#include <QtCore>
QString CommandMessageHandler::handleCommand(QString command){
    QStringList commandList = command.split(" ");
    QStringList firstCommand = commandList.first().split("_");
    if(firstCommand.first()=="create")
        return handleCreateCommand(commandList);
    else if(firstCommand.first()=="connect")
        return handleConnectCommand(commandList);
    else if(firstCommand.first()=="execute")
        return handleExecuteCommand(commandList);
    else return "Invalid Command";
}

QString CommandMessageHandler::handleCreateCommand(QStringList &commandList){
    QString firstCommand = commandList.first();

    commandList.removeFirst();//remove the first command from the list to access name parameter

    QString name = NULL; //set the default value to name, if it is not updated, later an error message will be printed

    //parse name paramter
    if(commandList.first()=="-name"){
        commandList.removeFirst();
        name = commandList.first();
        //removes obsolete braces from the name
        if(name.endsWith('}') && name.startsWith('{')){
            name.removeFirst();
            name.removeLast();
        }
    }

    if(firstCommand == "create_line")
        return handleCreateLineCommand(commandList, name);
    else if(firstCommand == "create_rectangle")
        return handleCreateRectangleCommand(commandList, name);
    else if(firstCommand == "create_square")
        return handleCreateSquareCommand(commandList, name);
    else if(firstCommand == "create_triangle")
        return handleCreateTriangleCommand(commandList, name);
    else return "Invalid create command";
}

//utility method
QPointF handlePointCreation(QStringList &list, int coordNo){
    QPointF ans;
    qreal coordx, coordy;
    QString expectedArg = "-coord_" + QString::number(coordNo);
    list.removeFirst();
    if(list.first() == expectedArg){
        list.removeFirst();
        QString coordTuple = list.first();
        coordTuple.removeFirst();
        coordTuple.removeLast();
        QStringList crds = coordTuple.split(',');
        coordx = crds.first().toDouble();
        coordy  = crds.last().toDouble();
        ans = QPointF(coordx, coordy);
    }
    return ans;
}


QString CommandMessageHandler::handleCreateLineCommand(QStringList &list, QString name){
    if(name.isNull())
        return "Invalid formatting, name parameter expected";

    QPointF coord1 = handlePointCreation(list, 1);
    if(coord1.isNull())
        return "Invalid formatting, -cord_1 parameter expected";

    QPointF coord2 = handlePointCreation(list, 2);
    if(coord2.isNull())
        return "Invalid formatting, -cord_2 parameter expected";

    emit(lineRequested(name, coord1.x(), coord1.y(), coord2.x(), coord2.y()));

    return "Success, line will be created";
}


QString CommandMessageHandler::handleCreateRectangleCommand(QStringList &list, QString name){
    if(name.isNull())
        return "Invalid formatting, name parameter expected";

    QPointF coord1 = handlePointCreation(list, 1);
    if(coord1.isNull())
        return "Invalid formatting, -cord_1 parameter expected";

    QPointF coord2 = handlePointCreation(list, 2);
    if(coord2.isNull())
        return "Invalid formatting, -cord_2 parameter expected";

    emit(rectangleRequested(name, coord1.x(), coord1.y(), coord2.x(), coord2.y()));

    return "Success, rectangle will be created";
}


QString CommandMessageHandler::handleCreateSquareCommand(QStringList &list, QString name){
    return NULL;
}
QString CommandMessageHandler::handleCreateTriangleCommand(QStringList &list, QString name){
    if(name.isNull())
        return "Invalid formatting, name parameter expected";

    QPointF coord1 = handlePointCreation(list, 1);
    if(coord1.isNull())
        return "Invalid formatting, -cord_1 parameter expected";

    QPointF coord2 = handlePointCreation(list, 2);
    if(coord2.isNull())
        return "Invalid formatting, -cord_2 parameter expected";

    QPointF coord3 = handlePointCreation(list, 3);
    if(coord2.isNull())
        return "Invalid formatting, -cord_2 parameter expected";

    emit(triangleRequested(name, coord1.x(), coord1.y(), coord2.x(), coord2.y(), coord3.x(), coord3.y()));

    return "Success, rectangle will be created";
}

QString CommandMessageHandler::handleConnectCommand(QStringList &list){
    //TODO
    return NULL;
}
QString  CommandMessageHandler::handleExecuteCommand(QStringList &list){
    //TODO
    return NULL;
}
