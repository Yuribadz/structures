#include "unity.h"
#include "file.h"
#include "fff.h"
DEFINE_FFF_GLOBALS;
FAKE_VALUE_FUNC(FILE *, fopen, const char*, const char*);

void setUp(void)
{
}

void tearDown(void)
{
}

void test_file_readWritable_sucess(void)
{
    fopen_fake.return_val = stderr;
    //fclose_fake.return_val = 0;
    TEST_ASSERT_EQUAL_INT(1, is_readWritable("test"));
}

void test_file_readWritable_fail(void)
{
        fopen_fake.return_val = NULL;
        TEST_ASSERT_EQUAL_INT(-1, is_readWritable("test"));
}
