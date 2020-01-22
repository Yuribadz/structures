#include "unity.h"
#include "fff.h"
#include "log.h"
#include <stdbool.h>
DEFINE_FFF_GLOBALS;
FAKE_VALUE_FUNC(qlog_t*, qlog, const char *, mode_t, int,
                int);
void fake_free(__attribute__((unused))qlog_t* log)
{
}

bool fake_duplicate_log(__attribute__((unused))qlog_t *log,
                __attribute__((unused))FILE *outfp,
                __attribute__((unused))bool flush)
{
        return 0;
}
void setUp(void)
{
        RESET_FAKE(qlog)
}

void tearDown(void)
{
}

void test_log_test_success(void)
{
        qlog_t test_struct;
        test_struct.free = &fake_free;
        qlog_fake.return_val = &test_struct;
        TEST_ASSERT_EQUAL(1, create_logger());
        TEST_ASSERT_EQUAL(qlog_fake.call_count, 1);
        TEST_ASSERT_EQUAL_PTR(&test_struct, get_logger());
        close_logger();
}

void test_log_test_fail(void)
{
        qlog_fake.return_val = NULL;
        TEST_ASSERT_EQUAL(-1, create_logger());
}

void test_log_test_duplicate(void)
{
        qlog_t test_struct;
        FILE* fp = NULL;
        test_struct.free = &fake_free;
        test_struct.duplicate = &fake_duplicate_log;
        qlog_fake.return_val = &test_struct;
        TEST_ASSERT_EQUAL(1, create_logger());
        TEST_ASSERT_EQUAL(qlog_fake.call_count, 1);
        TEST_ASSERT_EQUAL_PTR(&test_struct, get_logger());
        TEST_ASSERT_EQUAL_INT(0, duplicate_log(fp, 1));
        close_logger();
}

