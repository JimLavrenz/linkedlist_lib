#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist_lib.h"

/* Creates a new list.
*/
list_t *list_new(){
	list_t *list = malloc(sizeof(*list));
	list->head = NULL;
	list->tail = NULL;
	list->count = 0;

	return list;
}	

/* Creates a new node.
*/
node_t *list_create_node(list_t *list, char *string){
	node_t *node = malloc(sizeof(*node));
	node->text = malloc(sizeof(char) * (strlen(string) + 1));
	strcpy(node->text, string);
	node->next = NULL;
	return node;
}

/* Appends a new string to the list.
*/
void list_append(list_t *list, char *string){

	node_t *node = list_create_node(list, string);

	if(list->count == 0){
		list->head = node;
		list->tail = node;
		list->count++;
		return;
	}
	list->tail->next = node;
	list->tail = node;
	list->count++;
}

/* Removes a node from the list.
*/
void list_remove_node(list_t *list, char * string){
	node_t *cur, *prev;
	cur = list->head;
	prev = cur;
	int index = 0;

	if(!list_count(list)){
		printf("List is empty--nothing to remove.\n");
		return;
	}
	while(cur){
		if(!strcmp(cur->text, string)){
			if(!cur->next)//check for tail of list
				list->tail = prev;

			prev->next = cur->next;
			if(index == 0)//check for head of list
				list->head = prev->next;

			free(cur->text);
			free(cur);
			list->count--;
			return;
		}
		prev = cur;
		cur = cur->next;
		index++;
	}
}

/* Prints the list.
*/
void list_print(list_t *list){
	node_t *cur;
	cur = list->head;

	if(!list_count(list)){
		printf("List is empty--nothing to print.\n");
		return;
	}

	while(cur){
		printf("%s\n", cur->text);
		cur=cur->next;
	}
}

/* Returns the index of the list or -1 if not found or if the list is empty.
*/
int list_index(list_t *list, char * string){
	node_t *cur;
	cur = list->head;
	int index = -1;

	if(!list_count(list)){
		printf("List is empty--nothing to index.\n");
		return index;
	}

	while(cur){
		index++;
		if(!strcmp(cur->text, string))
			return index;
		cur = cur->next;
	}
	return index;
}

/* Delete the linked list.
*/
void list_linkedlist_del(list_t *list){
	node_t *cur, *next;
	cur = list->head;

	if(!list_count(list)){
		printf("List is empty--nothing to delete.\n");
		return;
	}

	while(cur){
		free(cur->text);
		next = cur->next;
		free(cur);
		cur = next;
	}
}

/* Deletes the entire list (list plus meta data of list).
*/
void list_del(list_t *list){

	if(!list_count(list)){
		printf("List is empty--nothing to delete.\n");
		return;
	}
	list_linkedlist_del(list);
	free((void *) list);
}

/* Returns the count (number of items in list).
*/
int list_count(list_t *list){
	return list->count;
}