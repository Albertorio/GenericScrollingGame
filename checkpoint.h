#ifndef CHECKPOINT_H
#define CHECKPOINT_H

#include <QWidget>
#include <string>

using namespace std;

class checkpoint : public QWidget
{
    Q_OBJECT
public:
    explicit checkpoint(QWidget *parent = 0);
    int y_flag;
    int x_flag;
    string name;
    void setCheckpoint(string);
    string getCheckpoint();
    void setXflag(int);
    int getXflag();
    void setYflag(int);
    int getYflag();

signals:

public slots:

};

#endif // CHECKPOINT_H
