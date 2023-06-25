#ifndef SCOREINFO_H
#define SCOREINFO_H

#include <QString>
class ScoreInfo
{
public:
    ScoreInfo();
    ScoreInfo(QString title, QString author);
    QString title();
    QString composer();
private:
    QString m_title;
    QString m_composer;
};

#endif // SCOREINFO_H
