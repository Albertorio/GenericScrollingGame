#include "racer.h"

racer::racer(QWidget *parent) :
    QWidget(parent)
{
    y_car=80;
}

void racer::setRacer(string arg){
    if (arg == "red"){
        name = ":/images/racer.png";
    }
    else if(arg== "pink"){
        name = ":/images/racer2.png";
    }
    else if(arg== "green"){
        name = ":/images/racer3.png";
    }
    else if(arg == "orange"){
        name = ":/images/racer4.png";
    }
    else if(arg == "candy"){
        name = ":/images/sweetcar.png";
    }
    else if(arg == "batman"){
        name = ":/images/batman.png";
    }
    else {
        name = ":/images/racer5.png";
    }

    repaint();
}

string racer::getRacer(){
    return name;
}

void racer::setYcar(int arg){
    y_car = arg;
}

int racer::getYcar(){
    return y_car;
}
