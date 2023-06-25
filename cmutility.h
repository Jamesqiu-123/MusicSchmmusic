#ifndef CMUTILITY_H
#define CMUTILITY_H
class Note;

#include <QString>
#include <QMap>
#include <QRect>
#include <QFrame>
namespace Cm{
    enum {unknownType, space, line};
    enum {unknownDur, whole, half,  quarter, eighth};
    enum {up, down};
    enum {treble, bass};
    extern QString notes;
    Note lineToNote(int num);// Use Scientific Pitch Notation
    Note spaceToNote(int num);
    //extern QMap<int, QString>typeToStringMap;
    int getNotePoint(Note n, QList<QFrame*> lines, int sbl=10);
    QString getDurNotehead(int duration);
    double getRelativeDuration(int meter, int n);
    double getDurValue(int n);
    //inline int getStemDirection(Note n);
    extern const int shortestDurSpace;
    extern const int shortestDuration;
}
#include <note.h>
#endif // CMUTILITY_H
