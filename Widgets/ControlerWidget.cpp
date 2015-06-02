#include "ControlerWidget.h"
#include "ui_ControlerWidget.h"

ControlerWidget::ControlerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlerWidget)
{
    ui->setupUi(this);
}

ControlerWidget::~ControlerWidget()
{
    delete ui;
}


void ControlerWidget::SetControler(s_ControlersParameters Controler)
{
    m_Controler = Controler;

    ui->comboBox->setCurrentIndex(m_Controler.Type);
    ui->lineEdit_MaxSpeed->setText(QString::number(m_Controler.m_MaxV));

    ui->tableWidget->setFrameStyle(QFrame::NoFrame);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->verticalScrollBar()->setDisabled(true);
    ui->tableWidget->verticalScrollBar()->hide();
    ui->tableWidget->horizontalScrollBar()->setDisabled(true);
    ui->tableWidget->horizontalScrollBar()->hide();

    ui->tableWidget_2->setFrameStyle(QFrame::NoFrame);
    ui->tableWidget_2->verticalHeader()->setVisible(false);
    ui->tableWidget_2->horizontalHeader()->setVisible(false);
    ui->tableWidget_2->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget_2->verticalScrollBar()->setDisabled(true);
    ui->tableWidget_2->verticalScrollBar()->hide();
    ui->tableWidget_2->horizontalScrollBar()->setDisabled(true);
    ui->tableWidget_2->horizontalScrollBar()->hide();

    ui->tableWidget_Kf->setFrameStyle(QFrame::NoFrame);
    ui->tableWidget_Kf->verticalHeader()->setVisible(false);
    ui->tableWidget_Kf->horizontalHeader()->setVisible(false);
    ui->tableWidget_Kf->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget_Kf->verticalScrollBar()->setDisabled(true);
    ui->tableWidget_Kf->verticalScrollBar()->hide();
    ui->tableWidget_Kf->horizontalScrollBar()->setDisabled(true);
    ui->tableWidget_Kf->horizontalScrollBar()->hide();

    ui->tableWidget_Kvf->setFrameStyle(QFrame::NoFrame);
    ui->tableWidget_Kvf->verticalHeader()->setVisible(false);
    ui->tableWidget_Kvf->horizontalHeader()->setVisible(false);
    ui->tableWidget_Kvf->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget_Kvf->verticalScrollBar()->setDisabled(true);
    ui->tableWidget_Kvf->verticalScrollBar()->hide();
    ui->tableWidget_Kvf->horizontalScrollBar()->setDisabled(true);
    ui->tableWidget_Kvf->horizontalScrollBar()->hide();


    ui->tableWidget->setRowCount(m_Controler.Size);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget_2->setRowCount(m_Controler.Size);
    ui->tableWidget_2->setColumnCount(2);
    ui->tableWidget_Kf->setRowCount(m_Controler.Size);
    ui->tableWidget_Kf->setColumnCount(2);
    ui->tableWidget_Kvf->setRowCount(m_Controler.Size);
    ui->tableWidget_Kvf->setColumnCount(2);


    QString textKp = "Kp ";
    QString textKv = "Kv ";
    QString textKf = "Kf ";
    QString textKvf = "Kvf ";
    for( int i = 0 ; i < m_Controler.Size ; i++)
    {
       ui->tableWidget->setItem(i, 0, new QTableWidgetItem);
       ui->tableWidget->setItem(i, 1, new QTableWidgetItem);
       ui->tableWidget->item(i,0)->setText(textKp + QString::number( i ) + ":");
       ui->tableWidget->verticalHeader()->resizeSection(i, 20);

       ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem);
       ui->tableWidget_2->setItem(i, 1, new QTableWidgetItem);
       ui->tableWidget_2->item(i,0)->setText(textKv + QString::number( i ) + ":");
       ui->tableWidget_2->verticalHeader()->resizeSection(i, 20);

       ui->tableWidget_Kf->setItem(i, 0, new QTableWidgetItem);
       ui->tableWidget_Kf->setItem(i, 1, new QTableWidgetItem);
       ui->tableWidget_Kf->item(i,0)->setText(textKf + QString::number( i ) + ":");
       ui->tableWidget_Kf->verticalHeader()->resizeSection(i, 20);

       ui->tableWidget_Kvf->setItem(i, 0, new QTableWidgetItem);
       ui->tableWidget_Kvf->setItem(i, 1, new QTableWidgetItem);
       ui->tableWidget_Kvf->item(i,0)->setText(textKvf + QString::number( i ) + ":");
       ui->tableWidget_Kvf->verticalHeader()->resizeSection(i, 20);
    }

    ui->tableWidget->horizontalHeader()->resizeSection(0,50);
    ui->tableWidget_2->horizontalHeader()->resizeSection(0,50);
    ui->tableWidget_Kf->horizontalHeader()->resizeSection(0,50);
    ui->tableWidget_Kvf->horizontalHeader()->resizeSection(0,50);
    ui->tableWidget->horizontalHeader()->resizeSection(1,60);
    ui->tableWidget_2->horizontalHeader()->resizeSection(1,60);
    ui->tableWidget_Kf->horizontalHeader()->resizeSection(1,60);
    ui->tableWidget_Kvf->horizontalHeader()->resizeSection(1,60);
    ui->tableWidget->setMinimumHeight(m_Controler.Size*20+15);
    ui->tableWidget->setMaximumHeight(m_Controler.Size*20+15);
    ui->tableWidget_2->setMinimumHeight(m_Controler.Size*20+15);
    ui->tableWidget_2->setMaximumHeight(m_Controler.Size*20+15);
    ui->tableWidget_Kf->setMinimumHeight(m_Controler.Size*20+15);
    ui->tableWidget_Kf->setMaximumHeight(m_Controler.Size*20+15);
    ui->tableWidget_Kvf->setMinimumHeight(m_Controler.Size*20+15);
    ui->tableWidget_Kvf->setMaximumHeight(m_Controler.Size*20+15);

    qDebug() << m_Controler.Size;



    for( int i = 0 ; i < ui->tableWidget->rowCount() ; i++)
        {
        ui->tableWidget->item(i,1)->setText(QString::number(m_Controler.m_KpDiag(i)));
        ui->tableWidget_2->item(i,1)->setText(QString::number(m_Controler.m_KvDiag(i)));
        ui->tableWidget_Kf->item(i,1)->setText(QString::number(m_Controler.m_KfDiag(i)));
        ui->tableWidget_Kvf->item(i,1)->setText(QString::number(m_Controler.m_KvfDiag(i)));
        }

}

