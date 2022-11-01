#include <xc.h>
#include <stdio.h>
#include "DeviceConfig.h"
#include "UART.h"
#include "delay.h"

void main(void){
	// Set all pins as digital
    ANSELA = 0;
    ANSELB = 0;
    ANSELC = 0;
    ANSELE = 0;
    ANSELG = 0;
    
    // PPS for UART
    TRISGbits.TRISG6 = 0;   // pin E15 jako wyjscie
    RPG6R = 0b00001;        // RG6 = U5TX
    
    //TRISFbits.TRISF0 = 1; // pin F0 jako wejscie
	//U5RXR = 0b1100;       // RF0 = U5RX
	
	Set_MaxSpeed_Mode();
	UART_Init();

	while (1){
        printf("UART dziala i ma sie dobrze");
        delay_ms(10);
    }
}