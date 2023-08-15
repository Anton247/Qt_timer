#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ms = 0;
  s = 0;
  m = 0;
  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(TimerSlot()));
  timer->start(1);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::TimerSlot()
{
  ms++;
  if(ms >= 1000){
    ms = 0;
    s++;
  }
  if(s >= 60){
    s = 0;
    m++;
  }
  ui->label->setText(QString::number(m) + ":");
  ui->label_2->setText(QString::number(s));
  ui->label_3->setText( ":" + QString::number(ms));
}
