// Console IO is a wrapper between the actual in and output and the console code
// In an embedded system, this might interface to a UART driver.

#include "consoleIo.h"

eConsoleError ConsoleIoInit(void)
{
	return CONSOLE_SUCCESS;
}

eConsoleError ConsoleIoReceive(uint8_t *buffer, const uint32_t bufferLength, uint32_t *readLength)
{
	uint8_t i = 0;
	unsigned char ch;
	HAL_StatusTypeDef status;

	status = HAL_UART_Receive(&huart3, &ch, 1, 0);

	while (status == HAL_OK && i < bufferLength)
	{
		buffer[i] = (uint8_t) ch;
		i++;
		status = HAL_UART_Receive(&huart3, &ch, 1, 0);
	}

	*readLength = i;
	return CONSOLE_SUCCESS;

	
}
/*
eConsoleError ConsoleIoReceive(uint8_t *buffer, const uint32_t bufferLength, uint32_t *readLength)
{
	uint8_t i = 0;
	char ch;
	
	ch = getchar();
	while ( ( EOF != ch ) && ( i < bufferLength ) )
	{
		buffer[i] = (uint8_t) ch;
		i++;
		ch = getch_noblock();
	}
	*readLength = i;
	return CONSOLE_SUCCESS;
}
*/

eConsoleError ConsoleIoSend(const uint8_t *buffer, const uint32_t bufferLength, uint32_t *sentLength)
{
	printf("%s",(char*)buffer);
	*sentLength = bufferLength;
	return CONSOLE_SUCCESS;
}

eConsoleError ConsoleIoSendString(const char *buffer)
{
	printf("%s", buffer);
	return CONSOLE_SUCCESS;
}

