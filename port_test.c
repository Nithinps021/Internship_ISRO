#include<stdio.h>
#include<termios.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include <string.h>
#include "nmea.h"
#include<pthread.h>
#include<errno.h>
gga_t gga[1000];
rmc_t rmc[1000];
char buff_read[100000];


void main(){


        pthread_t thread_store_input;
        struct termios opt_attr;
        unsigned char rx_buffer[250];
        int rx_length=0;
        int fp_stream = -1;
         fflush(stdout);

        fp_stream=open("/dev/ttyUSB0",O_RDONLY|O_NOCTTY);

        printf("fpstream1:%d",fp_stream);
        if(fp_stream==-1)
           	return;
        
        tcgetattr(fp_stream,&opt_attr);
        printf("Port Opened!");
        fflush(stdout);
        opt_attr.c_cflag=B115200|CS8|CREAD|CLOCAL;
        opt_attr.c_iflag=IGNPAR;
        opt_attr.c_oflag=0;
        opt_attr.c_lflag=0;

        tcflush(fp_stream,TCIFLUSH);
        tcsetattr(fp_stream,TCSANOW,&opt_attr);

	    while(1){
            rx_length=0;		
		    if(fp_stream!=-1){
		        while(rx_length<999){
			        rx_length+=read(fp_stream,rx_buffer,998);
                    if(rx_length<0){
                        printf("ERROR:%s",strerror(errno));
                        return;
                    }
                    else if(rx_length==0){
                        printf("ERROR:%s",strerror(errno));
                        return;
                    }
                }
                rx_buffer[rx_length]='\0';
                printf("%s",rx_buffer);
                printf("\n\n%d\n",rx_length);
		   }
       
       }

}
