#include <stdio.h>
#include <malloc.h>
#include "LinkedList.h"

LinkedList *createLinkedList(){
	LinkedList *list = malloc(sizeof(LinkedList));
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	return list;
}
