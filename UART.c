#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "UART.h"

#ifndef SYS_FREQ
#define SYS_FREQ 120000000                   // 120 MHz
#endif

void UART_Init(void){
    U1MODE           = 0;                    // Set UART 1 off prior to setting it up
    U1MODEbits.BRGH  = 0;                    // High Baud Rate Enable bit. 0 = Standard Speed Mode - 16x baud clock enables
    U1BRG = SYS_FREQ / (16 * 921600) - 1;    // Baud Rate (datasheet)
    U1STA            = 0;                    // Disable the TX and RX pins, clear all flags
    U1STAbits.UTXEN  = 1;                    // UART1 transmitter is enabled
    U1STAbits.URXEN  = 1;                    // UART1 receiver is enabled
    U1MODEbits.PDSEL = 0;                    // Parity and Data Selection bits. 0 = 8-bit data, no parity
    U1MODEbits.STSEL = 0;                    // Stop Selection bit. 0 = one Stop bit
    U1MODEbits.ON    = 1;                    // Turn on the UART 5 peripheral
}

void _mon_putc (char c){
   while (U1STAbits.UTXBF);
   U1TXREG = c;
}