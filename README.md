# Assignment2

1. Define what is needed in case T and H

    T: 



    Questions: 
        * Do I need to store the data since I dont use cmd "L"?
        
            I need to store the characters in the rx/tx buffer to be able to send it. After a value is read from the buffer it should get removed and move the rest to the left. 


TO DO: 

    * Fix case H

        - Fix the layout of the code OK

    * Implement help functions for the cases
        
        + calcChecksum 

        + txChar

        + rxChar

        + resetRxBuffer

        + resetTxBuffer

    * Add the tests
        
        + Return every possible int value from cmdProcessor()












        








