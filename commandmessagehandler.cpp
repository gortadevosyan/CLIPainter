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
    else return invalidCommandMessage;
}

QString CommandMessageHandler::handleCreateCommand(QStringList &commandList){
    QString firstCommand = commandList.first();

    commandList.removeFirst();//remove the first command from the list to access name parameter

    QString name = NULL; //set the default value to name, if it is not updated, later an error message will be printed

    //parse name paramter
    if(commandList.size()>=2 && commandList.first()=="-name"){
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
    else return invalidCommandMessage;
}

//utility methods

std::unique_ptr<QPointF> handlePointCreation(QStringList &list, int coordNo){
    auto ans = std::make_unique<QPointF>();
    qreal coordx, coordy;
    QString expectedArg = "-coord_" + QString::number(coordNo);
    if(list.size() >= 2 && list.first() == expectedArg){
        list.removeFirst();
        QString coordTuple = list.first();
        //remove the values of the point coordinates from the list
        coordTuple.removeFirst();
        coordTuple.removeLast();
        QStringList crds = coordTuple.split(',');
        if(crds.size() != 2) //invalid formatting
            return nullptr;

        bool xOk, yOk;
        coordx = crds.first().toDouble(&xOk);
        coordy  = crds.last().toDouble(&yOk);
        if(!xOk || !yOk)
            return nullptr;

        *ans = QPointF(coordx, coordy);
        list.removeFirst();
        return ans;
    }
    return nullptr;
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

bool isValidTriangle(std::unique_ptr<QPointF> &coord1, std::unique_ptr<QPointF> &coord2, std::unique_ptr<QPointF> &coord3){
    QPointF side1 = QPointF(coord1->x() - coord2->x(), coord1->y() - coord2->y());
    QPointF side2 = QPointF(coord2->x() - coord3->x(), coord2->y() - coord3->y());
    QPointF side3 = QPointF(coord3->x() - coord1->x(), coord3->y() - coord1->y());
    qreal arr[3] = {sqrt(QPointF::dotProduct(side1,side1)), sqrt(QPointF::dotProduct(side2,side2)), sqrt(QPointF::dotProduct(side3,side3))};
    std::sort(arr, arr+3);
    if(arr[0] + arr[1] <= arr[2])
        return false;
    return true;
}

QString CommandMessageHandler::handleCreateLineCommand(QStringList &list, QString name){
    if(name.isNull())
        return invalidFormattingMessage + " name " + parameterExpectedMessage;

    if(Canvas::isNameUsed(name))
        return duplicateNameMessage;

    auto coord1 = handlePointCreation(list, 1);
    if(coord1 == nullptr)
        return invalidFormattingMessage + " -coord_1 " + parameterExpectedMessage;

    auto coord2 = handlePointCreation(list, 2);
    if(coord2 == nullptr)
        return invalidFormattingMessage +  " -coord_2 " + parameterExpectedMessage;

    if(list.isEmpty())
        emit(lineRequested(name, coord1->x(), coord1->y(), coord2->x(), coord2->y()));
    else return invalidCommandMessage;
    return "Success: line will be created";
}

QString CommandMessageHandler::handleCreateRectangleCommand(QStringList &list, QString name){
    if(name.isNull())
        return invalidFormattingMessage +  " name " + parameterExpectedMessage;

    if(Canvas::isNameUsed(name))
        return duplicateNameMessage;

    //extract the coordinates of point1
    auto coord1 = handlePointCreation(list, 1);
    if(coord1 == nullptr)
        return invalidFormattingMessage + " -coord_1 " + parameterExpectedMessage;

    //extract the coordinates of point2
    auto coord2 = handlePointCreation(list, 2);
    if(coord2== nullptr)
        return invalidFormattingMessage + " -coord_2 " + parameterExpectedMessage;

    //check which constructor was used, 2 or 4 point one
    if(list.isEmpty()){
        if(coord1->x() == coord2->x() || coord1->y() == coord2->y())
            return "Failed: there is no rectangle with diagonal (coord_1, coord_2) and parallel to (x,y) axis";

        emit(rectangleRequested(name, coord1->x(), coord1->y(), coord2->x(), coord2->y()));
        return "Success: rectangle will be created";
    }

    //extract the coordinates of point3
    auto coord3 = handlePointCreation(list, 3);
    if(coord3== nullptr)
        return invalidFormattingMessage + " -coord_3 " + parameterExpectedMessage;

    //extract the coordinates of point4
    auto coord4 = handlePointCreation(list, 4);
    if(coord4== nullptr)
        return invalidFormattingMessage + " -coord_4 " + parameterExpectedMessage;

    //checks the correctness of the given points
    if(!isValidRectangle(coord1, coord2, coord3, coord4) || !list.isEmpty())
        return invalidCommandMessage + " given points do not form a rectangle";

    emit(rectangleRequested_4(name, coord1->x(), coord1->y(), coord2->x(),coord2->y(), coord3->x(), coord3->y(), coord4->x(), coord4->y()));
    return "Success: rectangle will be created";
}


QString CommandMessageHandler::handleCreateSquareCommand(QStringList &list, QString name){
    if(name.isNull())
        return invalidFormattingMessage + " name " + parameterExpectedMessage;

    if(Canvas::isNameUsed(name))
        return duplicateNameMessage;

    //extract the coordinates of point1
    auto coord1 = handlePointCreation(list, 1);
    if(coord1 == nullptr)
        return invalidFormattingMessage + " -coord_1 " + parameterExpectedMessage;

    //extract the coordinates of point2
    auto coord2 = handlePointCreation(list, 2);
    if(coord2 == nullptr)
        return invalidFormattingMessage + " -coord_2 " + parameterExpectedMessage;

    //check which constructor was used, 2 or 4 point one
    if(list.isEmpty()){
        emit(squareRequested(name, coord1->x(), coord1->y(), coord2->x(), coord2->y()));
        return "Success: square will be created";
    }

    //extract the coordinates of point3
    auto coord3 = handlePointCreation(list, 3);
    if(coord3 == nullptr)
        return invalidFormattingMessage + " -coord_3 " + parameterExpectedMessage;

    //extract the coordinates of point4
    auto coord4 = handlePointCreation(list, 4);
    if(coord4 == nullptr)
        return invalidFormattingMessage + " -coord_4 " + parameterExpectedMessage;

    //checks the correctness of the given points
    if(!isValidRectangle(coord1, coord2, coord3, coord4, true) || !list.isEmpty())
        return invalidCommandMessage + ", given points do not form a rectangle";

    emit(squareRequested_4(name, coord1->x(), coord1->y(), coord2->x(),coord2->y(), coord3->x(), coord3->y(), coord4->x(), coord4->y()));
    return "Success: rectangle will be created";
}

QString CommandMessageHandler::handleCreateTriangleCommand(QStringList &list, QString name){
    if(name.isNull())
        return invalidFormattingMessage + " name " + parameterExpectedMessage;

    if(Canvas::isNameUsed(name))
        return duplicateNameMessage;

    auto coord1 = handlePointCreation(list, 1);
    if(coord1== nullptr)
        return invalidFormattingMessage + " -coord_1 " + parameterExpectedMessage;

    auto coord2 = handlePointCreation(list, 2);
    if(coord2 == nullptr)
        return invalidFormattingMessage + " -coord_2 " + parameterExpectedMessage;

    auto coord3 = handlePointCreation(list, 3);
    if(coord3 == nullptr)
        return invalidFormattingMessage + " -coord_3 " + parameterExpectedMessage;

    if(!list.isEmpty())
        return invalidCommandMessage;

    if(!isValidTriangle(coord1, coord2, coord3))
        return "Failed: all the points are on the same line";

    emit(triangleRequested(name, coord1->x(), coord1->y(), coord2->x(), coord2->y(), coord3->x(), coord3->y()));

    return "Success: triangle will be created";
}

QString CommandMessageHandler::handleConnectCommand(QStringList &commandList){
    commandList.removeFirst();//remove the first command from the list to access name parameter

    QString name1 = NULL; //set the default value to name, if it is not updated, later an error message will be printed
    QString name2 = NULL;
    //parse name paramter
    if(commandList.size()>=2 && commandList.first()=="-object_name_1"){
        commandList.removeFirst();
        name1 = commandList.first();
        commandList.removeFirst();
        //removes obsolete braces from the name
        if(name1.endsWith('}') && name1.startsWith('{')){
            name1.removeFirst();
            name1.removeLast();
        }
    }
    else return "Failed: invalid argument, object_name_1 expected";
    if(commandList.first()=="-object_name_2"){
        commandList.removeFirst();
        name2 = commandList.first();
        commandList.removeFirst();
        //removes obsolete braces from the name
        if(name2.endsWith('}') && name2.startsWith('{')){
            name2.removeFirst();
            name2.removeLast();
        }
    }
    else return "Failed: invalid argument, object_name_2 expected";

    if(!Canvas::isNameUsed(name1))
        return "Failed: no object with name_1 exists";
    if(!Canvas::isNameUsed(name2))
        return "Failed: no object with name_2 exists";
    if(name1 == name2)
        return "Failed: can not connect the object to itself";
    if(!commandList.isEmpty())
        return invalidCommandMessage;

    emit(connectRequested(name1, name2));

    return "Success: objects will be connected";
}
QString  CommandMessageHandler::handleExecuteCommand(QStringList &commandList){
    if(commandList.first() != "execute_file")
        return invalidCommandMessage;

    commandList.removeFirst();//remove the first command from the list to access the file_path parameter

    if(commandList.size() < 2 || commandList.first() != "-file_path")
        return invalidFormattingMessage + " -file_path " + parameterExpectedMessage;

    commandList.removeFirst();

    QString fileName = commandList.first();

    //get rid of the braces
    fileName.removeFirst();
    fileName.removeLast();

    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return invalidCommandMessage + " could not open the file";

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        this->handleCommand(line);
    }

    file.close();
    return "Success: file executed";
}