void ControlerWidget::on_pushButton_clicked()
{
    GetDataInput();
    emit UpdateControler(m_Controler);
}

void ControlerWidget::on_pushButton_2_clicked()
{
    GetDataInput();
    emit UpdateControler(m_Controler);
    close();
}

void ControlerWidget::on_pushButton_3_clicked()
{
    close();
}

void ControlerWidget::GetDataInput()
{
    vec kpDiag, kvDiag, kfDiag, kvfDiag;
    kpDiag.resize(m_Controler.Size);
    kvDiag.resize(m_Controler.Size);
    kfDiag.resize(m_Controler.Size);
    kvfDiag.resize(m_Controler.Size);
    for( int i = 0 ; i < m_Controler.Size ; i++)
        {
        kpDiag(i) = ui->tableWidget->item(i,1)->text().toDouble();
        kvDiag(i) = ui->tableWidget_2->item(i,1)->text().toDouble();
        kfDiag(i) = ui->tableWidget_Kf->item(i,1)->text().toDouble();
        kvfDiag(i) = ui->tableWidget_Kvf->item(i,1)->text().toDouble();
        }
     m_Controler.m_KpDiag = kpDiag;
     m_Controler.m_KvDiag = kvDiag;
     m_Controler.m_KfDiag = kfDiag;
     m_Controler.m_KvfDiag = kvfDiag;
     m_Controler.Type = e_COType(ui->comboBox->currentIndex());
     m_Controler.m_MaxV = ui->lineEdit_MaxSpeed->text().toDouble();
}
