#ifndef HAPTICDEVICEWINDOW_H
#define HAPTICDEVICEWINDOW_H

#include <QWidget>
#include "HControler.h"

namespace Ui {
class HapticDeviceWindow;
}

class HapticDeviceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HapticDeviceWindow(HControler *HapticControler, QWidget *parent = 0);
    ~HapticDeviceWindow();

private slots:
    void on_pushButton_Cancel_1_clicked();

    void on_pushButton_Accept_1_clicked();

    void on_pushButton_Disconnected_1_clicked();

    void on_pushButton_Connected_1_clicked();

    void on_pushButton_Cancel_2_clicked();

    void on_pushButton_Accept_2_clicked();

    void on_pushButton_Disconnected_2_clicked();

    void on_pushButton_Connected_2_clicked();

private:
    Ui::HapticDeviceWindow *ui;
    HControler *m_HapticControler;
    void SetCurrentOptions(e_Device Device);
    void GetLastOptions(e_Device Device);
    void UpdateStatus(e_Device Device);
};

#endif // HAPTICDEVICEWINDOW_H
