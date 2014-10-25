#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static LIST_HEAD(list);

int main(int argc, char **argv)
{
	struct test_list {
		struct list_head list;
		int a;
		int b;
		int c;
	} tlist1, tlist2, tlist3, tlist4, tlist5;
	struct test_list *p;

	tlist1.a = 1;
	tlist1.b = 2;
	tlist1.c = 3;

	tlist2.a = 11;
	tlist2.b = 12;
	tlist2.c = 13;

	tlist3.a = 21;
	tlist3.b = 22;
	tlist3.c = 23;

	tlist4.a = 31;
	tlist4.b = 32;
	tlist4.c = 33;

	tlist5.a = 41;
	tlist5.b = 42;
	tlist5.c = 43;

	list_add_tail(&tlist1.list, &list);
	list_add_tail(&tlist2.list, &list);
	list_add_tail(&tlist3.list, &list);
	list_add_tail(&tlist4.list, &list);
	list_add_tail(&tlist5.list, &list);

	list_for_each_entry(p, &list, list) {
		printf("a=%d, b=%d, c=%d.\n", p->a, p->b, p->c);
	}

	list_del(&tlist5.list);

	printf("~~~~~~~~~~~~~~~~~~~~\n");
	list_for_each_entry(p, &list, list) {
		printf("a=%d, b=%d, c=%d.\n", p->a, p->b, p->c);
	}

	return 0;
}
