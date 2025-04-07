/* ****************************** */
/* See cmdProc.h for indications  */
/* ****************************** */
#include <stdio.h>
#include <string.h>

#include "cmdproc.h"

/* Internal variables */
/* Used as part of the UART emulation */
static unsigned char UARTRxBuffer[UART_RX_SIZE];
static unsigned char rxBufLen = 0; 

static unsigned char UARTTxBuffer[UART_TX_SIZE];
static unsigned char txBufLen = 0; 

 
/* Function implementation */

/* 
 * cmdProcessor
 */ 
int cmdProcessor(void)
{
	int i = 0;
	// unsigned char sid;
		
	/* Detect empty cmd string */
	if(rxBufLen == 0)
		return -1; 
	
	/* Find index of SOF */
	for(i=0; i < rxBufLen; i++) {
		printf("Hej %d\n", UARTRxBuffer[i]);

		if(UARTRxBuffer[i] == SOF_SYM) {
			break;
		}
	}
	printf("rxBufLen: %d\n", rxBufLen);
	/* If a SOF was found look for commands */
	if(i < rxBufLen) {
		
		switch(UARTRxBuffer[i+1]) { 
	
			case 'H':
				/* Command "H" dectected.							*/
				/* Get the humidity from the sensor 				*/
				printf("We enter case H\n");
				/* Check checksum */
				if(!(calcChecksum(&(UARTRxBuffer[i]), 1))) {
					printf("We fucked up\n");

					return -3;
				}
				printf("We are still in case H\n");
				
			
				/* Check EOF */
				if(UARTRxBuffer[i + 2] == EOF_SYM) {
					printf("We fucked up\n");

					return -4;
				}

				printf("We are still x2 case H\n");

				/* Variable to send the values */
				// unsigned int h; 

				/* Command  */ 
				txChar('#');
				txChar('h'); 
				txChar('+'); // Sensor reading, should call a function to do this part
				txChar('2'); 
				txChar('1'); 
				txChar('1'); 
				txChar('1'); 
				txChar('3'); 
				txChar('!');

				printf("txBuflen is: %d\n", txBufLen);

				/* Here you should remove the characters that are part of the 		*/
				/* command from the RX buffer. I'm just resetting it, which is not 	*/
				/* a good solution, as a new command could be in progress and		*/
				/* resetting  will generate errors		
											*/
				resetRxBuffer(); 	
				
				return 0; 

			case 'T': 
				/* Command "T" dectected.							*/
				/* Get the humidity from the sensor 				*/
				printf("We enter case T\n");
				/* Check checksum */
				if(!(calcChecksum(&(UARTRxBuffer[i]), 1))) {
					printf("We fucked up\n");

					return -3;
				}
				printf("We are still in case T\n");
				
			
				/* Check EOF */
				if(UARTRxBuffer[i + 2] == EOF_SYM) {
					printf("We fucked up\n");

					return -4;
				}

				printf("We are still x2 case T\n");

				/* Variable to send the values */
				// unsigned int h; 

				/* Command  */ 
				txChar('#');
				txChar('t'); 
				txChar('+'); // Sensor reading, should call a function to do this part
				txChar('2'); 
				txChar('1'); 
				txChar('1'); 
				txChar('1'); 
				txChar('3'); 
				txChar('!');

				printf("txBuflen is: %d\n", txBufLen);

				/* Here you should remove the characters that are part of the 		*/
				/* command from the RX buffer. I'm just resetting it, which is not 	*/
				/* a good solution, as a new command could be in progress and		*/
				/* resetting  will generate errors		
											*/
				resetRxBuffer(); 	
				
				return 0; 
								
			default:
				/* If code reaches this place, the command is not recognized */
				return -2;				
		}
		
	}
	
	/* Cmd string not null and SOF not found */
	return -4;

}

/* 
 * calcChecksum
 */ 
int calcChecksum(unsigned char * buf, int nbytes) {
	/* Here you are supposed to compute the modulo 256 checksum */
	/* of the first n bytes of buf. Then you should convert the */
	/* checksum to ascii (3 digitas/chars) and compare each one */
	/* of these digits/characters to the ones in the RxBuffer,	*/
	/* positions nbytes, nbytes + 1 and nbytes +2. 				*/
	
	/* That is your work to do. In this example I just assume 	*/
	/* that the checksum is always OK.							*/	
	
	int checksum = 0; 
	int i = 0;
	for(i = nbytes ; buf[i+1] != '!'; i++)
	{
		checksum += buf[i];
		printf("%d : ", i);
		printf("checksum: %d buf: %c\n", checksum%256, buf[i]);
		
	}	
	printf("The checksum is : %d", checksum);
	printf(" BUFF  %c \n ", buf[i]);

	return checksum == buf[i];		
}

/*
 * rxChar
 */
int rxChar(unsigned char car)
{
	/* If rxbuff not full add char to it */
	if (rxBufLen < UART_RX_SIZE) {
		UARTRxBuffer[rxBufLen] = car;
		rxBufLen += 1;
		return 0;		
	}	
	/* If cmd string full return error */
	return -1;
}

/*
 * txChar
 */
int txChar(unsigned char car)
{
	/* If rxbuff not full add char to it */
	if (txBufLen < UART_TX_SIZE) {
		UARTTxBuffer[txBufLen] = car;
		txBufLen += 1;
		return 0;		
	}	
	/* If cmd string full return error */
	return -1;
}

/*
 * resetRxBuffer
 */
void resetRxBuffer(void)
{
	for(int i = 0; i < rxBufLen; i++)
	{
		UARTRxBuffer[i] = 0; 
	}
	rxBufLen = 0;		
	return;
}

/*
 * resetTxBuffer
 */
void resetTxBuffer(void)
{
	for(int i = 0; i < txBufLen; i++)
	{
		UARTTxBuffer[i] = 0; 
	}
	txBufLen = 0;		
	return;
}

/*
 * getTxBuffer
 */
void getTxBuffer(unsigned char * buf, int * len)
{
	*len = txBufLen;
	printf("Here is *len: %d\n", *len);
	if(txBufLen > 0) {
		memcpy(buf,UARTTxBuffer,*len);
	}		
	return;
}


