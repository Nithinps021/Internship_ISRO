#include "nmea.h"
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

int checksum(char *s){

    int i=1;
    unsigned char sum = 0;
    char * p;
    char *delim={"*"};
        if(s[0]!='$')
        return -1;
    while(s[i]!='*'){
          sum=sum ^ s[i];
          i++;
    }
    p=strtok(s,delim);
    p=strtok(NULL,delim);
    if((strtol(p,NULL,16))==sum)
        return 0;
    else
        return -1;
}

gga_t PraseGGA( char *st){

    char *p;
    gga_t result;
    char temp[200];
    strcpy(temp,st);
    char *delim={","};

    p=strtok(st,delim);
    strcpy(result.name,p);

    p=strtok(NULL,delim);
    result.utc_time = atof(p);

    p=strtok(NULL,delim);
    result.lattitude = atof(p);

    p=strtok(NULL,delim);
    result.N_S = *p;

    p=strtok(NULL,delim);
    result.longitude =atof(p);

    p=strtok(NULL,delim);
    result.E_W = *p;

    p=strtok(NULL,delim);
    result.quality_indicator = *p;

    p=strtok(NULL,delim);
    result.satellite_used = atoi(p);

    p=strtok(NULL,delim);
    result.HDOP = atof(p);

    p=strtok(NULL,delim);
    result.altitude = atof(p);

    p=strtok(NULL,delim);
    result.geodial_separation = atof(p);

    p=strtok(NULL,delim);
    result.age = atoi(p);

    p=strtok(NULL,delim);
    result.DGPS_ID = atoi(p) ;

    return result;
}

rmc_t PraseRMC( char *st){

    char *p;
    rmc_t result;
    char temp[200];
    strcpy(temp,st);
    char *delim={","};

    p=strtok(st,delim);
    strcpy(result.name,p);

    p=strtok(NULL,delim);
    result.utc_time = atof(p);

    p=strtok(NULL,delim);
    result.status = *p;

    p=strtok(NULL,delim);
    result.latitude = atof(p);

    p=strtok(NULL,delim);
    result.N_S = *p;

    p=strtok(NULL,delim);
    result.longitude = atof(p);

    p=strtok(NULL,delim);
    result.E_W = *p;

    p=strtok(NULL,delim);
    result.speed_over_ground = atof(p);

    p=strtok(NULL,delim);
    result.course_over_ground = atof(p);

    p=strtok(NULL,delim);
    result.utc_date = atoi(p);

    p=strtok(NULL,delim);
    result.mode_indicator = *p;

    return result;
}


