#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scoreinfo.h"
#include "newscoreguide.h"
#include "scorelauncher.h"
#include <QScrollArea>
#include "stafflist.h"
#include <QFontDatabase>
MainWindow::MainWindow(QWidget *parent)
    : BaseWindow(parent)
    , ui(new Ui::MainWindow)
{
    if(!QFontDatabase::families().contains("Leland")){
        QFontDatabase::addApplicationFont(":/fonts/Leland.otf");
    }
    ui->setupUi(this);
    mainWindow = this;
    setUpMenu();
    connect(ui->newScoreButton, &QPushButton::clicked, this, &MainWindow::addScore);
    setWindowTitle("Composer2");

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::addScore(){
    NewScoreGuide* nsGuide = new NewScoreGuide;
    nsGuide->show();
    connect(nsGuide, &NewScoreGuide::nextPressed, this, [nsGuide, this](QString title, QString composer){
        nsGuide->close();
        MainWindow::launchScore(title, composer);
    });
}
void MainWindow::launchScore(QString title, QString composer){
    ScoreInfo si(title, composer);
    ScoreLauncher* sl = new ScoreLauncher;
    sl->loadFromScoreInfo(si);
    sl->show();
}
