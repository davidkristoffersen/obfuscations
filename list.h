#ifndef LIST_H
#define	LIST_H
#include <stdlib.h>
typedef struct list list_t;
typedef struct list_iterator list_iterator_t;
list_t *list_create(void);
void list_destroy(list_t *list);
void list_addfirst(list_t *list, void *item);
void list_addlast(list_t *list, void *item);
void list_remove(list_t *list, void *item);
int list_size(list_t *list);
list_iterator_t *list_createiterator(list_t *list);
void list_destroyiterator(list_iterator_t *iter);
void *list_next(list_iterator_t *iter);
void list_resetiterator(list_iterator_t *iter);
#endif
