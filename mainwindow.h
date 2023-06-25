#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "basewindow.h"
#include "scoreinfo.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public BaseWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addScore();
private:
    Ui::MainWindow *ui;
public slots:
    void launchScore(QString title, QString composer);
};
#endif // MAINWINDOW_H
