#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

///
/// Default Constructor for the MainWindow. Some properties:
/// * ui: Allows the user to access members of the ui
/// * scene: Creates a new scene where the game will be "painted"
/// * game:  Creates a new game
/// * globalTimer: Creates a new timer
/// * score: Getes the number of the score in a string for future use
///
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /*
     * Sets the ui and the scene for future use.
     */
    ui->setupUi(this);
    scene= new QGraphicsScene(this);
    scene->setSceneRect(QRectF(QPointF(0,0), QPointF(0,0)));

    /*
     * Places the scene in the main view and then we move mainView
     * so that it is centralized
     */
    ui->mainView->setScene(scene);
    ui->mainView->setAlignment((Qt::AlignLeft | Qt::AlignTop));
    ui->mainView->resize(550,345);
    ui->mainView->move(0,0);

    /*
     * Here we create a new game and set the racer to red, also
     * we create a timer and add the game to the scene
     */
    game = new play;
    game->setRacecar("red");
    globalTimer = new QTimer;
    scene->addWidget(game);

    /*
     * Get the score and store it as a string, then we just
     * move around the buttons and the labels to make the
     * ui more aesthetically pleasing
     */
    QString score = QString::number(game->getScore());
    ui->playButton->move(60,355);
    ui->retryButton->move(420, 355);
    ui->scoreLabel->move(210,365);
    ui->scoreLabel->setText("<h3><b>Score: </b></h3>");
    ui->label->move(262,370);
    ui->comboBox->move(63, 410);
    ui->label->setText(score);
    ui->racerLabel->move(20, 410);
    ui->racerLabel->setText("Racer: ");
    ui->difficultyBox->move(420,407);
    ui->trackBox->move(225,410);
    ui->trackLabel->setText("Track: ");
    ui->trackLabel->move(185,415);
    ui->difficultyLabel->setText("Difficulty: ");
    ui->difficultyLabel->move(355,410);
    ui->retryButton->setEnabled(false);
    setWindowTitle("Scrolling Racing Game");
}

///
/// Default destructor
///
MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

///
///
///
void MainWindow::on_playButton_clicked()
{
    game->run();
    connect(globalTimer,SIGNAL(timeout()),this,SLOT(score()));
    globalTimer->start(120);
    ui->playButton->setEnabled(false);
}

void MainWindow::score(){
    if(game->playing == false){

        ui->retryButton->setEnabled(true);
    }else{
        ui->retryButton->setEnabled(false);
    }
    QString num = QString::number(game->getScore());
    ui->label->setText(num);
}

void MainWindow::on_retryButton_clicked()
{
    game->newGame();
    delete globalTimer;
    globalTimer = new QTimer;
    connect(globalTimer,SIGNAL(timeout()),this,SLOT(score()));
    globalTimer->start(120);
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    game->keyPressEvent(event);
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    game->setRacecar(arg1.toStdString());
    repaint();
}

void MainWindow::on_trackBox_activated(const QString &arg1)
{
    //game->setTrack(arg1.toStdString());
    repaint();
}

void MainWindow::on_difficultyBox_activated(const QString &arg1)
{

    if(arg1 == "Easy"){
        qDebug() << "now its easy";
        game->easy = true;
        if(game->medium == true){
            game->medium = false;
        }
        if(game->hard == true){
            game->hard = false;
        }
        game->me_col_bol = false;
        game->ha_col_bol = false;
    }

    if(arg1 == "Medium"){
        qDebug() << "now its medium";
        game->medium = true;
        if(game->hard == true){
            game->hard = false;
        }
        if(game->easy == true){
            game->easy = false;
        }
        game->ha_col_bol = false;
    }

    if(arg1 == "Hard"){
        qDebug() << "now its hard";
        game->hard = true;
        if(game->medium == true){
            game->medium = false;
        }
        if(game->easy == true){
            game->easy = false;
        }
    }
}
