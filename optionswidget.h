#ifndef OPTIONSWIDGET_H
#define OPTIONSWIDGET_H

#include <QDialog>
#include "programoptions.h"
#include "DHeaders.h"

namespace Ui {
class OptionsWidget;
}

class OptionsWidget : public QDialog
{
    Q_OBJECT

public:
    explicit OptionsWidget(QWidget *parent = 0);
    void LoadOptions(ProgramOptions Options);
    ~OptionsWidget();

signals:
   void AcceptOptions(ProgramOptions Options);

private slots:
    void on_horizontalSlider_R_valueChanged(int value);

    void on_horizontalSlider_G_valueChanged(int value);

    void on_horizontalSlider_B_valueChanged(int value);

    void on_pushButton_OK_clicked();

    void on_pushButton_Cancel_clicked();

    void on_pushButton_Apply_clicked();


    void on_horizontalSlider_R_Line_valueChanged(int value);

    void on_horizontalSlider_G_Line_valueChanged(int value);

    void on_horizontalSlider_B_Line_valueChanged(int value);

    void updateBackgroundColorBox();
    void updateLinesColorBox();

private:
    Ui::OptionsWidget *ui;
    ProgramOptions SavedOptions, UnsavedOptions;
    void SaveSceneOptions();
};

#endif // OPTIONSWIDGET_H
