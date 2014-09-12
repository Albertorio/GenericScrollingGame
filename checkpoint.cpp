#include "checkpoint.h"

///
/// Default constructor. The properties for the checkpoints are set as follows:
/// * x_flag: x coordinates where the checkpoint will be placed
/// * y_flag: y coordinates where the checkpoint will be placed
/// * name:   Sets the image that will be used for the checkpoint
///
checkpoint::checkpoint(QWidget *parent) :
    QWidget(parent)
{
    x_flag = 250;
    y_flag = 140;
    name = ":/images/flag.png";
}

///
/// Setter for the image of the checkpoint that will be used
///
void checkpoint::setCheckpoint(string arg){
    name = arg;
}

///
/// Getter for the image of the checkpoint
///
string checkpoint::getCheckpoint(){
    return name;
}

///
/// Setter for the X coordinates of the checkpoint
///
void checkpoint::setXflag(int arg){
    x_flag = arg;
}

///
/// Setter for the Y coordinates of the checkpoint
///
void checkpoint::setYflag(int arg){
    y_flag = arg;
}

///
/// Getter for the X coordinates of the checkpoint
///
int checkpoint::getXflag(){
    return x_flag;
}

///
/// Getter for the Y coordinates of the checkpoint
///
int checkpoint::getYflag(){
    return y_flag;
}
