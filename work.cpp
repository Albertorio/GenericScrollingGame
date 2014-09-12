#include "play.h"
#include <ctime>

///
/// function which updates the position of the obstacles
/// and the flags in the game
///
void play::updateObs(){
int ycone = 250;
int ycone2 = 145;
int ycone3 = 100;
int yflag;
int xflag;
int xcone = -50;


/*
 * If for the first half of the background
 */
    if (x1 < 600){
        obs.setYcone(ycone);
        obs.setXcone(xcone);
        obs2.setXcone(xcone);
        obs2.setYcone(ycone2);
        obs3.setXcone(xcone);
        obs3.setYcone(ycone3);
        flag->setYflag(yflag);
        flag->setXflag(xflag);

/* Here the student can complete exercise 1 */
//------------------------------------------//
        /*
         * The Y coordinate of the first obstacle is set randomly
         */
        ycone = rand()%200 + 80;
        
        /*
         * The Y coordinate of the second obstacle is also set randomly 
         * but keeping in mind that the second obstacle cannot appear
         * on top of the first one
         */
        do{
            ycone2 = rand()%200 + 80;
        }while (ycone2 >= ycone-35 && ycone2 <= ycone+35);

        /*
         * The Y coordinate of the third obstacle is also set randomly
         * but now the third obstacle cannot land on top of the first
         * or the second obstacle
         */
        do{
            ycone3 = rand()%200 + 80;
        }while ((ycone3 >= ycone-35 && ycone3 <= ycone+35) || (ycone3 >= ycone2-35 && ycone3 <= ycone2+35));
        
        /*
         * The Y coordinate of the flag is set randomly but the flag 
         * cannot land on top of any of the obstacles or else it would 
         * be impossible to grab it
         */
        do{
            yflag = rand()%200 + 80;
        }while ((yflag >= ycone-35 && yflag <= ycone+35) || (yflag >= ycone2-35 && yflag <= ycone2+35) || (yflag >= ycone3-35 && yflag <= ycone3+35));

        
        xflag = 600;
        xcone = 550;
//------------------------------------------//
    }
/*
 * If for the second half of th background
 */
    if (x2 < 600){
        obs.setYcone(ycone);
        obs.setXcone(xcone);
        obs2.setXcone(xcone);
        obs2.setYcone(ycone2);
        obs3.setXcone(xcone);
        obs3.setYcone(ycone3);
        flag->setYflag(yflag);
        flag->setXflag(xflag);

/* Here the student can complete exercise 1 */
//------------------------------------------//
        ycone = rand()%200 + 80;

        do{
            ycone2 = rand()%200 + 80;
        }while (ycone2 >= ycone-35 && ycone2 <= ycone+35);


        do{
            ycone3 = rand()%200 + 80;
        }while ((ycone3 >= ycone-35 && ycone3 <= ycone+35) || (ycone3 >= ycone2-35 && ycone3 <= ycone2+35));


        do{
            yflag = rand()%200 + 80;
        }while ((yflag >= ycone-35 && yflag <= ycone+35) || (yflag >= ycone2-35 && yflag <= ycone2+35) || (yflag >= ycone3-35 && yflag <= ycone3+35));

        xflag = 600;
        xcone = 550;
    //------------------------------------------//
    }
}

///
/// Function which sets the track you're going to play on
///
void play::setTrack(string arg){
    
    /*
     * The argument is the one option selected in the track selection box
     * that you'll see when you play the game. 
     */
    if(arg == "Day"){
        /*
         * All background pictures follow the same path but with
         * different names e.g. ":/images/myPicture.png"
         */
        track = ":/images/coolroad.png";
        if(rand()%2){
            /*
             * To find the names of the rest of the obstacles go to avoid.cpp
             * and in the setObs funciton you can see the name of all the obstacles
             */
            obs.setObs("hole");
        }else{
            obs.setObs("cone");
        }
    }
/* Here the student can complete exercise 2 */
//-----------------------------------------//
    else if(arg == "Night"){
        track = ":/images/roadnight.png";
        if(rand()%2){
            obs.setObs("it");
        }else{
            obs.setObs("zombie");
        }
    }
    else if(arg == "Beach"){
        track = ":/images/roadsand.png";
        if(rand()%2){
            obs.setObs("spongebob");
        }else{
            obs.setObs("patrick");
        }
    }
    else if(arg == "Candyland"){
        track = ":/images/candyroad.png";
        obs.setObs("monster");
    }
//-----------------------------------------//
    repaint();
}

///
/// Function which checks for collisions against obstacles
///
void play::collision(){

/* Here the student can complete exercise 3 */
//-----------------------------------------//
    /*
     * Here we check if the racecar is close enough to collision with an
     * obstacle, if it is then we call the stop game function and set the
     * playing boolean to false so we know the game has stopped
     */
    if((obs.getYcone() >= racecar.getYcar()-30 && obs.getYcone() <= racecar.getYcar()+30) && obs.getXcone() == 70){
        qDebug() << "Collision!!";
        stopGame();
        playing = false;
    }

    /*
     * If the medium_collision boolean is true then we check if the racecar
     * is close enough to hit an obstacle, if it is then we call the stop
     * game and set the playing boolean to false so we know the has stopped.
     *
     * We have medium_collision and hard_collision booleans so we can actually hit 
     * the extra obstacles that appear when the difficulty is changed
     */
    if(me_col_bol){
        if((obs2.getYcone() >= racecar.getYcar()-30 && obs2.getYcone() <= racecar.getYcar()+30) && obs2.getXcone() == 70){
            qDebug() << "Collision!!";
            stopGame();
            playing = false;
        }
    }

    if(ha_col_bol){
        if((obs3.getYcone() >= racecar.getYcar()-30 && obs3.getYcone() <= racecar.getYcar()+30) && obs3.getXcone() == 70){
            qDebug() << "Collision!!";
            stopGame();
            playing = false;
        }
    }
//-----------------------------------------//
}

///
/// Function which checks for collision against flags
///
void play::flagCollision(){

/* Here the student can complete exercise 3 */
//-----------------------------------------//
    /*
     * Here we check if the racecar is close enough to hit flag,
     * if it is then we add 30 points to the score and set the 
     * new X coordinate of the flag
     */
    if((flag->getYflag() >= racecar.getYcar()-20 && flag->getYflag() <= racecar.getYcar()+20) && flag->getXflag() == 70){
        score = score + 30;
        flag->setXflag(630);
        qDebug() << "flagCollision";
    }
//-----------------------------------------//
}
