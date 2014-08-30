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

class play : public QWidget
{
    Q_OBJECT
public:
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
    void collision();
    void keyPressEvent(QKeyEvent *event);
    void setScore();
    void setRacecar(string);
    int getScore();
    void updateObs();
    string track;
    void flagCollision();
    void setTrack(string);
    string getTrack();
    void stopGame();


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
