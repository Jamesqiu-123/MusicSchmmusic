#include "staff.h"
#include <QList>
#include <QPushButton>
#include <QMouseEvent>
#include "cmutility.h"
#include <QFontDatabase>
#include <QPushButton>
/*
#ifndef SBL
#define SBL 10 //space between lines
#endif
*/
void Staff::initStaff(){
    if(!initialized){
        this->setMinimumSize(sWidth, 80);//swidth =800;
        top->setParent(this);
        top->setObjectName("top");
        top->blockSignals(true);
        int y = 0;
        for(int i=0; i<5; i++){
            lines.append(new QFrame);
            lines[i]->setParent(this);
            lines[i]->setFrameStyle(QFrame::HLine);
            lines[i]->setGeometry(0, y, this->sWidth, 1);
            y += sbl;
        }

        bottom->setParent(this);
        bottom->setMinimumSize(sWidth, 30);
        QRect r = QRect(lines[4]->geometry().bottomLeft(), QSize(sWidth, 10));
        bottom->setGeometry(r);
        connect(top, &StaffSpace::heightChanged, this, &Staff::moveTgt);
        top->setMinimumSize(sWidth, 10);
        top->blockSignals(false);
        top->setGeometry(0, 0, sWidth, 10);
        this->setVisible(true);
        initialized = true;
    }
}
Staff::Staff(QWidget *parent)
    : QWidget{parent}, top(new StaffSpace), bottom(new StaffSpace)
{
    this->initStaff();
}
void Staff::setTopHeight(int newH){
    top->resize(top->width(), newH);
}
void Staff::setBottomHeight(int newH){
    bottom->resize(bottom->width(), newH);
}

inline QRectF Staff::getSpaceRect(int num){
    return QRectF(lines[num]->geometry().bottomLeft(), lines[num + 1]->geometry().topRight());
}

void Staff::moveTgt(int toh, int tnh){
    qDebug() << "Staff::moveTgt";
    int ch = tnh - toh;
    for(int i=0; i < 5; i++){
        QRect r = lines[i]->geometry();
        r.moveBottom(r.bottomLeft().y() + ch);
        lines[i]->setGeometry(r);
    }
    QRect r1 = this->geometry();
    r1.setBottom(r1.bottom() + ch);
    this->setGeometry(r1);

    QRect r2 = bottom->geometry();
    r2.moveBottom(r2.bottomLeft().y() + ch);
    bottom->setGeometry(r2);
    qDebug() << lines[0]->geometry();
    if(!clefAndTsSet){
        insertClef(Clef(Cm::treble));
        insertTimeSignature(TimeSignature(4, 4));
        clefAndTsSet = true;
    }
}

void Staff::mouseReleaseEvent(QMouseEvent* m_e){
    QPointF p = m_e->position();
    for(int i=0; i < 5; i++){
        if(QRectF(lines[i]->geometry()).contains(p)){
           emit noteClicked(Cm::lineToNote(i));
           return;
        }
        else if(i != 4 && getSpaceRect(i).contains(p)){
           emit noteClicked(Cm::spaceToNote(i));
           return;
        }
    }

}
void Staff::insertNote(Note n){
    qDebug() << "received " << n.name;
    Note* newNote = new Note(n);
    newNote->setParent(this);
    if(data.isEmpty()){
        newNote->makeVisible(QPoint(0, Cm::getNotePoint(n, this->lines, this->sbl)), this->sbl);
    }
    else{
         newNote->makeVisible(QPoint(data[data.size() - 1]->geometry().topRight().x() + nextNoteSpaceAmount,\
                              Cm::getNotePoint(n, this->lines, this->sbl)), this->sbl);
    }

    data.append(newNote);
    newNote->setVisible(true);
    this->nextNoteSpaceAmount = getSpaceAmount(newNote->duration);
    this->filledBeat += Cm::getRelativeDuration(ts.bottom, newNote->duration);
    if(data[data.size() - 1]->geometry().x() + data[data.size() - 1]->geometry().width() > this->sWidth){//move contents to new staff if exceed width
        qDebug() << "width exceeded";
        emit newStaffNeededForSpace(getLastMeasureLine() + 1);
    }
    if(this->filledBeat >= this->ts.top){//INSERT BARLINE
        insertBarline();
        filledBeat = 0;
    }

}

inline int Staff::getSpaceAmount(int dur){
    return Cm::shortestDurSpace * (abs(dur - Cm::shortestDuration) + 1);
}

void Staff::insertClef(Clef c){
    qDebug() << "received clef";
    Clef* newClef = new Clef(c);
    newClef->setParent(this);
    if (data.isEmpty()){
        newClef->makeVisible(0);
    }
    else{
        newClef->makeVisible(data[data.size() - 1]->geometry().topRight().x());
    }
    newClef->setVisible(true);
    data.append(newClef);
}

void Staff::insertTimeSignature(TimeSignature ts){
    qDebug() << "recevied time signature";
    TimeSignature* newTs = new TimeSignature(ts);
    newTs->setParent(this);

    if (data.isEmpty()){
        newTs->makeVisible(0);
    }
    else{
        newTs->makeVisible(data[data.size() - 1]->geometry().topRight().x());
    }
    data.append(newTs);
}
void Staff::insertBarline(){
    qDebug() << "received barline" ;
    Barline * newB = new Barline(this);
    if (data.isEmpty()){
        newB->makeVisible(0, lines[0]->geometry().y(), this->sbl);
    }
    else{
        if(data[data.size() - 1]->getTypeString().contains("note")){
            newB->makeVisible(data[data.size() - 1]->geometry().topRight().x() + nextNoteSpaceAmount, lines[0]->geometry().y(), this->sbl);
            nextNoteSpaceAmount = 6;
        }
        else{
            newB->makeVisible(data[data.size() - 1]->geometry().topRight().x(), lines[0]->geometry().y(), this->sbl);
        }
    }
    data.append(newB);
    qDebug() << "last measure " << getLastMeasureLine();
}

int Staff::getLastMeasureLine(int n){ //find the idx of last measure line (N=how many before last one), n=1
    int count = 0;
    for(int i= data.size() - 1; i >= 0; i--){
        if(data[i]->getTypeString().contains("barline") && (++count) == n){
                return i;
        }
    }
    return 0;
}
