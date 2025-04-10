#ifndef CMD_PROC_H_
#define CMD_PROC_H_

/* Some defines */
/* Other defines should be return codes of the functions */
/* E.g. #define CMD_EMPTY_STRING -1                      */
#define UART_RX_SIZE 20 	/* Maximum size of the RX buffer */ 
#define UART_TX_SIZE 20 	/* Maximum size of the TX buffer */ 
#define SOF_SYM '#'	        /* Start of Frame Symbol */
#define EOF_SYM '!'          /* End of Frame Symbol */

/* Function prototypes */

/**
 *  @brief  This function processes the chars in the RxBuffer and looks for commands. 
 *          Returns:                                                     
 *        	 0: if a valid command was found and executed           
 *   		-1: if empty string or incomplete command found         
 *   		-2: if an invalid command was found                     
 *   		-3: if a CS error is detected (command not executed)    
 *   		-4: if string format is wrong                   
 */
int cmdProcessor(void);


/**
 *  @brief This function adds a char to the RxBuffer, i.e creates the reception of commands. 
 */
int rxChar(unsigned char car);


/**
 *  @brief This function adds a char to the TxBuffer, i.e creates the transmission of answers.
 */
int txChar(unsigned char car);

/**
 *  @brief This function resets the RxBuffer. 
 */
void resetRxBuffer(void);

/**
 *  @brief This function resets the TxBuffer. 
 */
void resetTxBuffer(void);

/**
 *  @brief This function receives the data that would be sent by the sensor. 
 */
void getTxBuffer(unsigned char * buf, int * len);

/**
 *  @brief This function controlls that the sensor is send the correct data by computing the checksum of a given number of chars. 
 */
int calcChecksum(unsigned char * buf, int nbytes);

#endif
