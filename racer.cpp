#include "racer.h"


///
/// Default Constructor for the racer class. Properties are set as follow:
/// * y_car: The starting Y coordinate of the racecar
///
racer::racer(QWidget *parent) :
    QWidget(parent)
{
    y_car=80;
}

///
/// Setter for the racecar
///
void racer::setRacer(string arg){
    
    if (arg == "red") name = ":/images/racer.png";
    
    else if(arg== "pink") name = ":/images/racer2.png";
    
    else if(arg== "green") name = ":/images/racer3.png";
    
    else if(arg == "orange") name = ":/images/racer4.png";
    
    else if(arg == "candy") name = ":/images/sweetcar.png";
    
    else if(arg == "batman") name = ":/images/batman.png";
    
    else name = ":/images/racer5.png";
    

    repaint();
}

///
/// Getter for the racecar
///
string racer::getRacer(){
    return name;
}

///
/// Setter for the Y coordinate of the racecar
///
void racer::setYcar(int arg){
    y_car = arg;
}

///
/// Getter for the Y coordinate of the racecar
///
int racer::getYcar(){
    return y_car;
}
