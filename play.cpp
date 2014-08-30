#include "play.h"
#include <QDebug>


play::play(QWidget *parent) :
    QWidget(parent)
{
    x1=0;
    x2=600;
    score=0;
    setTrack("Day");
    myTimer= new QTimer(this);
    obs.setObs("cone");
    obs2.setObs("cone");
    obs3.setObs("cone");
    flag = new checkpoint;
    racecar.setRacer("red");
    easy = true;
    medium = false;
    hard = false;
    obs2.setYcone(145);
    obs3.setYcone(100);
    me_col_bol = false;
    ha_col_bol = false;
    playing = false;
}

play::~play(){
    delete myTimer;
    delete flag;
}

void play::setRacecar(string arg){
    racecar.setRacer(arg);
}

string play::getTrack(){
    return track;
}

void play::paintEvent(QPaintEvent *event){
    QPainter p(this);
    QString car = QString::fromStdString(racecar.getRacer());
    QString check = QString::fromStdString(flag->name);
    QString road = QString::fromStdString(track);
    QString cone = QString::fromStdString(obs.getObs());

    collision();

    flagCollision();

    p.drawPixmap(x1,0,600,400,QPixmap(road));
    p.drawPixmap(x2,0,610,400,QPixmap(road));

    //moves road, cones, flags
    x1 = x1-10;
    x2 = x2-10;
    obs.setXcone(obs.getXcone()-10);
    obs2.setXcone(obs2.getXcone()-10);
    obs3.setXcone(obs3.getXcone()-10);
    flag->setXflag(flag->getXflag()-10);

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

    //cones
    p.drawPixmap(obs.getXcone(),obs.getYcone(),35,35,QPixmap(cone));
    //flag
    p.drawPixmap(flag->getXflag(),flag->getYflag(),50,50,QPixmap(check));
    //racer
    p.drawPixmap(10,racecar.getYcar(),80,50,QPixmap(car));

    //when first road ends
        if (x1 < -600){
            updateObs();
            x1 = 599;
        }
    //when second road ends
        if(x2 < -600){
            updateObs();
            x2 = 599;
        }

    setScore();
}

void play::stopGame(){
    myTimer->stop();
//    playing = false;
}

void play::setScore(){
    score++;
}

int play::getScore(){
    return score;
}


void play::mySlot(){
    repaint();
}

void play::run(){
    qDebug()<< "playing";
    playing = true;
    connect(myTimer, SIGNAL(timeout()), this, SLOT(mySlot()));
    myTimer->start(16);
}

void play::newGame(){
    x1 = 0;
    x2 = 600;
    score=0;
    racecar.y_car = 80;
    obs.y_cone = 250;
    obs.x_cone = 200;
    myTimer = new QTimer(this);
    setTrack(getTrack());
    obs.getObs();
    flag = new checkpoint;
    racecar.getRacer();
    run();
    obs2.setYcone(obs2.getYcone());
    obs3.setYcone(obs2.getYcone());
}

void play::keyPressEvent(QKeyEvent *event){

    if((event->key() == Qt::Key_Up) && racecar.getYcar() > 80){
        racecar.setYcar(racecar.getYcar()-30);
    }

    if((event->key() == Qt::Key_Down) && racecar.getYcar() < 280){
        racecar.setYcar(racecar.getYcar()+30);
    }

}
