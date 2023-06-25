#include "timesignature.h"
#include <QPushButton>
TimeSignature::TimeSignature(int t, int b, QWidget *parent): MusicElement(parent){
    top = t;
    bottom = b;
    //makeVisible();
}

TimeSignature::TimeSignature(const TimeSignature &ts): MusicElement(){
    this->top = ts.top;
    this->bottom = ts.bottom;
}
void TimeSignature::makeVisible(int x, int y, int sbl){
    this->setGeometry(x, y, 15, sbl*6);
    QFont f = QString("leland");
    f.setPixelSize(20);
    QLabel *topLabel = new QLabel(this);
    topLabel->setFont(f);
    topLabel->setText("\ue084");
    topLabel->resize(15, sbl*3);

    QLabel* bottomLabel = new QLabel(this);
    bottomLabel->setFont(f);
    bottomLabel->setText("\ue084");
    bottomLabel->setGeometry(0, topLabel->geometry().bottomLeft().y() - sbl*1.5, 15, sbl*3);
    topLabel->setVisible(true);
    bottomLabel->setVisible(true);

    this->setVisible(true);
}
