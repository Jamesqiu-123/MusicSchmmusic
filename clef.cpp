#include "clef.h"

Clef::Clef(int tp, QWidget* parent): MusicElement(parent)
{
    this->typeString = "clef";
    this->type = tp;
    //makeVisible();
}

Clef::Clef(const Clef& c): MusicElement()
{
    this->typeString = "clef";
    this->type = c.type;
}

void Clef::setType(int tp){
    this->type = tp;
}
void Clef::makeVisible(int x, int y){
    this->setGeometry(QRect(x, y, 20, 70));
    QLabel* visual = new QLabel(this);
    QFont f = QString("leland");
    f.setPixelSize(20);
    visual->setFont(f);
    if(this->type == Cm::treble){
        visual->setText("\ue050");
    }
    //visual->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    visual->setVisible(true);
    this->setVisible(true);
}
