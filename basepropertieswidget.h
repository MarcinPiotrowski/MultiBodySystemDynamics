/* *******************
 * File name : basepropertieswidget.h
 * Author : Marcin Piotrowski
 * Created : 2015-03-01    20:33
 * Brief : This file containts widget that sets properties of base (position and 3D model).
 * *******************
 */

#ifndef BASEPROPERTIESWIDGET_H
#define BASEPROPERTIESWIDGET_H

#include <QWidget>
#include <DHeaders.h>
#include <QFileDialog>

namespace Ui {
class BasePropertiesWidget;
}

class BasePropertiesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BasePropertiesWidget(QWidget *parent = 0);
    ~BasePropertiesWidget();
    void SetBaseProperties(s_MBSParameters Parameters);
    s_MBSParameters GetBaseProperties();

signals:
    void SendParameters(s_MBSParameters);
private slots:
    void on_radioButton_Default_clicked();

    void on_radioButton_LoadedModel_clicked();

    void on_pushButton_OK__clicked();

    void on_pushButton_Apply__clicked();

    void on_pushButton_Cancel__clicked();

private:
    Ui::BasePropertiesWidget *ui;
    s_MBSParameters m_UnsavedParameters, m_SavedParameters;
    void Setup();
    void UpdateUnsavedParameters();
};

#endif // BASEPROPERTIESWIDGET_H
