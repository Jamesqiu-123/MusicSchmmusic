#ifndef NEWSCOREGUIDE_H
#define NEWSCOREGUIDE_H

#include <QDialog>
#include <ui_newscoreguide.h>
#include "scoreinfo.h"
class NewScoreGuide : public QDialog
{
    Q_OBJECT
public:
    NewScoreGuide();
    Ui::NewScoreGuide* guideUi;
signals:
    void nextPressed(QString title, QString composer);
public slots:
    int checkInput(QString title, QString composer);

};

#endif // NEWSCOREGUIDE_H
