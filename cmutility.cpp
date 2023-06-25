#include "cmutility.h"

QString Cm::notes = "EGBDF";
const int Cm::shortestDurSpace = 10;
const int Cm::shortestDuration = Cm::quarter;
Note Cm::lineToNote(int num){
    if(num == 0 )
        return Note("F", 4, Cm::line, num);
    if(num == 1)
        return Note("D", 4, Cm::line, num);
    if(num == 2)
        return Note("B", 4, Cm::line, num);
    if(num == 3)
        return Note("G", 4, Cm::line, num);
    if(num == 4)
        return Note("E", 4, Cm::line, num);
    return Note();
}
Note Cm::spaceToNote(int num){
    if(num == 0)
        return Note("E", 4, Cm::space, num);
    if(num == 1)
        return Note("C", 4, Cm::space, num);
    if(num == 2)
        return Note("A", 4, Cm::space, num);
    if(num ==3)
        return Note("F", 4, Cm::space, num);
    return Note();
}
int Cm::getNotePoint(Note n, QList<QFrame *> lines, int sbl){
    if(n.number != -1){
        if(n.type == Cm::line){
            return lines[n.number]->geometry().y() - sbl/2;
        }
        else if (n.type == Cm::space){
            return lines[n.number]->geometry().y();
        }
    }
    return -1;
}

double Cm::getDurValue(int n){
    if(n == Cm::whole){
        return 4;
    }
    else if(n == Cm::half){
        return 2;
    }
    else if(n == Cm::quarter){
        return 1;
    }
    else if(n == Cm::eighth){
        return 0.5;
    }
    else{
        return -1;
    }
}
 double Cm::getRelativeDuration(int meter, int n){
    double ret = getDurValue(n);
    if(ret != -1){
        return ret*double(meter)/4;
    } else{
        return 0;
    }
}
/*
 * int Cm::getStemDirection(Note n){
 *   return (n.number > 3 ? Cm::down : Cm::up)
 * }
*/
