#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>
#include "nmea.h"


int port=6789;

int main(){

    int socket_id;
    struct sockaddr_in sin;
    gga_t gga;
    rmc_t rmc;
    int flag=0;
    
    printf("Waiting for data from sender\n");
    
    bzero(&sin,sizeof(sin));
    sin.sin_family=AF_INET;
    sin.sin_addr.s_addr=htonl(INADDR_ANY);
    sin.sin_port=htons(port);
    

    socket_id=socket(AF_INET,SOCK_DGRAM,0);
    bind(socket_id,(struct sockaddr *)&sin,sizeof(sin));

    while(1){
        recvfrom(socket_id,&flag,sizeof(flag),0,(struct sockaddr *)&sin,(socklen_t *)sizeof(sin));
        if(flag==1)
            recvfrom(socket_id,&gga,sizeof(gga),0,(struct sockaddr *)&sin,(socklen_t *)sizeof(sin));
        else
            recvfrom(socket_id,&rmc,sizeof(rmc),0,(struct sockaddr *)&sin,(socklen_t *)sizeof(sin));
        printf("Responce from server :%s\n",message);
        if(strncmp(message,"stop",4)==0){
            printf("sender message : stop...TEREMINATING....\n");
           break;
        }
    }
    close(socket_id);
    return 0;
}
