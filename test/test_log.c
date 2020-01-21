#include "unity.h"
#include "fff.h"
#include "log.h"
DEFINE_FFF_GLOBALS;
FAKE_VALUE_FUNC(qlog_t*, qlog, const char *, mode_t, int,
                int);

void fake_free(__attribute__((unused))qlog_t* log) {
}
void setUp(void)
{
        RESET_FAKE(qlog)
}

void tearDown(void)
{
}

void test_log_test(void)
{
        qlog_t test_struct;
        test_struct.free = &fake_free;
        qlog_fake.return_val = &test_struct;
        TEST_ASSERT_EQUAL_INT(1,create_logger());
        TEST_ASSERT_EQUAL(qlog_fake.call_count, 1);
        TEST_ASSERT_EQUAL_PTR(&test_struct, logger);
}
