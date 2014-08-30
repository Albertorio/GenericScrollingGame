#ifndef AVOID_H
#define AVOID_H

#include <QWidget>
#include <string>

using namespace std;

class avoid : public QWidget
{
    Q_OBJECT
public:
    explicit avoid(QWidget *parent = 0);
    int x_cone;
    int y_cone;
    string name;
    void setObs(string);
    string getObs();
    void setXcone(int);
    int getXcone();
    void setYcone(int);
    int getYcone();

signals:

public slots:

};

#endif // AVOID_H
