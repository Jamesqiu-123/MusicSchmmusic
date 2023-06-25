#ifndef DURATIONBUTTON_H
#define DURATIONBUTTON_H

#include <QPushButton>
#include <QWidget>
#include "cmutility.h"

class DurationButton : public QPushButton
{
    Q_OBJECT
public:
   explicit DurationButton(int tp = Cm::unknownDur, QWidget* parent = nullptr);
   int type;
   void setType(int type);
signals:
public slots:
   void uncheck();
};

#endif // DURATIONBUTTON_H
