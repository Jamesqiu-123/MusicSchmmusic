#include "basewindow.h"
#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QApplication>
#include <QResizeEvent>
#include "mainwindow.h"

BaseWindow::BaseWindow(QWidget *parent)
    : QMainWindow{parent}
{
}

void BaseWindow::setUpMenu(){
    quitApp = new QAction("&Quit", this);
    QMenu *fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction(quitApp);
    connect(quitApp, &QAction::triggered, qApp, QApplication::quit);
    newScore = new QAction("&New Score", this);
    fileMenu->addAction(newScore);
    connect(newScore, &QAction::triggered, mainWindow, &MainWindow::addScore);
}


void BaseWindow::resizeEvent(QResizeEvent* r_e){
    emit widthChanged(r_e->size().width());
}
