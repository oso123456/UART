#include <LPC214X.H>

void Pin_direction_set(int,int);
void input_set(int ,int);
void input_clr(int ,int );
int  gpio_read(int,int);
void delay(int);
void uart_display(char *p);
char uart_receive();
void uart_baudrate(int f);