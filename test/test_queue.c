#include "unity.h"

#include "queue.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_queue_create(void)
{
	queue_t* qu = create_queue();
	TEST_ASSERT_EQUAL(qu->next, qu->next->next);
	enqueue((item_t){.i = 5}, qu);
	enqueue((item_t){.i = 6}, qu);
	remove_queue(qu);
	clean_free_nodes();
}

void test_queue_remove(void)
{
        queue_t* qu = create_queue();
        TEST_ASSERT_EQUAL(qu->next, qu->next->next);
        enqueue((item_t){.i = 5}, qu);
        qu = remove_queue(qu);
        clean_free_nodes();
        TEST_ASSERT_EQUAL_PTR(NULL, qu);
        TEST_ASSERT_EQUAL_PTR(NULL, free_list);
}

void test_queue_add_remove(void)
{
        queue_t* qu = create_queue();
        TEST_ASSERT_EQUAL(qu->next, qu->next->next);
        enqueue((item_t){.i = 5}, qu);
        TEST_ASSERT_EQUAL(5, dequeue(qu).i);
        qu = remove_queue(qu);
        clean_free_nodes();
        TEST_ASSERT_EQUAL_PTR(NULL, qu);
        TEST_ASSERT_EQUAL_PTR(NULL, free_list);
}

void test_queue_empty(void)
{
        queue_t* qu = create_queue();
        TEST_ASSERT_EQUAL(1, queue_empty(qu));
        qu = remove_queue(qu);
        clean_free_nodes();
        TEST_ASSERT_EQUAL_PTR(NULL, qu);
        TEST_ASSERT_EQUAL_PTR(NULL, free_list);
}

void test_front_element(void)
{
        queue_t* qu = create_queue();
        enqueue((item_t){.i = 5}, qu);
        TEST_ASSERT_EQUAL(5, front_element(qu).i);
        qu = remove_queue(qu);
        clean_free_nodes();
        TEST_ASSERT_EQUAL_PTR(NULL, qu);
        TEST_ASSERT_EQUAL_PTR(NULL, free_list);
}
