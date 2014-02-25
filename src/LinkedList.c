#include "LinkedList.h"
#include <malloc.h>
#include <stdio.h>

LinkedList *createLinkedList(){
	LinkedList *list = malloc(sizeof(LinkedList));
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	return list;
}

void List_addFirst(LinkedList *list, Element *elem){
	int i = list->length;

	*(list->tail)++;
	list->head = &elem[0];
	elem[i].next = NULL;
	
	for(i; i>=0; i--){
		elem[i-1].next = &elem[i];
		elem[i].data = elem[i-1].data;
	}

	(list->length)++;
	elem[0].data = 5; //user input.
	
}

Element *List_removeFirst(LinkedList *list){
	Element *address;
	
	address = list->head;
	
	if(list->head == list->tail){
		list->head == NULL;
		list->tail == NULL;
	}
	else{
		*(list->head)++;
	}
	
	list->length--;
	
	return address;
}
