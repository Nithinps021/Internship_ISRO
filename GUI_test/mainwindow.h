#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMessageBox>
#include <QUdpSocket.h>
#include <QHostAddress.h>
#include<QByteArray>
#include<iostream>
#include <QMainWindow>
#include<qpushbutton.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QUdpSocket *udpSocket;
    void initSocket();

private slots:
    void on_pushButton_clicked();
    void readPendingDatagrams();
};

typedef struct
{
    char name[10];
    float utc_time;
    float lattitude;
    char N_S;
    float longitude;
    char E_W;
    char quality_indicator;
    int satellite_used;
    float HDOP;
    float altitude;
    float geodial_separation;
    int age;
    int DGPS_ID;
}gga_t;



typedef struct{

    char name[10];
    float utc_time;
    unsigned char status;
    float latitude;
    unsigned char N_S;
    float longitude;
    unsigned char E_W;
    float speed_over_ground;
    float course_over_ground;
    float utc_date;
    unsigned char mode_indicator;

}rmc_t;


typedef union{
    char msg_type[10];
    gga_t gga;
    rmc_t rmc;
}data_pkt_t;



#endif // MAINWINDOW_H
