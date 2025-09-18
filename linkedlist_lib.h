#ifndef LINKED_LIST_LIB_H
#define LINKED_LIST_LIB_H

struct node_struct {
	char *text;
	struct node_struct *next;
};

struct list_struct {
	struct node_struct *head;
	struct node_struct *tail;
	int count;
};

typedef struct node_struct node_t;
typedef struct list_struct list_t;

list_t *list_new();
node_t *list_create_node(list_t *list, char *string);
void list_remove_node(list_t *list, char * string);
void list_append(list_t *list, char *string);
void list_print(list_t *list);
int list_index(list_t *list, char * string);
void list_del(list_t *list);
void list_linkedlist_del(list_t *list);
int list_count(list_t *list);

#endif