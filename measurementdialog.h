#ifndef MEASUREMENTDIALOG_H
#define MEASUREMENTDIALOG_H

#include <QDialog>

namespace Ui {
class MeasurementDialog;
}

class MeasurementDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MeasurementDialog(QWidget *parent = 0);
    ~MeasurementDialog();
    void SetMacro(QString Macro);

private:
    Ui::MeasurementDialog *ui;
};

#endif // MEASUREMENTDIALOG_H
