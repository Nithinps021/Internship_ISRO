#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QUdpSocket>
#include <QHostAddress>
#include<QByteArray>
#include<QDebug>

int count=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initSocket();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initSocket()
 {

     udpSocket = new QUdpSocket(NULL);
     udpSocket->bind(7755);
     connect(udpSocket, SIGNAL(readyRead()),this, SLOT(readPendingDatagrams()));
 }

 void MainWindow::readPendingDatagrams()
 {
     data_pkt_t dpkt;
     char buff[10];

     while (udpSocket->hasPendingDatagrams()) {
         QByteArray datagram;
         datagram.resize(udpSocket->pendingDatagramSize());
         QHostAddress sender;
         quint16 senderPort;

         udpSocket->readDatagram((char*)&dpkt, datagram.size(),
                                 &sender, &senderPort);
         count=count+1;
         sprintf(buff,"%d",count);
         ui->Pakage->setPlainText(buff);


         if(strcmp(dpkt.msg_type,"$GNGGA") == 0)
         {
             qDebug()<<dpkt.gga.name;
             qDebug()<<dpkt.gga.altitude;
             sprintf(buff,"%.2f",dpkt.gga.utc_time);
             ui->utc_time_box->setPlainText(buff);
             sprintf(buff,"%.2f",dpkt.gga.lattitude);
             ui->latitude_box->setPlainText(buff);
             if(dpkt.gga.N_S=='N')
                ui->N_S_box->setPlainText("NORTH");
             else
                 ui->N_S_box->setPlainText("SOUTH");
             sprintf(buff,"%.4f",dpkt.gga.longitude);
             ui->longitude_box->setPlainText(buff);
             sprintf(buff,"%c",dpkt.gga.E_W);
             if(*buff=='E')
                ui->E_W_box->setPlainText("EAST");
             else
                ui->E_W_box->setPlainText("WEST");
             sprintf(buff,"%c",dpkt.gga.quality_indicator);
             ui->Quality_indicaotr_box->setPlainText(buff);
             sprintf(buff,"%d",dpkt.gga.satellite_used);
             ui->Satellite_used_box->setPlainText(buff);
             sprintf(buff,"%.2f",dpkt.gga.HDOP);
             ui->HDOP_box->setPlainText(buff);
             sprintf(buff,"%.2f",dpkt.gga.altitude);
             ui->Alittude_box->setPlainText(buff);
             sprintf(buff,"%.2f",dpkt.gga.geodial_separation);
             ui->Geodial_seperation_box->setPlainText(buff);
             sprintf(buff,"%d",dpkt.gga.age);
             ui->Age_box->setPlainText(buff);
             sprintf(buff,"%d",dpkt.gga.DGPS_ID);
             ui->DGPS_statoin_ID_box->setPlainText(buff);
         }
         if(strcmp(dpkt.msg_type,"$GNRMC") == 0){
             qDebug()<<dpkt.rmc.name;
             qDebug()<<dpkt.rmc.longitude;
             sprintf(buff,"%.2f",dpkt.rmc.utc_time);
             ui->UTC_time_rmc->setPlainText(buff);
             if(dpkt.rmc.status=='A')
                 ui->status_rmc->setPlainText("DATA VALID");
             else if(dpkt.rmc.status=='V')
                 ui->status_rmc->setPlainText("RECEIVER WARNING");
             sprintf(buff,"%.4f",dpkt.rmc.latitude);
             ui->latitude_rmc->setPlainText(buff);
             if(dpkt.rmc.N_S=='N')
                ui->N_S_rmc->setPlainText("NORTH");
             else
                 ui->N_S_rmc->setPlainText("SOUTH");
             sprintf(buff,"%.2f",dpkt.rmc.longitude);
             ui->longtiutde_rmc->setPlainText(buff);
             sprintf(buff,"%c",dpkt.rmc.E_W);
             if(*buff=='E')
                ui->E_W_rmc->setPlainText("EAST");
             else
                ui->E_W_rmc->setPlainText("WEST");
             sprintf(buff,"%.2f",dpkt.rmc.speed_over_ground);
             ui->speed_over_ground_rmc->setPlainText(buff);
             sprintf(buff,"%.2f",dpkt.rmc.course_over_ground);
             ui->course_over_ground_rmc->setPlainText(buff);
             sprintf(buff,"%.2f",dpkt.rmc.utc_date);
             ui->UTC_Date_rmc->setPlainText(buff);
             switch(dpkt.rmc.mode_indicator){
             case 'N': ui->Mode_indicator_rmc->setPlainText("DATA NOT VALID");
                        break;
             case 'A': ui->Mode_indicator_rmc->setPlainText("AUTONOMOUS MODE");
                        break;
             case 'D': ui->Mode_indicator_rmc->setPlainText("DIFFERENTIAL MODE");
                        break;
             case 'E': ui->Mode_indicator_rmc->setPlainText("ESTIMATED MODE");
                        break;

             }

         }


     }
 }

void MainWindow::on_pushButton_clicked()
{

}
