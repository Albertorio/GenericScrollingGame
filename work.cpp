#include "play.h"
#include <ctime>

void play::updateObs(){
int ycone = 250;
int ycone2 = 145;
int ycone3 = 100;
int yflag;
int xflag;
int xcone = -50;



    if (x1 < 600){
        obs.setYcone(ycone);
        obs.setXcone(xcone);
        obs2.setXcone(xcone);
        obs2.setYcone(ycone2);
        obs3.setXcone(xcone);
        obs3.setYcone(ycone3);
        flag->setYflag(yflag);
        flag->setXflag(xflag);

//Here you can write the code for exercise 1//
//------------------------------------------//
        ycone = rand()%200 + 80;

        do{
            ycone2 = rand()%200 + 80;
        } while (ycone2 >= ycone-35 && ycone2 <= ycone+35);


        do{
            ycone3 = rand()%200 + 80;
        } while ((ycone3 >= ycone-35 && ycone3 <= ycone+35) || (ycone3 >= ycone2-35 && ycone3 <= ycone2+35));


        do{
            yflag = rand()%200 + 80;
        } while ((yflag >= ycone-35 && yflag <= ycone+35) || (yflag >= ycone2-35 && yflag <= ycone2+35) || (yflag >= ycone3-35 && yflag <= ycone3+35));

         xflag = 600;
         xcone = 550;
//------------------------------------------//
    }

    if (x2 < 600){
        obs.setYcone(ycone);
        obs.setXcone(xcone);
        obs2.setXcone(xcone);
        obs2.setYcone(ycone2);
        obs3.setXcone(xcone);
        obs3.setYcone(ycone3);
        flag->setYflag(yflag);
        flag->setXflag(xflag);

    //Here you can write the code for exercise 1//
    //------------------------------------------//
                ycone = rand()%200 + 80;

                do{
                    ycone2 = rand()%200 + 80;
                } while (ycone2 >= ycone-35 && ycone2 <= ycone+35);


                do{
                    ycone3 = rand()%200 + 80;
                } while ((ycone3 >= ycone-35 && ycone3 <= ycone+35) || (ycone3 >= ycone2-35 && ycone3 <= ycone2+35));


                do{
                    yflag = rand()%200 + 80;
                } while ((yflag >= ycone-35 && yflag <= ycone+35) || (yflag >= ycone2-35 && yflag <= ycone2+35) || (yflag >= ycone3-35 && yflag <= ycone3+35));

                 xflag = 600;
                 xcone = 550;
    //------------------------------------------//
    }
}

void play::setTrack(string arg){
    //The argument is the one in the track selection box when you play the game
    if(arg == "Day"){
        //All background picture follow the same path but with different names e.g. ":/images/blahblah.png"
        track = ":/images/coolroad.png";
        if(rand()%2){
            //To find the names of the obstacles go to avoid.cpp and in the setObs function you can see
            //the names of all the obstacles.
            obs.setObs("hole");
        }else{
            obs.setObs("cone");
        }
    }

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
    repaint();
}

void play::collision(){
    if((obs.getYcone() >= racecar.getYcar()-30 && obs.getYcone() <= racecar.getYcar()+30) && obs.getXcone() == 70){
        qDebug() << "Collision!!";
        stopGame();
        playing = false;
    }


    if(me_col_bol == true){
        if((obs2.getYcone() >= racecar.getYcar()-30 && obs2.getYcone() <= racecar.getYcar()+30) && obs2.getXcone() == 70){
            qDebug() << "Collision!!";
            stopGame();
            playing = false;
        }
    }

    if(ha_col_bol == true){
        if((obs3.getYcone() >= racecar.getYcar()-30 && obs3.getYcone() <= racecar.getYcar()+30) && obs3.getXcone() == 70){
            qDebug() << "Collision!!";
            stopGame();
            playing = false;
        }
    }
}

void play::flagCollision(){
    if((flag->getYflag() >= racecar.getYcar()-20 && flag->getYflag() <= racecar.getYcar()+20) && flag->getXflag() == 70){
        score = score + 30;
        flag->setXflag(630);
        qDebug() << "flagCollision";
    }
}
