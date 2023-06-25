#ifndef STAFFSPACE_H
#define STAFFSPACE_H

#include <QWidget>
class StaffSpace : public QWidget
{
    Q_OBJECT
public:
    explicit StaffSpace(QWidget *parent = nullptr);

signals:
    void heightChanged(int oldH, int newH);

public slots:
    void resizeEvent(QResizeEvent* r_e);
};

#endif // STAFFSPACE_H
