#include "newscoreguide.h"
#include "ui_newscoreguide.h"
NewScoreGuide::NewScoreGuide(): guideUi(new Ui::NewScoreGuide)
{
    guideUi->setupUi(this);

    connect(guideUi->cancelButton, &QPushButton::pressed, this, &QDialog::reject);
    connect(guideUi->nextButton, &QPushButton::pressed, this, [this](){
        if (checkInput(guideUi->titleInput->toPlainText(), guideUi->composerInput->toPlainText()))
        {
            emit nextPressed(guideUi->titleInput->toPlainText(), guideUi->composerInput->toPlainText());
        }
    });
}
int NewScoreGuide::checkInput(QString title, QString composer){
    if (title != "" && composer != "")
        return 1;
    return 0;
}
