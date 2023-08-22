#include "header.h"

void Pin_direction_set(int a,int b)
{
switch(a)
		{
		case 0:
			IO0DIR|=1<<b;
			break;
		case 1:
			IO1DIR|=1<<b;
			break;
		default:
			IO0DIR|=1<<b;
	  }
}

void input_set(int a,int b)
{
	switch(a)
	{
		case 0:
			IO0SET|=1<<b;
			break;
		case 1:
			IO0SET|=1<<b;
			break;
		default:
			IO0SET|=1<<b;
			break;
	}
}

void input_clr(int a,int b)
{
	 switch(a)
		{
		case 0:
			IO0CLR|=1<<b;
			break;
		case 1:
			IO1CLR|=1<<b;
			break;
		default:
			IO0CLR|=1<<b;
	  }
}

int gpio_read(int r,int d)
{
switch(r)
{
int n;
case 0:
n=(IO0PIN&(1<<d));
return n;
break;
case 1:
n=(IO1PIN&(1<<d));
return n;
break;
}
}

void delay(int n)
{
int i,j;
	for(i=0;i<n;i++)
		{
	for(j=0;j<=1275;j++);
		}
}

void uart_baudrate(int f)
{
VPBDIV=0x01; 
PINSEL0 |= (1<<0);/* Selecting P0.0 as TXD0 */
PINSEL0 &= ~(1<<1);
PINSEL0 |= (1<<2);/* Selecting P0.0 as RXD0 */
PINSEL0 &= ~(1<<3);
if(f==9600)
{
U0LCR = 0x83;
U0DLM |= 0x01;
U0DLL |= 0x86;
U0LCR = 0x03;     //to make DLAB =0 , that is unlocking
}
if(f==11500)
{
U0LCR = 0x83;
U0DLM |= 0x01;
U0DLL |= 0x86;
U0LCR = 0x03;     //to make DLAB =0 , that is unlocking
}
}


char uart_receive()
{
unsigned char s;
while((U0LSR & (1<<0))==0);//RECEIVE BUFFER REG BE 1 check.
s=U0RBR; 
return s;
}
	
void uart_display(char *p)
{
int i;
	for(i=0;p[i]!='\0';i++)
	{
	while((U0LSR & (1<<5))==0);
	U0THR=p[i]; 
	}
}

