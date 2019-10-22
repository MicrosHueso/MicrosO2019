#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "TPM.h" /* include peripheral declarations */

unsigned char global=0x00;

void main(void) {
  SOPT1_COPE=0;
  PTBDD_PTBDD7=1;  
  PTADD_PTADD0=1;  // Definir usar CH0 como TPM Output Compare
  init_ouputcompare();
  
  for(;;) {
  periodo(100);
  PTBD_PTBD7=~PTBD_PTBD7;
  } /* loop forever */
  /* please make sure that you never leave main */
}
