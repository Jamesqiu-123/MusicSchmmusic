
#include "staffspace.h"
#include <QResizeEvent>

StaffSpace::StaffSpace(QWidget *parent)
    : QWidget{parent}
{
}

void StaffSpace::resizeEvent(QResizeEvent* r_e){
    QSize oldsize = r_e->oldSize();
    if(!oldsize.isValid())
        oldsize = QSize(0,0);
    emit heightChanged(oldsize.height(), r_e->size().height());

}
