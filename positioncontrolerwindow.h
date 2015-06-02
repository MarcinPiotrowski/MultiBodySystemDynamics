#ifndef POSITIONCONTROLERWINDOW_H
#define POSITIONCONTROLERWINDOW_H

#include <QWidget>

namespace Ui {
class PositionControlerWindow;
}

class PositionControlerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PositionControlerWindow(QWidget *parent = 0);
    ~PositionControlerWindow();

private:
    Ui::PositionControlerWindow *ui;
};

#endif // POSITIONCONTROLERWINDOW_H
