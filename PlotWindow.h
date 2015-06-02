#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include <QWidget>

enum PW_DataType
{
    DT_JOINTS_POSITIONS,
    DT_JOINTS_VELOCIETIES,
    DT_JOINTS_ACCELERATIONS
};

enum PW_ChartType
{
    CT_STRIP,
    CT_SCOPE
};

namespace Ui {
class PlotWindow;
}

class PlotWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PlotWindow(QWidget *parent = 0);
    ~PlotWindow();

    PW_DataType GetDataType();
    int GetDataTypeNumber();
    void AddData(double Time, double Data);

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(int index);

    void on_comboBox_activated(int index);

    void on_checkBox_clicked();

    void on_comboBox_3_activated(int index);

    void on_lineEdit_TimeScaleLength_editingFinished();

    void on_checkBox_AutoscaleY_clicked();

    void on_lineEdit_MinY_editingFinished();

    void on_lineEdit_MaxY_editingFinished();

    void on_lineEdit_TimeScaleLength_textEdited(const QString &arg1);

private:
    PW_DataType m_DataType;
    int m_DataTypeNumber;
    Ui::PlotWindow *ui;
    int m_MaxNumberOfPoints;
    double m_dt;
    double m_LastTime;
    double m_TimeRange;
    double m_TimeRangeLeft;
    double m_TimeRangeRight;
    double m_MinY;
    double m_MaxY;
    QVector<double> m_Time;
    QVector<double> m_Data;
    bool m_AutoScaleY;
    PW_ChartType m_ChartType;


};

#endif // PLOTWINDOW_H
