#ifndef PROJECTORYGENERATORWINDOW_H
#define PROJECTORYGENERATORWINDOW_H

#include <QWidget>

namespace Ui {
class ProjectoryGeneratorWindow;
}

class ProjectoryGeneratorWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectoryGeneratorWindow(QWidget *parent = 0);
    ~ProjectoryGeneratorWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ProjectoryGeneratorWindow *ui;
};

#endif // PROJECTORYGENERATORWINDOW_H
