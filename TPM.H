/*
 * TPM.h
 *
 *  Created on: Oct 18, 2019
 *      Author: Jaime Hueso
 */

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */


#ifndef TPM_H_
#define TPM_H_


#define  MODULO  0xFFFF  // PERIODO
#define  PRESCALER 32
#define  BCLK  4000000
#define  T_OV   MODULO*PRESCALER*(1/BCLK)


extern unsigned char global;  
//Declaracion para Variable Global en Main.c


void init_ouputcompare(void);
void periodo (unsigned int tiempo);



#endif /* TPM_H_ */
