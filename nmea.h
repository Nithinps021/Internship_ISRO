#ifndef NMEA_H_INCLUDED
#define NMEA_H_INCLUDED



int checksum(char *s);


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

gga_t PraseGGA( char *st);
rmc_t PraseRMC( char *st);
void* store_input(char* buff_read);

#endif // NMEA_H_INCLUDED
