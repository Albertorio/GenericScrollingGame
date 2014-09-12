#ifndef CHECKPOINT_H
#define CHECKPOINT_H

#include <QWidget>
#include <string>

using namespace std;

///
/// Class that has the attributes of the flags, such as:
/// * X, y coordinates
/// * Name
/// * Setters and Getters
///
class checkpoint : public QWidget
{
    Q_OBJECT
public:
    explicit checkpoint(QWidget *parent = 0);
    int y_flag;
    int x_flag;
    int getXflag();
    int getYflag();
    void setXflag(int);
    void setCheckpoint(string);
    void setYflag(int);
    string name;
    string getCheckpoint();
    
};

#endif // CHECKPOINT_H
