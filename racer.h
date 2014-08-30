#ifndef RACER_H
#define RACER_H

#include <QWidget>
#include <string>

using namespace std;

class racer : public QWidget
{
    Q_OBJECT
public:
    explicit racer(QWidget *parent = 0);
    int y_car;
    string name;
    void setRacer(string);
    void setYcar(int);
    int getYcar();
    string getRacer();

signals:

public slots:

};

#endif // RACER_H
