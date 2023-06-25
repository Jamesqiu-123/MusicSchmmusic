#ifndef STAFFLINE_H
#define STAFFLINE_H

#include <QFrame>
#include <QWidget>

class StaffLine : public QFrame
{
public:
    StaffLine(QWidget* parent= nullptr);
    static int defaultWidth;
    void setGeo(int x1, int y1, int width);
    void setGeo(int x1, int y1);
    void mouseReleaseEvent(QMouseEvent* m_e);
signals:
};

#endif // STAFFLINE_H
