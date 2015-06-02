#ifndef LINKSPROPERTIESWIDGET_H
#define LINKSPROPERTIESWIDGET_H

#include <QWidget>
#include "DHeaders.h"
#include "QFileDialog"

namespace Ui {
class LinksPropertiesWidget;
}

class LinksPropertiesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LinksPropertiesWidget(QWidget *parent = 0);
    ~LinksPropertiesWidget();
    void SetLinksProperties(s_MBSParameters Parameters);
    s_MBSParameters GetLinksProperties();

signals:

    void SendParameters(s_MBSParameters Parameters);

private slots:
    void on_pushButton_OK_clicked();

    void on_pushButton_Cancel_clicked();

    void on_pushButton_Apply_clicked();

    void on_comboBox_Links_currentIndexChanged(int index);

    void on_radioButton_LoadedModel_clicked();

    void on_radioButton_Default_clicked();

private:
    s_MBSParameters m_SavedParameters;
    s_MBSParameters m_UnsavedParameters;
    int m_LastIndex;

    Ui::LinksPropertiesWidget *ui;
    void Setup();
    void UpdateUnsavedParameters();
};

#endif // LINKSPROPERTIESWIDGET_H
