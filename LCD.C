#define  CGRAM0 0x40  
#define  DDRAM  0x80
#define  CLRDISPLAY 0x01
#define  SECONDLINE 0xC0

#define  RS   PTAD_PTAD0
#define  E    PTAD_PTAD1
#define  BUS  PTBD

void inicializar(void);
void instruccion(unsigned char comando);
void enable(void);
void retardo(unsigned int tiempo);
void MCUinit(void);

void mensaje(void);
void dato(unsigned char info);


unsigned char Inicializa4bits[7]={0x33,0x32,0x28,0x0F,0x06,0x01,0xFF};

unsigned char Icono[9]={0x1C,0x02,0x12,0x01,0x11,0x02,0x02,0x1C,0xFF};




void main(void) {

  

  for(;;) {
    __RESET_WATCHDOG();	/* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}


void MCUinit(void)
{
/*Configurar todos los modulos de HW */	
SOPT1=0x12;
PTADD_PTADD0=1;
PTADD_PTADD1=1;
PTBDD=0xF0;
/*Inicializa o Pon en Algun Estado el HW*/
PTAD_PTAD0=1;
PTAD_PTAD1=0;
PTBD=0x00;
}

void retardo(unsigned int tiempo)
{
while(tiempo)tiempo--;	
}

void enable(void)
{
E=1;
retardo(0xFFFF);
E=0;
}

void instruccion(unsigned char comando)
{
unsigned char x=0;
RS=0;
x=comando&0xF0;  // Separar el primer Nibble
BUS=x;
enable();

x=comando&0x0F;  // Separar el segundo Nibble
x=x<<4;   // Acomodar el segundo Nibble
BUS=x;
enable();
}


void dato(unsigned char info)
{
unsigned char x=0;
RS=1;
x=info&0xF0;  // Separar el primer Nibble
BUS=x;
enable();

x=info&0x0F;  // Separar el segundo Nibble
x=x<<4;   // Acomodar el segundo Nibble
BUS=x;
enable();
}

void inicializar(void)
{
unsigned char i=0;
while(Inicializa4bits[i]!=0xFF)
	{	
	instruccion(Inicializa4bits[i]);
	i++;
	}
}

void mensaje(void)
{
unsigned char i=0;
while(Icono[i]!=0xFF)
	{	
	dato(Icono[i]);
	i++;
	}
}

