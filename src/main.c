
#include <stdio.h>
#include "queue.h"


int main() {
	item_t item = { .i = 5 };
	queue_t* qu = create_queue();
	enqueue(item, qu);
	item_t item2 = { .i = 6 };
	enqueue(item2, qu);
	printf("Queue 1 = %d\n", dequeue(qu).i);
	printf("Queue 2 = %d\n", dequeue(qu).i);
	remove_queue(qu);
	clean_free_nodes();
	return 0;
}
