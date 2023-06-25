#ifndef NOTE_H
#define NOTE_H

#include "musicelement.h"
#include <QString>
#include "cmutility.h"
#include <QLabel>
class Note : public MusicElement
{
public:
    Note(QWidget* parent = nullptr);
    Note(QString nm, int oct = 4);
    Note(const Note& n);
    Note(QString nm, int oct, int tp, int num, int dur = Cm::unknownDur);
    void makeVisible(QPoint pt = QPoint(0,0), int sbl=10);
    void setDuration(int d);
    QString name;
    int octave = -1;
    int number = -1; //staff/line num
    int type = Cm::unknownType;
    int duration = Cm::unknownDur;
};

#endif // NOTE_H
