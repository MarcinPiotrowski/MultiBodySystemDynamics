#include "PlotWindow.h"
#include "ui_PlotWindow.h"

PlotWindow::PlotWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlotWindow)
{
    ui->setupUi(this);


    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }

    ui->Plot->addGraph();

    // give the axes some labels:
    ui->Plot->xAxis->setLabel("Time [s]");
    ui->Plot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->Plot->xAxis->setRange(0, 10);
    ui->Plot->yAxis->rescale();


    m_TimeRangeLeft = 0;
    m_TimeRange = 10;
    ui->lineEdit_TimeScaleLength->setText(QString::number(m_TimeRange));
    m_dt = 0.1;
    m_LastTime = - 1.0;

    ui->Plot->replot();
    m_DataType = DT_JOINTS_POSITIONS;
    m_DataTypeNumber = 0;

}

PlotWindow::~PlotWindow()
{
    delete ui;
}

PW_DataType PlotWindow::GetDataType()
{
    return m_DataType;
}

int PlotWindow::GetDataTypeNumber()
{
    return m_DataTypeNumber;
}

void PlotWindow::AddData(double Time, double Data)
{


    if (m_LastTime < 0 )
        m_LastTime = Time;
    if (Time > m_LastTime + m_dt)
        {
        ui->Plot->graph(0)->addData(Time, Data);

        ui->Plot->replot();
        m_LastTime = Time;

        if (m_AutoScaleY)
            ui->Plot->yAxis->rescale();

        switch (m_ChartType)
            {
            case CT_STRIP:
                {
                if (Time - m_TimeRangeLeft > m_TimeRange)
                    {
                    m_TimeRangeLeft +=m_TimeRange;
                    ui->Plot->xAxis->setRange(m_TimeRangeLeft, m_TimeRangeLeft+m_TimeRange);
                    ui->Plot->graph(0)->clearData();
                    }
                break;
                }
            case CT_SCOPE:
                {
                ui->Plot->graph(0)->removeDataBefore(Time - m_TimeRangeLeft);
                ui->Plot->xAxis->setRange(Time - m_TimeRange, Time);
                break;
                }
            default:
                break;
            }


        }


}

void PlotWindow::on_comboBox_activated(const QString &arg1)
{
//   if (arg1 == "Joint Positions")
//       m_DataType = DT_JOINTS_POSITIONS;
//   else if (arg1 == "Joint Velocities")
//       m_DataType = DT_JOINTS_VELOCIETIES;
//   else if (arg1 == "Joint Accelerations")
//       m_DataType = DT_JOINTS_ACCELERATIONS;

//   qDebug() << m_DataType;
}



void PlotWindow::on_comboBox_2_activated(int index)
{
    m_DataTypeNumber = index;
    qDebug() << m_DataTypeNumber;
}

void PlotWindow::on_comboBox_activated(int index)
{
    m_DataType = (PW_DataType) index;
    qDebug() << m_DataType;
}

void PlotWindow::on_checkBox_clicked()
{

}

void PlotWindow::on_comboBox_3_activated(int index)
{
    m_ChartType = (PW_ChartType)index;
    ui->Plot->graph(0)->clearData();
}

void PlotWindow::on_lineEdit_TimeScaleLength_editingFinished()
{
    m_TimeRange = ui->lineEdit_TimeScaleLength->text().toDouble();
}

void PlotWindow::on_checkBox_AutoscaleY_clicked()
{
    if (ui->checkBox_AutoscaleY->isChecked())
        {
        m_AutoScaleY = true;
        ui->lineEdit_MinY->setText("");
        ui->lineEdit_MaxY->setText("");
        ui->lineEdit_MaxY->setDisabled(true);
        ui->lineEdit_MinY->setDisabled(true);
        }
    else
        {
        m_AutoScaleY = false;
        ui->lineEdit_MinY->setText("0");
        ui->lineEdit_MaxY->setText("1");
        ui->lineEdit_MaxY->setDisabled(false);
        ui->lineEdit_MinY->setDisabled(false);
        m_MinY = 0;
        m_MaxY = 1;
        ui->Plot->yAxis->setRange(m_MinY,m_MaxY);
        }


}

void PlotWindow::on_lineEdit_MinY_editingFinished()
{
    m_MinY = ui->lineEdit_MinY->text().toDouble();
    ui->Plot->yAxis->setRange(m_MinY,m_MaxY);
}

void PlotWindow::on_lineEdit_MaxY_editingFinished()
{
    m_MinY = ui->lineEdit_MinY->text().toDouble();
    ui->Plot->yAxis->setRange(m_MinY,m_MaxY);
}

void PlotWindow::on_lineEdit_TimeScaleLength_textEdited(const QString &arg1)
{
    m_TimeRange = ui->lineEdit_TimeScaleLength->text().toDouble();

}
