#ifndef LIST_H
#define	LIST_H

typedef struct listnode listnode_t;
struct listnode {
	listnode_t	*next;
	void 		*item;
};

typedef struct list list_t;
struct list {
	listnode_t	*head;
	int			numitems;
};


list_t *list_create(void);
void list_destroy(list_t *list);
void list_addfirst(list_t *list, void *item);
void list_addlast(list_t *list, void *item);
void list_remove(list_t *list, void *item);
int list_size(list_t *list);

typedef struct list_iterator list_iterator_t;
struct list_iterator {
	listnode_t	*next;
	list_t		*list;
};

list_iterator_t *list_createiterator(list_t *list);
void list_destroyiterator(list_iterator_t *iter);
void *list_next(list_iterator_t *iter);
void list_resetiterator(list_iterator_t *iter);
#endif
