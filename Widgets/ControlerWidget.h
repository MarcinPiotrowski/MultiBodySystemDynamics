#ifndef CONTROLERWIDGET_H
#define CONTROLERWIDGET_H

#include <QWidget>
#include <QScrollBar>
#include <QTableWidgetItem>
#include "COControler.h"

namespace Ui {
class ControlerWidget;
}

class ControlerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ControlerWidget(QWidget *parent = 0);
    ~ControlerWidget();
    void SetControler(s_ControlersParameters Controler);

signals:
    void UpdateControler(s_ControlersParameters Parameters);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::ControlerWidget *ui;
    s_ControlersParameters m_Controler;
    s_ControlersParameters m_ControlerSaved;
    void GetDataInput();

};

#endif // CONTROLERWIDGET_H
