######################################################################
# Automatically generated by qmake (3.1) Wed Sep 11 09:49:57 2024
######################################################################

TEMPLATE = app
TARGET = CLIPainter
INCLUDEPATH += .
QT += core
QT += gui
QT += widgets
# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += basegraphicsitem.h \
           canvas.h \
           commandmessagehandler.h \
           lineitem.h \
           mainwindow.h \
           polygonitem.h \
           rectangleitem.h \
           squareitem.h \
           triangleitem.h \
           ui_mainwindow.h \
           CLIPainter_autogen/include/ui_mainwindow.h \
           build/Desktop_Qt_6_7_2-Debug/CLIPainter_autogen/include/ui_mainwindow.h
FORMS += mainwindow.ui
SOURCES += basegraphicsitem.cpp \
           canvas.cpp \
           commandmessagehandler.cpp \
           lineitem.cpp \
           main.cpp \
           mainwindow.cpp \
           polygonitem.cpp \
           rectangleitem.cpp \
           squareitem.cpp \
           triangleitem.cpp \
           CLIPainter_autogen/mocs_compilation.cpp \
           build/Desktop_Qt_6_7_2-Debug/CLIPainter_autogen/mocs_compilation.cpp \
           CMakeFiles/3.28.3/CompilerIdCXX/CMakeCXXCompilerId.cpp \
           build/Desktop_Qt_6_7_2-Debug/CMakeFiles/3.29.3/CompilerIdCXX/CMakeCXXCompilerId.cpp
TRANSLATIONS += CMakeFiles/CLIPainter.dir/compiler_depend.ts \
                CMakeFiles/CLIPainter_autogen.dir/compiler_depend.ts \
                CMakeFiles/CLIPainter_autogen_timestamp_deps.dir/compiler_depend.ts
