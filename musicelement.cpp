#include "musicelement.h"

MusicElement::MusicElement(QWidget *parent)
    : QWidget{parent}
{

}

void MusicElement::moveRight(int distance){};

void MusicElement::moveLeft(int distance){};

void MusicElement::remove(){};

void MusicElement::increaseWidth(int amount){};

void MusicElement::decreaseWidth(int amount){};

QString MusicElement::getTypeString(){
    return this->typeString.get();
}
