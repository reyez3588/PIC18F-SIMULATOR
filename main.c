/*
 * File:   main.c
 * Author: MIEC Jesús Reyes Gómez
 * Descripción: En este programa se puede imprimir en consola utilizando el 
 *              comando printf()
 *
 * Created on January 27, 2022, 9:55 PM
 */


#include <xc.h>
#include <stdio.h>


//uint32_t myVar;
float myFloat;
//int32_t m;

void init_uart(void);

void main(void) {
    init_uart();
    printf("Prueba de impresión");
    while(1)
        continue;
    //return;
}


void init_uart(void) {
    U1CON0bits.TXEN = 1;               // enable transmitter
    U1CON1bits.ON = 1;               // enable serial port
    return;
}

void putch(char data) {
    while( ! U1ERRIRbits.TXMTIF)          // wait until the transmitter is ready
        continue;
    U1TXB = data;                     // send one character
    return;
}
