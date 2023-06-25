#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QMainWindow>
#include <QWidget>
class BaseWindow : public QMainWindow
{

    Q_OBJECT
public:
    explicit BaseWindow(QWidget *parent = nullptr);

protected:
    void setUpMenu();
    QAction *quitApp;
    QAction *newScore;
private:
    friend class MainWindow;
    friend class ScoreLauncher;
    class MainWindow* mainWindow;
signals:
     void widthChanged(int newW);

public slots:
     void resizeEvent(QResizeEvent* r_e) override;
};

#endif // BASEWINDOW_H
