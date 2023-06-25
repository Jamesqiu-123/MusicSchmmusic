#include "scoreinfo.h"

ScoreInfo::ScoreInfo() { }
ScoreInfo::ScoreInfo(QString title, QString author)
{
    m_title = title;
    m_composer = author;
}
QString ScoreInfo::title(){
    return m_title;
}
QString ScoreInfo::composer(){
    return m_composer;
}
