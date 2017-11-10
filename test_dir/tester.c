/*
	Created by: David Krsitoffersen
	Description: Unit tester for simple implementation of linked list in C
	Usage: 
		$ make testlist
		$ ./testlist
*/

#include "tester.h"
#include "../list.h"

typedef struct listnode {struct listnode *next, *prev; void *item;} listnode_t;
struct list {listnode_t *head, *tail; int numitems;};
struct list_iterator {listnode_t *next; list_t *list;};

int *dup_arr(int *array, int size) {
	int *output = calloc(size, sizeof(int));;
	for (int i = 0; i < size; i++) output[i] = array[i];
	return output;
}

void print_status(char *func_name, int status) {
	printf("%s:", func_name);
	for(float i = 4; i > ((strlen(func_name) + 1) / 8); i--) printf("\t");
	status ? printf(" BUILD \e[38;2;0;255;0mPASSED\e[m\n") : printf(" BUILD \e[38;2;255;0;0mFAILED\e[m\n");
}

int size  = 10;

int main() {
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	// List functions
	print_status("list_create", test_list_create(dup_arr(arr, size)));
	print_status("list_destroy", test_list_destroy(dup_arr(arr, size)));
	print_status("list_addfirst", test_list_addfirst(dup_arr(arr, size)));
	print_status("list_addlast", test_list_addlast(dup_arr(arr, size)));
	print_status("list_remove", test_list_remove(dup_arr(arr, size)));
	print_status("list_size", test_list_size(dup_arr(arr, size)));

	// Iterator functions
	print_status("list_createiterator", test_list_createiterator(dup_arr(arr, size)));
	print_status("list_destroyiterator", test_list_destroyiterator(dup_arr(arr, size)));
	print_status("list_resetiterator", test_list_resetiterator(dup_arr(arr, size)));
	print_status("list_next", test_list_next(dup_arr(arr, size)));
	return 0;
}

/*
//	Test functions
*/

int *allocate_int(int input) {
	int *output = malloc(sizeof(int));
	*output = input;
	return output;
}

void printlist(list_t *list) {
	listnode_t *node = list->head;
	for (int i = 0; node != NULL && node->item != NULL; i++) {
		printf("list[%d] = %d\n", i, *(int*)node->item);
		node = node->next;
		if (i > 12) break;
	}
}

list_t *list_inputarr(list_t *list, int *array) {
	for (int i = 0; i < size; i++) list_addfirst(list, &array[i]);
	return list;
}

/*
//	List functions
*/

// Create list
int test_list_create(int *array) {
	int result = 1;										// Init

	list_t *list = list_create();			 			// Testing funcion call
	if (!list) result = 0;

	list_destroy(list); 								// Freeing memory
	free(array);
	return result;
}
// Destroy list
int test_list_destroy(int *array) {
	int result = 1;										// Init
	list_t *list = list_create();
	list_inputarr(list, array);

	list_destroy(list);									// Testing funcion call

	free(array);
	return result;
}
// Add item
int test_list_addfirst(int *array) {
	int result = 1;										// Init
	int item = 13;
	list_t *list = list_create();
	list_inputarr(list, array);

	list_addfirst(list, allocate_int(item)); 			// Testing funcion call
	if (*(int *)list->head->item != item) result = 0;

	list_destroy(list);									// Freeing memory
	free(array);
	return result;
}
int test_list_addlast(int *array) {
	int result = 1;										// Init
	int item = 13;
	list_t *list = list_create();
	list_inputarr(list, array);

	list_addlast(list, allocate_int(item));		 		// Testing funcion call
	listnode_t *node = list->head;
	while(node->next) node = node->next;
	if (*(int *)node->item != item) result = 0;

	list_destroy(list); 								// Freeing memory
	free(array);
	return result;
}
// Remove item
int test_list_remove(int *array) {
	int result = 1;										// Init
	int item_arr[] = {3, -3, 42, 0, 9};
	list_t *list = list_create();
	list_inputarr(list, array);

	for (int i = 0; i < 5; i++)							// Testing function call
		list_remove(list, &item_arr[i]);
	for (int i = 0; i < 4; i++) list_remove(list, &array[i]);
	for (int i = 0; i < 4; i++) 
		for (listnode_t *node = list->head; node; node = node->next) if(node->item == &array[i]) result = 0;

	list_destroy(list); 								// Freeing memory
	free(array);
	return result;
}
int test_list_size(int *array) {
	int result = 1;										// Init
	list_t *list = list_create();
	list_inputarr(list, array);

	if (list_addlast(list, allocate_int(41)), list_size(list) != (++size, size--)) result = 0; 	// Testing function call
	if (list_remove(list, &array[2]), list_size(list) != size) result = 0; 						// Testing function call
	if (list_remove(list, allocate_int('s')), list_size(list) != size) result = 0; 				// Testing function call

	list_destroy(list); 								// Freeing memory
	free(array);
	return result;
}

/*
//	Iterator functions
*/

// Create iterator
int test_list_createiterator(int *array) {
	int result = 1;										// Init
	list_t *list = list_create();
	list_inputarr(list, array);

	if (!list_createiterator(list)) result = 0;	 		// Testing function call

	list_destroy(list); 								// Freeing memory
	free(array);
	return result;
}
int test_list_destroyiterator(int *array) {
	int result = 1;										// Init
	list_t *list = list_create();
	list_inputarr(list, array);
	list_iterator_t *iter= list_createiterator(list);

	list_destroyiterator(iter); 						// Testing function call

	list_destroy(list); 								// Freeing memory
	free(array);
	return result;
}
int test_list_resetiterator(int *array) {
	int result = 1;										// Init
	list_t *list = list_create();
	list_inputarr(list, array);
	list_iterator_t *iter= list_createiterator(list);
	(list_next(iter), list_next(iter));

	list_resetiterator(iter); 							// Testing function call
	if (iter->next != list->head) result = 0;

	list_destroy(list); 								// Freeing memory
	free(array);
	return result;
}
int test_list_next(int *array) {
	int result = 1;										// Init
	list_t *list = list_create();
	list_inputarr(list, array);
	list_iterator_t *iter= list_createiterator(list);
	(list_next(iter), list_next(iter));

	if (list_next(iter) != &array[7]) result = 0; 		// Testing function call
	while (list_next(iter));
	if (list_next(iter)) result = 0;

	list_destroy(list); 								// Freeing memory
	free(array);
	return result;
}
