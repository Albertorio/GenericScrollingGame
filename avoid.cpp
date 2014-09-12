#include "avoid.h"

///
/// Default constructor. The properties of the obstacles are set as follows:
/// * x_cone: x coordinates where the obstacle will be placed
/// * y_cone: y coordinates where the obstacle will be placed
///
avoid::avoid(QWidget *parent) :
    QWidget(parent)
{
    x_cone=200;
    y_cone=250;
}

///
/// Setter for the obstacle picture
///
void avoid::setObs(string arg){
    
    if(arg == "cone") name = ":/images/cone.png";
    
    else if (arg == "hole") name = ":/images/hoyo.png";
    
    else if(arg == "monster") name = ":/images/monster.png";
    
    else if(arg == "zombie") name = ":/images/zombie.png";
    
    else if(arg == "it") name = ":/images/it.png";
    
    else if(arg == "spongebob") name = ":/images/spongebob.png";
    
    else if(arg == "patrick") name = ":/images/patrick.png";
    
}

///
/// Getter for the obstacle picture
///
string avoid::getObs(){
    return name;
}

///
/// Setter for the X coordinate
///
void avoid::setXcone(int arg){
    x_cone = arg;
}

///
/// Setter for the Y coordinate
///
void avoid::setYcone(int arg){
    y_cone = arg;
}

///
/// Getter for the X coordinate
///
int avoid::getXcone(){
    return x_cone;
}

///
/// Getter for the Y coordinate
///
int avoid::getYcone(){
    return y_cone;
}


