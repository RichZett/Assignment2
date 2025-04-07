#include <stdio.h>
#include <string.h>
#include "cmdproc.h"

int main(void) 
{
	int i;
	int len;
	unsigned char ans[30]; 
	unsigned char ansTest1[]={'#','h', '+', '2', '1', '1', '1', '3','!'};
	
	printf("\n Smart Sensor interface emulation \n");
	printf(" \t - simple illustration of interface and use \n\n\r");
	
	/* Init UART RX and TX buffers */
	resetTxBuffer();
	resetRxBuffer();
	
	/* Test 1 */
	
	printf("Test1 - check the answer to a valid Pt command\n");
	
	/* 1 - send the command */
	rxChar('#'); // 0
	rxChar('T'); // 1
	rxChar('1'); // 2
	rxChar('8'); // 3
	rxChar(189); // 4 - H: 177, T: 189
	rxChar('!'); // 5
			
	/* 2 - Process the comand and check the answer */
	
	cmdProcessor();
	
	getTxBuffer(ans,&len);
	if(memcmp(ans,ansTest1,len)) {
		printf("Test 1 failed\n");
	} else {
		printf("Test 1 succeeded\n");
	}	
	
	/* You can print the answer to see what is wrong, if necessary */
	printf("len : %d\n", len);

	printf("\t Received answer:");

	for(i=0; i < len; i++) {
		printf("%c", ans[i]);
	}
	printf("\n\t Expected answer:");
	i=sizeof(ansTest1);
	for(i=0; i < len; i++) {
		printf("%c", ansTest1[i]);
	}
	printf("\n");
	
	
	// /* Test 2 */
	
	printf("Test2 - check the answer to a transmission omission/error \n");
	
	/* 1 - send the command */
	rxChar('#');
	rxChar('C');
	rxChar('1');
	rxChar('8');
	rxChar(177);
	rxChar('!');
			
	/* 2 - Process the comand and check the answer */
	
	int err = cmdProcessor();
		
	if(err == -2) {
		printf("Test 2 succeeded, as omission was detected\n");
	} else {
		printf("Test 2 failed, as omission was not detected\n");
	}		
	
	/* Much more tests are needed. Unity should be used for it. */
	
	return 0;
}
