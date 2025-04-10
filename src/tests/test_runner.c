#include "unity.h"
#include "cmdproc.h"  

void setUp(void) {}

void tearDown(void) {}

/**
 * @test Checks if cmdProcessor correctly detects an empty RxBuffer
 */
void test_isEmpty(void)
{
    TEST_ASSERT_EQUAL_INT(-1, cmdProcessor());
}


/** 
 * @test Checks that the temperature command 'T' is correctly processed and correct response is transmitted.
 */

void test_cmdT_valid(void)
{
    unsigned char expected[] = {'#','t', '+', '1', '3','!'};
    unsigned char result[30];
    int len;

    resetTxBuffer();
    resetRxBuffer();

    rxChar('#');
    rxChar('T');
    rxChar('1');
    rxChar('8');
    rxChar(189);  // Checksum for T
    rxChar('!');

    cmdProcessor();
    getTxBuffer(result, &len);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, result, len);
}
/** 
 * @test Checks that the humidity command 'H' is correctly processed and correct response is transmitted.
 */
void test_cmdH_valid(void)
{
    unsigned char expected[] = {'#','h', '+', '2', '1', '1', '1', '3','!'};
    unsigned char result[30];
    int len;

    resetTxBuffer();
    resetRxBuffer();

    rxChar('#');
    rxChar('H');
    rxChar('1');
    rxChar('8');
    rxChar(177);  // Checksum for H
    rxChar('!');

    cmdProcessor();
    getTxBuffer(result, &len);

    TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, result, len);
}

/** 
 * @test Checks that a wrong command 'C' is correctly processed, returning -2.
 */
void test_invalidCase(void)
{
    resetTxBuffer();
    resetRxBuffer();

    rxChar('#');
    rxChar('C');
    rxChar('1');
    rxChar('8');
    rxChar(177);
    rxChar('!');

    TEST_ASSERT_EQUAL_INT(-2, cmdProcessor());
}


/**
 * @test Checks that the RxBuffer gets cleared as intended and properly. 
 */
void test_resetRxBuffer_valid(void)
{
    resetRxBuffer(); 
    resetTxBuffer();

    rxChar('#');
    rxChar('T');
    rxChar('1');
    rxChar('8');
    rxChar(189);
    rxChar('!');

    resetRxBuffer();

    TEST_ASSERT_EQUAL_INT(-1, cmdProcessor());
}
/**
 * @test Checks that the TxBuffer gets cleared as intended and properly. 
 */
void test_resetTxBuffer_valid(void)
{
    unsigned char result[30];
    int len;

    resetTxBuffer();
    resetRxBuffer();

    rxChar('#');
    rxChar('T');
    rxChar('1');
    rxChar('8');
    rxChar(189); 
    rxChar('!');

    cmdProcessor();
    getTxBuffer(result, &len);

    TEST_ASSERT_GREATER_THAN(0, len);

    resetTxBuffer();

    getTxBuffer(result, &len);
    TEST_ASSERT_EQUAL(0, len);
}

/**
 * @test Check cmdProcessor behaves as expected if no SOF is given in the input. 
 */
void test_SOF_missing(void)
{
    resetRxBuffer();
    resetTxBuffer();

    // Send a value without SOF
    rxChar('T');
    rxChar('1');
    rxChar('8');
    rxChar(189);
    rxChar('!');

    // No SOF is detected -> cmdProcessor return -4 and stops/ don't acknowledge the data transfer
    TEST_ASSERT_EQUAL_INT(-4, cmdProcessor());
}

/**
 * @test Check cmdProcessor behaves as expected if no EOF is given in the input. 
 */
void test_EOF_missing(void)
{
    resetRxBuffer();
    resetTxBuffer();

    /* Send a value without EOF */
    rxChar('#');
    rxChar('T');
    rxChar('1');
    rxChar('8');
    rxChar(224);


    TEST_ASSERT_EQUAL_INT(-3, cmdProcessor());

}

/**
 * @test Checks that cmdProcessor() works correctly when there is data after EOF.
 */
void test_EOF_overflow(void)
{
    resetRxBuffer();
    resetTxBuffer();

    // Send correct data
    rxChar('#');
    rxChar('T');
    rxChar('1');
    rxChar('8');
    rxChar(189);
    rxChar('!');

    // Send more data before reseting the buffers
    rxChar('x');
    rxChar('y');
    rxChar('z');

    // First command should process as normal
    TEST_ASSERT_EQUAL_INT(0, cmdProcessor());

    // Data after EOF is regarded as irrelevant, clear the entire buffer. -> return -1; 
    TEST_ASSERT_EQUAL_INT(-1, cmdProcessor());
}

/**
 * @test Checks that cmdProcessor() handles too short frames correctly.
 */
void test_frame_too_short(void)
{
    resetRxBuffer();
    resetTxBuffer();

    // Command missing data Data
    rxChar('#');
    rxChar('T');
    rxChar(84); // CS = 'T'
    rxChar('!');

    // Should fail because it's too short for a real command
    TEST_ASSERT_EQUAL_INT(-3, cmdProcessor());
}

/** 
 * @test Checks that cmdProcessor works for longer frames.
 */
void test_frame_too_long(void)
{
    resetRxBuffer();
    resetTxBuffer();

    // CMD is 'T', DATA is 1,8,9
    // CS = 84 + 49 + 56 + 57 = 246
    rxChar('#');
    rxChar('T');
    rxChar('1');
    rxChar('8');
    rxChar('9');
    rxChar(246); // Correct checksum
    rxChar('!');

    // Since we are only sending more data, the data transfer should still go through
    TEST_ASSERT_EQUAL_INT(0, cmdProcessor());
}

/**
 * @brief Main function of the program is to run different types of tests.
 */
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_isEmpty);
    RUN_TEST(test_invalidCase);
    RUN_TEST(test_cmdT_valid);
    RUN_TEST(test_cmdH_valid);
    RUN_TEST(test_resetRxBuffer_valid);
    RUN_TEST(test_resetRxBuffer_valid);

    RUN_TEST(test_SOF_missing);

    RUN_TEST(test_EOF_missing);
    RUN_TEST(test_EOF_overflow);

    RUN_TEST(test_frame_too_short);
    RUN_TEST(test_frame_too_long);

    return UNITY_END();
}
