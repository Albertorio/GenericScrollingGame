#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include "play.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_playButton_clicked();

    void on_retryButton_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_trackBox_activated(const QString &arg1);

    void on_difficultyBox_activated(const QString &arg1);

public slots:
    void score();

private:
    play *game;
    Ui::MainWindow *ui;
    QTimer *globalTimer;
    QGraphicsScene*scene;
};

#endif // MAINWINDOW_H
