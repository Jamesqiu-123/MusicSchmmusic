#ifndef BARLINE_H
#define BARLINE_H

#include "musicelement.h"
#include <QFrame>
class Barline : public MusicElement
{
    Q_OBJECT
public:
    explicit Barline(QWidget* parent = nullptr);
    void makeVisible(int x, int y, int sbl=10);
};

#endif // BARLINE_H
