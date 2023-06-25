#ifndef SCORELAUNCHER_H
#define SCORELAUNCHER_H
#include <QPushButton>
#include <QMainWindow>
#include <QScrollArea>
#include "basewindow.h"
#include <QHBoxLayout>
#include "scoreinfo.h"
#include "stafflist.h"
#include "durationbutton.h"
#include "note.h"
#include <QVBoxLayout>
#include <QList>
#include "cmutility.h"
namespace Ui {
    class ScoreLauncher;
}

class ScoreLauncher : public BaseWindow
{
    Q_OBJECT

public:
    explicit ScoreLauncher(QWidget *parent = nullptr);
    ~ScoreLauncher();
    void loadFromScoreInfo(ScoreInfo si);
    void setUpElements();
private:
    Ui::ScoreLauncher *ui;
    //QPushButton* wholeButton, *halfButton, *quarterButton, *eighthButton;
    QList<DurationButton*> durationButtons;
    QScrollArea* sa;
    QHBoxLayout* noteL;
    QFont lf = QFont("leland");
    StaffList* contentStaff;

    int duration = Cm::whole;
signals:

public slots:
    void contentsToNewStaff(int start);
    void setDuration(int val);
    void addNote(Note n);
};

#endif // SCORELAUNCHER_H
