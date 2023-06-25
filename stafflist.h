#ifndef STAFFLIST_H
#define STAFFLIST_H

#include <QWidget>
#include <staff.h>

class StaffList : public QWidget
{
    Q_OBJECT
public:
    explicit StaffList(QWidget *parent = nullptr);
    QList<Staff*> staffL;
    void addStaff();
    Staff* getStaff(int n);
    Staff* operator[](int n);
signals:

};

#endif // STAFFLIST_H
