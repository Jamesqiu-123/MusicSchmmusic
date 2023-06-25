#include "metypestring.h"

METypeString::METypeString()
{
    typeString = "";
}
METypeString::METypeString(const char *cpt){
    typeString = cpt;
}
METypeString::METypeString(QString qs){
    typeString = qs;
}
void METypeString::addAttribute(QString qs){
    typeString += ("." +  qs);
}

QString& METypeString::get(){
    return typeString;
}
