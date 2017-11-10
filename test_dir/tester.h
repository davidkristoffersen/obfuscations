/*
	Created by: David Krsitoffersen
	Description: Unit tester header for simple implementation of linked list in C
*/

#ifndef TESTER_H
#define TESTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*
 * List functions
 */

int test_list_create(int *array);
int test_list_destroy(int *array);
int test_list_addfirst(int *array);
int test_list_addlast(int *array);
int test_list_remove(int *array);
int test_list_size(int *array);

/*
 * Iterator functions
 */

int test_list_createiterator(int *array);
int test_list_destroyiterator(int *array);
int test_list_resetiterator(int *array);
int test_list_next(int *array);

#endif
