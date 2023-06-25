#include "scorelauncher.h"
#include "ui_scorelauncher.h"
#include <QLayout>
#include "durationbutton.h"
#include "stafflist.h"
ScoreLauncher::ScoreLauncher(QWidget *parent) :
    BaseWindow(parent), ui(new Ui::ScoreLauncher),
    sa(new QScrollArea)
{
    ui->setupUi(this);
    setUpElements();
    
}
void ScoreLauncher::setUpElements(){
    noteL = new QHBoxLayout(ui->toolkitContents);
    durationButtons.append(new DurationButton(Cm::whole));
    durationButtons[0]->setText("\ue1d2");
    durationButtons.append(new DurationButton(Cm::half));
    durationButtons[1]->setText("\ue1d3");
    durationButtons.append(new DurationButton(Cm::quarter));
    durationButtons[2]->setText("\ue1d5");
    /*
    durationButtons.append(new DurationButton(Cm::eighth));
    durationButtons[3]->setText("\ue1d7");
   */
    for(int i = 0; i < durationButtons.size(); i++){
        noteL->addWidget(durationButtons[i]);
        durationButtons[i]->setFont(lf);
        durationButtons[i]->setCheckable(1);
        for(int j=0; j < durationButtons.size(); j++){
            if(j == i){
                continue;
            }
            connect(durationButtons[i], &DurationButton::clicked, durationButtons[j], &DurationButton::uncheck);
        }
        connect(durationButtons[i], &DurationButton::clicked, [this, i](){
            setDuration(durationButtons[i]->type);
        });
    }
    contentStaff = new StaffList(this);
    contentStaff->setGeometry(0, ui->composerBox->geometry().bottomRight().y() + 10, 0, 0);
    connect(contentStaff->getStaff(-1), &Staff::noteClicked, this, &ScoreLauncher::addNote);
    connect(contentStaff->getStaff(-1), &Staff::newStaffNeededForSpace, this, &ScoreLauncher::contentsToNewStaff);
/*
    sa->setWidget(this);
    sa->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    sa->show();
    sa->setMinimumSize(800, 600);
*/
}
void ScoreLauncher::loadFromScoreInfo(ScoreInfo si){
    this->ui->titleBox->setPlainText(si.title());
    this->ui->composerBox->setPlainText(si.composer());
}
ScoreLauncher::~ScoreLauncher()
{
    delete ui;
}
void ScoreLauncher::setDuration(int val){
    this->duration = val;
    qDebug() << "duration is setted to: " << val;
}

void ScoreLauncher::addNote(Note n){
    n.setDuration(this->duration);
    Staff * s = contentStaff->getStaff(-1);
    s->insertNote(n);
}

void ScoreLauncher::contentsToNewStaff(int start){
    qDebug() << "----------start new staff------------" << this->geometry();
    contentStaff->addStaff();
    connect(contentStaff->getStaff(-1), &Staff::noteClicked, this, &ScoreLauncher::addNote);
    connect(contentStaff->getStaff(-1), &Staff::newStaffNeededForSpace, this, &ScoreLauncher::contentsToNewStaff);
 }
