#ifndef TIMESIGNATURE_H
#define TIMESIGNATURE_H

#ifndef CM_TS_MAX
#define CM_TS_MAX 4
#endif
#include <QLabel>
#include "musicelement.h"

class TimeSignature : public MusicElement
{
    Q_OBJECT
public:
    TimeSignature(int t = 4, int b = 4, QWidget* parent = nullptr);
    TimeSignature(const TimeSignature& ts);
    int top = 4;
    int bottom = 4;
    void makeVisible(int x=0, int y = 0, int sbl = 10);
};

#endif // TIMESIGNATURE_H
