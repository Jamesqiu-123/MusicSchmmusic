#ifndef METYPESTRING_H
#define METYPESTRING_H

#include <QObject>
#include <QString>
class METypeString
{
    //Q_OBJECT
public:
    METypeString();
    METypeString(QString qs);
    METypeString(const char* cpt);
    QString& get();
    QString typeString;
    void addAttribute(QString qs);
};

#endif // METYPESTRING_H
