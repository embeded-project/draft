#include <stdint.h>
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
void SystemInit(){}
void init(void){
uint32_t delay;
SYSCTL_RCGCGPIO_R |= 0x20;
delay = 1; //dummy var
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
int main(){
	init();
	while(1){
if ((GPIO_PORTF_DATA_R & 0x11 )==0)
	  GPIO_PORTF_DATA_R = 0x08;	
else if ((GPIO_PORTF_DATA_R & 0x10) ==0)
  GPIO_PORTF_DATA_R = 0x04;
else if ((GPIO_PORTF_DATA_R & 0x01) ==0)
	GPIO_PORTF_DATA_R = 0x02;
else 
  GPIO_PORTF_DATA_R = 0x00;	

}
}	