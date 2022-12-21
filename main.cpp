

#include "mainwindow.h"


#include <QApplication>
#include <QFile>
#include<QTextStream>

// Where execution begins
int main(int argc, char *argv[])
{
    // Creates the application object
    QApplication a(argc, argv);

    // Create the main application object and display it on screen
    MainWindow w;
    w.setWindowTitle("Text Editor");
    w.show();

    // Puts the application into a loop in which events are handled
    return a.exec();
}


