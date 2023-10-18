#include "headers/window/mainapp.h"
#include "headers/window/login.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Login loginWindow;
    loginWindow.show();

//    MainApp mainappwindow;
//    mainappwindow.showMaximized();

    return a.exec();
}
