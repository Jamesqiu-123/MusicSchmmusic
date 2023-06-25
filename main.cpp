#include "mainwindow.h"
#include <QApplication>
#include "scorelauncher.h"
#include "staff.h"
#include "cmutility.h"
#include "stafflist.h"
#include "clef.h"
#include <QPushButton>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setMinimumSize(600,800);
    return a.exec();
}
