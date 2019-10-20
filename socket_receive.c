#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>
#include<errno.h>
#include "nmea.h"
#include<pthread.h>
#include<fcntl.h>

int port=7754;
int p=1;

void *stop(void * arg){
    scanf("%d",&p);
}


int main(){

    int socket_id;
    struct sockaddr_in sin;
    gga_t *gga;
    rmc_t *rmc;
    char buff[100];
    int flag;
    pthread_t stprcv;
    pthread_create(&stprcv,NULL,(void *)stop,NULL);
  
   
    printf("Waiting for data from sender\n");
    
    bzero(&sin,sizeof(sin));
    sin.sin_family=AF_INET;
    sin.sin_addr.s_addr=htonl(INADDR_ANY);
    sin.sin_port=htons(port);
    

    socket_id=socket(AF_INET,SOCK_DGRAM,0);
    bind(socket_id,(struct sockaddr *)&sin,sizeof(sin));

    

    while(p==1){
        recvfrom(socket_id,buff,sizeof(buff),0,(struct sockaddr *)&sin,(socklen_t *)sizeof(sin));
        if(strstr(buff,"$GNGGA")!=NULL){
            gga=(gga_t *)buff;
            printf("GGA NAME:%s\n",gga->name);
            printf("utc_time:%f\n",gga->utc_time);
            printf("lattitude:%f\n",gga->lattitude);
            printf("Satellite used:%d\n",gga->satellite_used);
        }
        if(strstr(buff,"$GNRMC")!=NULL){
            rmc=(rmc_t *)buff;
            printf("RMC NAME:%s\n",rmc->name); 
        }    
    }
    close(socket_id);
    return 0;
}
