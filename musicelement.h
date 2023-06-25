#ifndef MUSICELEMENT_H
#define MUSICELEMENT_H

#include <QWidget>
#include "metypestring.h"
class MusicElement : public QWidget
{
    Q_OBJECT
public:
    explicit MusicElement(QWidget *parent = nullptr);
    virtual void moveRight(int distance);
    virtual void moveLeft(int distance);
    virtual void remove();
    virtual void increaseWidth(int amount);
    virtual void decreaseWidth(int amount);
    QString getTypeString();
protected:
    METypeString typeString;
signals:
   void movedRight(int distance);
   void movedLeft(int distance);
   void removed(int width);
   void widthIncreased(int amount);
   void widthdecreased(int amount);

};

#endif // MUSICELEMENT_H
