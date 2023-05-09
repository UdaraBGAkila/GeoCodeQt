#include "widget.h"
#include <QApplication>
#include <QException>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    try {
         w.show();//Displays the Window
    } catch (QException e) {

    }


    return a.exec();
}
