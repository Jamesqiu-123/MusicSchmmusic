#include "note.h"
#include <QFontDatabase>
Note::Note(QWidget* parent){
    QFontDatabase::addApplicationFont(":/fonts/Leland.otf");
    setParent(parent);
}

Note::Note(QString nm, int oct){
    this->typeString = "note";
    name = nm;
    octave = oct;
}

Note::Note(QString nm, int oct, int tp, int num, int dur){
    this->typeString = "note";
    name = nm;
    octave = oct;
    type = tp;
    number = num;
    duration = dur;
}

Note::Note(const Note& n): MusicElement((QWidget*)n.parent()){
    this->typeString = "note";
    this->name = n.name;
    this->octave = n.octave;
    this->type = n.type;
    this->number = n.number;
    this->duration = n.duration;
    this->setGeometry(n.geometry());
}

void Note::makeVisible(QPoint pt, int sbl){
    qDebug() << "NUMBER: " <<this->number;
    QRect geo(pt, QSize(10,10));
    qDebug() << "sbl" << sbl;
    QLabel *visual = new QLabel(this);
    QFont ld = QString("leland");
    if(this->duration == Cm::whole){
        visual->setText("\ue0a2");
        ld.setPixelSize(24);
    }
    else if(this->duration == Cm::half){
        visual->setText("\ue0a3");
        ld.setPixelSize(26);
    }
    else if (this->duration == Cm::quarter){
        visual->setText("\ue0a4");
        ld.setPixelSize(26);
    }
    this->setGeometry(geo);
    visual->setFont(ld);
    visual->setVisible(true);
    visual->resize(geo.size());

    if(this->duration == Cm::half || this->duration == Cm::quarter){
        //stem
        QFrame* stem = new QFrame(this);
        stem->setFrameShape(QFrame::VLine);
       if(this->number >= 3 || (this->number == 2 && this->type == Cm::space)){ // A or below
            this->setGeometry(this->geometry().x(), this->geometry().y() - sbl*3, this->width() + 5, this->height() + sbl*3);
            stem->setGeometry(12, 0, 4, sbl*3 + sbl/2); // stems up
            visual->setGeometry(this->size().width() - 10, this->geometry().size().height() - 10, 10,10);
       }
        else{ // B or above
            this->resize(this->size().width(), sbl*4);
            stem->setGeometry(0, sbl/2, 4, sbl*3 + sbl/2 );
            visual->setGeometry(QRect(0, 0, 10, 10));
        }
        // visual->setGeometry(this->size().width() - 24, this->geometry().size().height() - 10, 10,10);
    }
    this->setVisible(true);
}

void Note::setDuration(int d){
    this->duration = d;
}
