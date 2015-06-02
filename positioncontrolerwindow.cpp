#include "positioncontrolerwindow.h"
#include "ui_positioncontrolerwindow.h"
#include <QVBoxLayout>
#include <QPushButton>

PositionControlerWindow::PositionControlerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PositionControlerWindow)
{
    ui->setupUi(this);

    QPushButton *buttons = new QPushButton[5];

    for (int i = 0 ; i < 5 ; i++)
    {
        buttons[i].setText("aaa");
    }

    QVBoxLayout *vlayout = new QVBoxLayout;
    for (int i = 0 ; i < 5 ; i++)
        {
        vlayout->addWidget(&buttons[i]);
        }

    setLayout(vlayout);


}

PositionControlerWindow::~PositionControlerWindow()
{
    delete ui;
}
