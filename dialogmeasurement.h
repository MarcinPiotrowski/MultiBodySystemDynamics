#ifndef DIALOGMEASUREMENT_H
#define DIALOGMEASUREMENT_H

#include <QDialog>

namespace Ui {
class DialogMeasurement;
}

class DialogMeasurement : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMeasurement(QWidget *parent = 0);
    ~DialogMeasurement();
    void SetMacro(QString Macro);

private slots:
    void on_pushButton_Close_clicked();

private:
    Ui::DialogMeasurement *ui;
};

#endif // DIALOGMEASUREMENT_H
