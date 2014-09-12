#ifndef AVOID_H
#define AVOID_H

#include <QWidget>
#include <string>

using namespace std;

/// 
/// Class that has the attributes of the obstacles such as:
/// * X, Y coordinates
/// * Name
/// * Setters and Getters
///
class avoid : public QWidget
{
    Q_OBJECT
public:
    explicit avoid(QWidget *parent = 0);
    int x_cone;
    int y_cone;
    int getXcone();
    int getYcone();
    string name;
    string getObs();
    void setXcone(int);
    void setObs(string);
    void setYcone(int);

};

#endif // AVOID_H
