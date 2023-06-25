#ifndef CLEF_H
#define CLEF_H

#include "musicelement.h"
#include "cmutility.h"
class Clef : public MusicElement
{
    Q_OBJECT
public:
    explicit Clef(int tp = Cm::treble, QWidget* parent = nullptr);
    Clef (const Clef& c);
    int type;
    void setType(int tp);
    void makeVisible(int x = 0, int y = 0);
};

#endif // CLEF_H
