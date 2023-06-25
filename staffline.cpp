#include "staffline.h"

StaffLine::StaffLine(QWidget* parent): QFrame(parent)
{
    setFrameShape(HLine);
}
void StaffLine::setGeo(int x1, int y1, int width){
    setGeometry(x1, y1, width, 1);
}
void StaffLine::setGeo(int x1, int y1){
    setGeometry(x1, y1, defaultWidth, 1);
}
void StaffLine::mouseReleaseEvent(QMouseEvent* m_e){

}
