#include <stdint.h>
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#include <stdio.h>
#include <math.h>
#define	PI 3.14159265358979323846
void SystemInit(){}
double dist[100]={0};
volatile int i=0;
volatile double total=0;
 /*distance_total(double d){
dist[i++] = d;
for(int j=0;j<100 ; j++){
total+=dist[j];}
printf("%f",total);
}*/
double ToRadian(double deg){
return (deg*(PI/180));
}
double distance_small(double lat1 , double lon1 ,double lat2 , double lon2 ){
double RadiusEarth = 6371;
double difflat = ((ToRadian(lat2))-(ToRadian(lat1))) ;
double difflan = ((ToRadian(lon2))-(ToRadian(lon1)));
double a = sin(difflat/2) * sin(difflat/2) + cos(ToRadian(lat1))*cos(ToRadian(lat1))*sin(difflan /2) * sin(difflan/2);
double c = 2*atan2(sqrt(a),sqrt(1-a));
double d = RadiusEarth *c;
return d;
}
int main(void){
	//lat then lon
//double d =distance_small((double)30.065876, (double)31.278368,(double)30.063505919752807, (double)31.274632286110787);
//double d2 =distance_small((double)30.065876, (double)31.278368,(double)30.063505919752807, (double)31.274632286110787);
double d = distance_small(30.067299 , 31.275946 , 30.067791,31.275249);
//dist[i++]=d;

}

