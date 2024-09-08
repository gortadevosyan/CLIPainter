#include "commandmessagehandler.h"
#include <QString>
#include <QtCore>
#include "canvas.h"
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
        commandList.removeFirst();
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

//utility methods

std::unique_ptr<QPointF> handlePointCreation(QStringList &list, int coordNo){
    auto ans = std::make_unique<QPointF>();
    qreal coordx, coordy;
    QString expectedArg = "-coord_" + QString::number(coordNo);
    if(list.first() == expectedArg){
        list.removeFirst();
        QString coordTuple = list.first();
        //remove the values of the point coordinates from the list
        coordTuple.removeFirst();
        coordTuple.removeLast();
        QStringList crds = coordTuple.split(',');
        coordx = crds.first().toDouble();
        coordy  = crds.last().toDouble();
        *ans = QPointF(coordx, coordy);
        list.removeFirst();
    }
    return ans;
}

//with the flag isSquare = true the function checks whether the points form a square or not
bool isValidRectangle(std::unique_ptr<QPointF> &coord1, std::unique_ptr<QPointF> &coord2, std::unique_ptr<QPointF> &coord3, std::unique_ptr<QPointF>  &coord4, bool isSquare = false){
    QPointF side1 = QPointF(coord1->x()-coord2->x(), coord1->y()-coord2->y());
    QPointF side2 = QPointF(coord2->x()-coord3->x(), coord2->y()-coord3->y());
    QPointF side3 = QPointF(coord3->x()-coord4->x(), coord3->y()-coord4->y());
    QPointF side4 = QPointF(coord4->x()-coord1->x(), coord4->y()-coord1->y());
    //all angles should be right
    if(0 != QPointF::dotProduct(side1, side2) || 0 != QPointF::dotProduct(side2, side3) || 0 != QPointF::dotProduct(side3, side4) || 0 != QPointF::dotProduct(side4, side1))
        return false;
    //the sides of a square should be equal
    if(isSquare)
        return QPointF::dotProduct(side1, side1) == QPointF::dotProduct(side2,side2);
    return true;
}

QString CommandMessageHandler::handleCreateLineCommand(QStringList &list, QString name){
    if(name.isNull())
        return "Invalid formatting, name parameter expected";

    if(Canvas::isNameUsed(name))
        return "An object with the same name exists";

    auto coord1 = handlePointCreation(list, 1);
    if(coord1 == nullptr)
        return "Invalid formatting, -coord_1 parameter expected";

    auto coord2 = handlePointCreation(list, 2);
    if(coord2 == nullptr)
        return "Invalid formatting, -coord_2 parameter expected";

    emit(lineRequested(name, coord1->x(), coord1->y(), coord2->x(), coord2->y()));

    return "Success, line will be created";
}

QString CommandMessageHandler::handleCreateRectangleCommand(QStringList &list, QString name){
    if(name.isNull())
        return "Invalid formatting, name parameter expected";

    if(Canvas::isNameUsed(name))
        return "An object with the same name exists";

    //extract the coordinates of point1
    auto coord1 = handlePointCreation(list, 1);
    if(coord1 == nullptr)
        return "Invalid formatting, -coord_1 parameter expected";

    //extract the coordinates of point2
    auto coord2 = handlePointCreation(list, 2);
    if(coord2== nullptr)
        return "Invalid formatting, -coord_2 parameter expected";

    //check which constructor was used, 2 or 4 point one
    if(list.isEmpty()){
        emit(rectangleRequested(name, coord1->x(), coord1->y(), coord2->x(), coord2->y()));
        return "Success, rectangle will be created";
    }

    //extract the coordinates of point3
    auto coord3 = handlePointCreation(list, 3);
    if(coord3== nullptr)
        return "Invalid formatting, -coord_3 parameter expected";

    //extract the coordinates of point4
    auto coord4 = handlePointCreation(list, 4);
    if(coord3== nullptr)
        return "Invalid formatting, -coord_4 parameter expected";

    //checks the correctness of the given points
    if(!isValidRectangle(coord1, coord2, coord3, coord4))
        return "Invalid command, given points do not form a rectangle";

    emit(rectangleRequested_4(name, coord1->x(), coord1->y(), coord2->x(),coord2->y(), coord3->x(), coord3->y(), coord4->x(), coord4->y()));
    return "Success, rectangle will be created";
}


QString CommandMessageHandler::handleCreateSquareCommand(QStringList &list, QString name){
    if(name.isNull())
        return "Invalid formatting, name parameter expected";

    if(Canvas::isNameUsed(name))
        return "An object with the same name exists";

    //extract the coordinates of point1
    auto coord1 = handlePointCreation(list, 1);
    if(coord1 == nullptr)
        return "Invalid formatting, -coord_1 parameter expected";

    //extract the coordinates of point2
    auto coord2 = handlePointCreation(list, 2);
    if(coord2== nullptr)
        return "Invalid formatting, -coord_2 parameter expected";

    //check which constructor was used, 2 or 4 point one
    if(list.isEmpty()){
        emit(squareRequested(name, coord1->x(), coord1->y(), coord2->x(), coord2->y()));
        return "Success, square will be created";
    }

    //extract the coordinates of point3
    auto coord3 = handlePointCreation(list, 3);
    if(coord3== nullptr)
        return "Invalid formatting, -coord_3 parameter expected";

    //extract the coordinates of point4
    auto coord4 = handlePointCreation(list, 4);
    if(coord3== nullptr)
        return "Invalid formatting, -coord_4 parameter expected";

    //checks the correctness of the given points
    if(!isValidRectangle(coord1, coord2, coord3, coord4, true))
        return "Invalid command, given points do not form a rectangle";

    emit(squareRequested_4(name, coord1->x(), coord1->y(), coord2->x(),coord2->y(), coord3->x(), coord3->y(), coord4->x(), coord4->y()));
    return "Success, rectangle will be created";
}

QString CommandMessageHandler::handleCreateTriangleCommand(QStringList &list, QString name){
    if(name.isNull())
        return "Invalid formatting, name parameter expected";

    if(Canvas::isNameUsed(name))
        return "An object with the same name exists";

    auto coord1 = handlePointCreation(list, 1);
    if(coord1== nullptr)
        return "Invalid formatting, -cord_1 parameter expected";

    auto coord2 = handlePointCreation(list, 2);
    if(coord2== nullptr)
        return "Invalid formatting, -cord_2 parameter expected";

    auto coord3 = handlePointCreation(list, 3);
    if(coord2== nullptr)
        return "Invalid formatting, -cord_3 parameter expected";

    emit(triangleRequested(name, coord1->x(), coord1->y(), coord2->x(), coord2->y(), coord3->x(), coord3->y()));

    return "Success, triangle will be created";
}

QString CommandMessageHandler::handleConnectCommand(QStringList &list){
    //TODO
    return NULL;
}
QString  CommandMessageHandler::handleExecuteCommand(QStringList &list){
    //TODO
    return NULL;
}
