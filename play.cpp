#include "play.h"
#include <QDebug>

///
/// Default constructor for the play class. Properties:
/// * x1: The x coordinate for the first background
/// * x2: The x coordinates for the second background
/// * score: Starts the score at 0
/// * setTrack: Sets the starting track to "Day"
/// * myTimer: Creates a new timer
/// * setObs: Sets the obstacle, there are three because in medium there are 2 cones and in hard 3 cones
/// * flag: Creates a new checkpoint
/// * setRacer: Sets the starting racer as "red"
/// * easy: Sets the starting difficulty to easy
/// * medium: Set to false until it is changed in game
/// * hard: Set to false until it is changed in game
/// * me_col_bol: Collision boolean for the medium difficulty
/// * ha_col_bol: Collision boolean for the hard difficulty
/// * playing: Verify if the game is running or not
///
play::play(QWidget *parent) :
    QWidget(parent)
{
    /*
     * X coordinates for the background and initialize the score 0 
     */
    x1=0;
    x2=600;
    score=0;
    
    /*
     * Set the starting track to 'day', set the starting racer to
     * 'red', create a new checkpoint and create a new timer
     */
    setTrack("Day");
    racecar.setRacer("red");
    flag = new checkpoint;
    myTimer= new QTimer(this);
   
    /*
     * Set the starting obsatcle as 'cone' also set the starting Y 
     * coordinates of the cones
     */
    obs.setObs("cone");
    obs2.setObs("cone");
    obs3.setObs("cone");
    obs2.setYcone(145);
    obs3.setYcone(100);
 
    /*
     * Set the starting difficulty to easy and the other 
     * are set to false
     */
    easy = true;
    medium = false;
    hard = false;
   
    /*
     * Set the collision variables of the medium and hard 
     * difficulty to false, playing bool is set to false 
     * so we know the game isn't running
     */
    me_col_bol = false;
    ha_col_bol = false;
    playing = false;
}

///
/// Default destructor
///
play::~play(){
    delete myTimer;
    delete flag;
}

///
/// Sets the racecar
///
void play::setRacecar(string arg){
    racecar.setRacer(arg);
}

///
/// Getter for the track
///
string play::getTrack(){
    return track;
}

///
/// This function is automatically invoked each time the widget or 
/// its parent receives a repaint signal.
///
void play::paintEvent(QPaintEvent *event){
    QPainter p(this);
    QString car = QString::fromStdString(racecar.getRacer());
    QString check = QString::fromStdString(flag->name);
    QString road = QString::fromStdString(track);
    QString cone = QString::fromStdString(obs.getObs());

    collision();

    flagCollision();

    /*
     * Draws the background (the road)
     */
    p.drawPixmap(x1,0,600,400,QPixmap(road));
    p.drawPixmap(x2,0,610,400,QPixmap(road));

    /*
     * Makes the road move back which creates the illusion of
     * the car moving forward, the same is done with the obstacles
     * and the flags
     */ 
    x1 = x1-10;
    x2 = x2-10;
    obs.setXcone(obs.getXcone()-10);
    obs2.setXcone(obs2.getXcone()-10);
    obs3.setXcone(obs3.getXcone()-10);
    flag->setXflag(flag->getXflag()-10);

    /*
     * Here we check if the game is on medium or hard difficulty,
     * if the game is in medium difficulty then we'll draw the extra
     * obstacle that wil appear and set medium_collision to true, which
     * will be used in the collision() function. The same will happen
     * the hard difficulty
     */
    if(medium == true){
        me_col_bol = true;
        p.drawPixmap(obs2.getXcone(),obs2.getYcone(),35,35,QPixmap(cone));
    }

    if(hard == true){
        ha_col_bol = true;
        me_col_bol = true;
        p.drawPixmap(obs2.getXcone() ,obs2.getYcone() + 10,35,35,QPixmap(cone));
        p.drawPixmap(obs3.getXcone() ,obs3.getYcone() + 20,35,35,QPixmap(cone));
    }
    
    /*
     * Here we draw the obstacles, checkpoints and the racecar
     */
    p.drawPixmap(obs.getXcone(),obs.getYcone(),35,35,QPixmap(cone));
    p.drawPixmap(flag->getXflag(),flag->getYflag(),50,50,QPixmap(check));
    p.drawPixmap(10,racecar.getYcar(),80,50,QPixmap(car));

    /*
     * To make the illusion of a continuous road, we need to draw two 
     * roads, both roads will be moving backwards at the same time 
     * and when the first one ends it is then painted next to the second 
     * one and voila! a continuous road and finally we set the score
     */
    if (x1 < -600){
        updateObs();
        x1 = 599;
    }
    if(x2 < -600){
        updateObs();
        x2 = 599;
    }

    setScore();
}

///
/// Function that stops the game by stopping the timer
/// and setting the playing boolean to false
///
void play::stopGame(){
    myTimer->stop();
}

///
/// Setter for the score
///
void play::setScore(){
    score++;
}

///
/// Getter for the score
///
int play::getScore(){
    return score;
}

///
/// Function calls the repaint function, which repaints the window
///
void play::mySlot(){
    repaint();
}

///
/// Function that runs the game, using a timer and a signal which
/// calls the mySlot function which just calls the repaint functions
///
void play::run(){
    playing = true;
    connect(myTimer, SIGNAL(timeout()), this, SLOT(mySlot()));
    myTimer->start(16);
}

///
/// Function that runs when the retry button is clicked, resets all 
/// variables of the game to the values in the constructor, except 
/// for the booleans which we need to keep the state of the game
///
void play::newGame(){
    x1 = 0;
    x2 = 600;
    score = 0;
    
    racecar.y_car = 80;
    obs.y_cone = 250;
    obs.x_cone = 200;
    obs2.setYcone(obs2.getYcone());
    obs3.setYcone(obs2.getYcone());
    setTrack(getTrack());
    racecar.getRacer();
    obs.getObs();
    
    myTimer = new QTimer(this);
    flag = new checkpoint;
   
    run();
}

///
/// Function which is used to move the racecar up and down
///
void play::keyPressEvent(QKeyEvent *event){

    if((event->key() == Qt::Key_Up) && racecar.getYcar() > 80){
        racecar.setYcar(racecar.getYcar()-30);
    }

    if((event->key() == Qt::Key_Down) && racecar.getYcar() < 280){
        racecar.setYcar(racecar.getYcar()+30);
    }

}
