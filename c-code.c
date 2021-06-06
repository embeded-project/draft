#include <stdint.h>
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#include <math.h>
//#define _USE_MATH_DEFINES
#define	PI 3.14159265358979323846
void SystemInit(){}
void initialize(void){
uint32_t delay;
SYSCTL_RCGCGPIO_R|= 0x20;
//delay = 1; //dummy var
//while((SYSCTL_PRGPIO_R & 0x20) == 0);
GPIO_PORTF_LOCK_R = 0x4C4F434B;
GPIO_PORTF_CR_R =0x1F;
GPIO_PORTF_PCTL_R =0;
GPIO_PORTF_AFSEL_R = 0;
GPIO_PORTF_AMSEL_R = 0 ;
GPIO_PORTF_DEN_R = 0x1F;
GPIO_PORTF_DIR_R = 0x0E;
GPIO_PORTF_PUR_R = 0x11;
}
double distance_total(double d){
double d_total=0;
	d_total+=d;
	if(d_total>100){
		GPIO_PORTF_DATA_R= 0x02;
	}
return d_total;
}
double distance_small(float lat1 , float lon1 ,float lat2 , float lon2 ){
int RadiusEarth = 6371;
double difflat = ((lat2)*(PI/180))-(lat1*(PI/180)) ;
double difflan = (lat2*(PI/180))-(lat1*(PI/180)) ;
double a = sin(difflat/2) * sin(difflat/2) + cos(lat1*(PI/180))*cos(lat2*(PI/180))*sin(difflan /2) * sin(difflan/2);
double c = 2*atan2(sqrt(a),sqrt(1-a));
double d = RadiusEarth *c;
distance_total(d);
return d; 
}
int main(void){
Initialize();
distance_small(30.067368 , 31.276526 , 30.066830,31.276388);
}
/*function getDistanceFromLatLonInKm(lat1,lon1,lat2,lon2) {
  var R = 6371; // Radius of the earth in km
  var dLat = deg2rad(lat2-lat1);  // deg2rad below
  var dLon = deg2rad(lon2-lon1); 
  var a = Math.sin(dLat/2) * Math.sin(dLat/2) + Math.cos(deg2rad(lat1)) * Math.cos(deg2rad(lat2)) * Math.sin(dLon/2) * Math.sin(dLon/2); 
  var c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1-a)); 
  var d = R * c; // Distance in km
  return d;
}*/