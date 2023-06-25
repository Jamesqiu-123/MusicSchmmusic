#include "durationbutton.h"

DurationButton::DurationButton(int tp, QWidget* parent): QPushButton(parent)
{
    type = tp;
}

void DurationButton::uncheck(){
    setChecked(false);
}

void DurationButton::setType(int tp){
    type = tp;
}
