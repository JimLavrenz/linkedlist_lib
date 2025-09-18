#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist_lib.h"

int main(){

	list_t *list = list_new();
	list_append(list, "Test_1");
	list_append(list, "Test_2");
	list_append(list, "Test_3");
	list_append(list, "Test_4");

	list_print(list);
	printf("List count = %d\n", list_count(list));
	
    printf("index = %d\n", list_index(list, "Test_2") );
    list_remove_node(list, "Test_1");
 	printf("List count = %d\n", list_count(list));
	list_print(list);   

    printf("Head text is: %s\n", list->head->text);
    printf("Tail text is: %s\n", list->tail->text);
    
    list_del(list);
}