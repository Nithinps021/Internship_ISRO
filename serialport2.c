#include<stdio.h>
#include<termios.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include <string.h>
#include "nmea.h"
#include<pthread.h>
#include<errno.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#define  BUF_SIZE 1000
gga_t gga;
rmc_t rmc;
char buff_A[BUF_SIZE], buff_B[BUF_SIZE];
int BufAcnt,BufBcnt;
pthread_mutex_t mutexA=PTHREAD_MUTEX_INITIALIZER ;
pthread_mutex_t mutexB=PTHREAD_MUTEX_INITIALIZER ;
int port=7755;
int socket_id;
int i=0;
char buf[100];
struct sockaddr_in address;
    

void write_function(char* buff_write){

   
   char cpy[180];
   
            
            char*p=strtok(buff_write,"\n");

            
           
            while(p!=NULL){
                strcpy(cpy,p);
                if(strstr(p,"$GNGGA")!=NULL){
                    if(checksum(p)==0){
                        gga= PraseGGA(cpy);
                        
			            
                        printf("\ndata sent to gga\n");
                       
                        sendto(socket_id,&gga,sizeof(gga),0,(struct sockaddr *)&address,sizeof(address));
                        
                        
                    }
                }
                else if(strstr(p,"$GNRMC")!=NULL){
                    if(checksum(p)==0){
                        rmc = PraseRMC(cpy);
			            
                        printf("\ndata sent to rmc\n");
			            
                        sendto(socket_id,&rmc,sizeof(rmc),0,(struct sockaddr *)&address,sizeof(address));                       
                        
                    }
                }

                p=strtok(NULL,"\n");
            }
}
                
                
void* store_input(char* arg){
   
    FILE*fp_store;
    fp_store=fopen("cdata.txt","wb");
    
    while(1){
        pthread_mutex_lock(&mutexA);      
       
        fwrite(buff_A,1,BufAcnt,fp_store);
        fflush(fp_store);
        write_function(buff_A);
        pthread_mutex_unlock(&mutexA);

        pthread_mutex_lock(&mutexB);
        fwrite(buff_B,1,BufBcnt,fp_store);
        fflush(fp_store);
        write_function(buff_B);
        pthread_mutex_unlock(&mutexB);
    }

}



void main(){
    //socket CODE starts//
    bzero(&address,sizeof(address));
    address.sin_family=AF_INET;
    address.sin_addr.s_addr=inet_addr("10.91.46.133");
    address.sin_port=htons(port);
        
    socket_id=socket(AF_INET,SOCK_DGRAM,0);
    //socket CODE STOPS..//
	pthread_t thread_store_input;
	struct termios opt_attr;
	unsigned char rx_buffer[BUF_SIZE];
	int rx_length=-1;
	int fp_stream = -1;
    char CurBuff='A';
    int BuffCnt=0;
    fflush(stdout);
    int first_item=1;
    int first_time=1;
	
	fp_stream=open("/dev/ttyUSB0",O_RDONLY|O_NOCTTY);
	
	printf("fpstream1:%d",fp_stream);
	if(fp_stream==-1){
	    printf("\nError : %s",strerror(errno));
        return;
    }
	
	
	tcgetattr(fp_stream,&opt_attr);
    //printf("Port Opened!");
    fflush(stdout);
	opt_attr.c_cflag=B115200|CS8|CREAD|CLOCAL;
	opt_attr.c_iflag=IGNPAR;
	opt_attr.c_oflag=0;
	opt_attr.c_lflag=0;

	tcflush(fp_stream,TCIFLUSH);
	tcsetattr(fp_stream,TCSANOW,&opt_attr);
	
    pthread_mutex_lock(&mutexA);
    pthread_mutex_lock(&mutexB);
    if(pthread_create(&thread_store_input,NULL,(void*)store_input,NULL))
                       printf("ERROR %s",strerror(errno));
    //printf("\nafter pthread_create\n");
	while(1){ 
        
                       
        rx_length=read(fp_stream,(void*)rx_buffer,BUF_SIZE -1);
                 //printf("\nread to the buffer\n");
        if(first_item){
            first_item=0;
            continue;
        }
                
        if(rx_length<0){
            printf("Error");
            continue;
        }
        if(rx_length==0){
            printf("No data waiting");
            continue;
        }
        if(CurBuff=='A'){
            if(BuffCnt+rx_length>BUF_SIZE){
                CurBuff='B';
                BufAcnt=BuffCnt;
               // printf("\n buffer switching to B");
                //fflush(stdout);
                BuffCnt=0; 
                if(!first_time)
                    pthread_mutex_lock(&mutexB);   
                first_time=0;          
                pthread_mutex_unlock(&mutexA);               
                
            }
            else{
                // printf("\n filling buffer A, %d",rx_length);
               // fflush(stdout);
                memcpy(buff_A+BuffCnt,rx_buffer,rx_length);
                BuffCnt+=rx_length;              
        
            }
         }
         if(CurBuff=='B'){
            if(BuffCnt+rx_length>BUF_SIZE){
                CurBuff='A';
                BufBcnt=BuffCnt; 
               // printf("\n buffer switching to A");
                //fflush(stdout);
                memcpy(buff_A,rx_buffer,rx_length);
                BuffCnt=rx_length;  
                pthread_mutex_lock(&mutexA);                         
                pthread_mutex_unlock(&mutexB);
                                
            }
            else{
                //printf("\n filling buffer B %d",rx_length);
                //fflush(stdout);
                memcpy(buff_B+BuffCnt,rx_buffer,rx_length);
                BuffCnt+=rx_length;
                       
            }
         }                 	
       
     }
	
    
	
}



