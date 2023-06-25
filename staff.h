
#ifndef STAFF_H
#define STAFF_H

#include <QWidget>
#include <QFrame>
#include "staffspace.h"
#include "note.h"
#include "clef.h"
#include "musicelement.h"
#include "timesignature.h"
#include "barline.h"
class Staff : public QWidget
{
    Q_OBJECT
public:
    explicit Staff(QWidget *parent = nullptr);
    void initStaff();
    void setTopHeight(int newH);
    void setBottomHeight(int newH);
    void moveTgt(int toh, int tnh);// top new height
    void mouseReleaseEvent(QMouseEvent* m_e);
    QRectF getSpaceRect(int num);
    int getSpaceAmount(int dur);
    int getLastMeasureLine(int n = 1);
    QList<QFrame*> lines;
    int sWidth = 800;
    int sbl = 10; // space between lines
    int nextNoteSpaceAmount = 0; // the space of this and next note
    StaffSpace* top, *bottom;
    QList<MusicElement*> data;
    TimeSignature ts = TimeSignature(4,4);
    int filledBeat = 0;
    bool initialized = false;
    bool clefAndTsSet = false;
signals:
    void noteClicked(Note n);
    void newStaffNeededForSpace(int start);
public slots:
    void insertNote(Note n);
    void insertClef(Clef c);
    void insertTimeSignature(TimeSignature ts);
    void insertBarline();
    //void insertBarline
};

#endif // STAFF_H
