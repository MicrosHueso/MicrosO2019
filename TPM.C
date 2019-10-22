/*
 * TPM.c
 *
 *  Created on: Oct 18, 2019
 *      Author: Jaime Hueso 
 *      
 *  Description. Basic TPM Driver for Output Compare Mode    
 */

#include "TPM.h" /* include peripheral declarations */


void init_ouputcompare(void)
{
	TPMMOD = MODULO; // Maxima cuenta del Contador General del TPM
	TPMC0V = 0x0000;  // Valor de Comparacion para hacer Toggle  	
	TPMC0SC = 0x14; //Modo Output Compare, Toggle
	TPMSC = 0x0D; // Sin IRQ, BusClk=4Mhz, Preescaler=32
}

void periodo (unsigned int tiempo)
{
while(!TPMC0SC_CH0F); // checar si el tiempo ya paso
TPMC0SC_CH0F=0; // Borra la bandera
TPMC0V = TPMC0V+tiempo; // Recarga el timer para el siguiente periodo
}

