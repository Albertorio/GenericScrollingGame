#ifndef PLAY_H
#define PLAY_H

#include <QTimer>
#include <QtGui>
#include <QtCore>
#include <QWidget>
#include <QPainter>
#include <string>
#include "avoid.h"
#include "checkpoint.h"
#include "racer.h"

using namespace std;

///
/// This class contains all the variables and functions 
/// necessary to run the game, also contains the functions
/// that the student will be working on.
///

class play : public QWidget
{
    Q_OBJECT
public:
    /*
     * Functions used in play.cpp, needed for the game to run
     */
    explicit play(QWidget *parent = 0);
    int x1;
    int x2;
    int y_car;
    int score;
    bool easy;
    bool medium;
    bool hard;
    bool me_col_bol;
    bool ha_col_bol;
    bool playing;
    void keyPressEvent(QKeyEvent *event);
    void setScore();
    void setRacecar(string);
    int getScore();
    string track;
    string getTrack();
    void stopGame();

    /*
     * Functions used in work.cpp, these are the exercises
     * that the student will work on
     */
    void updateObs();
    void setTrack(string);
    void collision();
    void flagCollision();

    ~play();

public slots:
    void mySlot();
    void run();
    void newGame();

protected:
    void paintEvent(QPaintEvent *event);
    QTimer *myTimer;
    avoid obs;
    avoid obs2;
    avoid obs3;
    checkpoint *flag;
    racer racecar;


};

#endif // PLAY_H
