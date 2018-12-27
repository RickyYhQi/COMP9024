#include "minunit.h"
#include <ricky/listIteratorInt.h>
#include <assert.h>
#include <stdlib.h>

static IteratorInt test_it = NULL;
char *test_create() {
	printf("For my reasons, the test is not available for the time being and the content may be updated a little .\n--Ricky\n");

 	test_it = IteratorIntNew();
 	mu_assert(test_it != NULL, "Failed to create Iterator one !!");

	return NULL;
}

char *test_add() {
	for(int i = 0; i<11; i++) {
		int c = add(test_it,i);
		printf("adding %d in iterator...\n",i);		
		mu_assert(c == 1, "Failed to add value in iterator !");

		int c1 = hasNext(test_it);

		mu_assert(c1 == 0, "Failed detect NULL after current value!");

		int c2 = hasPrevious(test_it);
		mu_assert(c2 == 1, "Failed detect value before current value!");
	}
	mu_assert(next(test_it) == NULL, "Failed detect NULL using next() function");
	while (hasPrevious(test_it)) {
		int *ptr = previous(test_it);
		printf("previous value is %d\n",*ptr);
		mu_assert(ptr != NULL, "Failed to move to previous one !");
	}
	printf("Checking point...very first\n");
	int *fp = findPrevious(test_it,0);
	mu_assert(fp == NULL, "When you find the very first element should return NULL");
	int *fn = findNext(test_it,5);
	mu_assert(fn != NULL, "the return value of findNext function shouldn't be NULL");
	

	printf("Should be start from 6\n");
	while (hasNext(test_it)) {
		int *pp = next(test_it);
		printf("next value is %d\n",*pp);
		mu_assert(pp != NULL, "Failed to move to next one !");
	}
	printf("Checking poing...very last\n");
	fn = findNext(test_it,10);
	mu_assert(fn == NULL, "the return value of findNext function should be NULL");

	fp = findPrevious(test_it,3);
	printf("move brfore the value 3\n");
	mu_assert(fp != NULL, "find previous 3 failed");
	printf("Should start from value 3\n");

	while (hasNext(test_it)) {
		int *pp = next(test_it);
		printf("next value is %d\n",*pp);
		mu_assert(pp != NULL, "Failed to move to next one !");
	}
	printf("set the last value to -1\n");
	printf("the set function should be failed\n");
	mu_assert(set(test_it,-1) == 0, "Failed to set last value to -1\n");
	printf("test reset...\n");
	reset(test_it);
	mu_assert(hasPrevious(test_it) == 0, "Failed to reset");
	while (hasNext(test_it)) {
		int *pp = next(test_it);
		printf("next value is %d\n",*pp);
		mu_assert(pp != NULL, "Failed to move to next one !");
	}

	return NULL;
}


char *test_deleteElm() {
	printf("\n\n\nnow testing delete function\n");
	printf("four situation to delete..\n");
	reset(test_it);
	printf("Delete the vary first element 0 \n");
	printf("testing delete function...");
	mu_assert(next(test_it) != NULL, "next can't be NULL");
	mu_assert(deleteElm(test_it) == 1, "can't delete the first element 0");
	reset(test_it);
	printf("deleting the value 5..\n");
	findNext(test_it,5);
	mu_assert(deleteElm(test_it) == 1, "can't delete the first element 5");
	printf("deleting the value 4..\n");
	previous(test_it);
	mu_assert(deleteElm(test_it) == 1, "can't delete the first element 4");
	printf("deleting the value 1..\n");
	findPrevious(test_it,1);
	mu_assert(deleteElm(test_it) == 1, "can't delete the first element 1");
	


	reset(test_it);
	printf("reset the position...\n");
	while (hasNext(test_it)) {
		int *pp = next(test_it);
		printf("next value is %d\n",*pp);
		mu_assert(pp != NULL, "Failed to move to next one !");
	}

	return NULL;
}



char *test_freeIt() {
	printf("testing free function\n");
	freeIt(test_it);

	return NULL;
}

char *all_tests() {
	mu_suite_start();

	mu_run_test(test_create);
	mu_run_test(test_add);
	mu_run_test(test_deleteElm);
	mu_run_test(test_freeIt);
	return NULL;
}

RUN_TESTS(all_tests);

