#include "barline.h"

Barline::Barline(QWidget* parent):MusicElement(parent)
{
    typeString = "barline";
}

void Barline::makeVisible(int x, int y, int sbl){
    QFrame* f = new QFrame(this);
    this->setGeometry(x, y, 3, sbl*4.5);
    f->setFrameStyle(QFrame::VLine);
    f->setVisible(true);
    f->setGeometry(0,0, 3, sbl*4.5);
    this->setVisible(true);
}
