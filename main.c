#include "instences.h"

int main()
{
unsigned char data;
VPBDIV = 0x01;
HAL.GPIO->Pin_direction_set(0,21);
	while(1)
	{ 
			HAL.UART->uart_baudrate(9600);
		  data=HAL.UART->uart_receive();
		  HAL.UART->uart_display(&data);
		  delay(500);
		  switch(data)
		  {
			case '0':
			HAL.GPIO->input_set(0,21);
			delay(1000);
			HAL.GPIO->input_clr(0,21);
			delay(1000);
			HAL.GPIO->input_set(0,21);
			delay(1000);
			HAL.GPIO->input_clr(0,21);
			delay(1000);
			break;
			case '1':
			HAL.GPIO->input_clr(0,21);
			delay(1000);
			break;
			case '2':
			HAL.GPIO->input_set(0,21);
			delay(1000);
			break;
			default:
			HAL.GPIO->input_clr(0,21);
			delay(1000);
			break;
			}
	}
}
