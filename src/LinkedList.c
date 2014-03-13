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
	
	if(list->head == NULL && list-> tail == NULL){
		list->head = elem;
		list->tail = elem;
	}else{
		elem->next = list->head;
		list->head = elem;
	}
	list->length++;
}

Element *List_removeFirst(LinkedList *list){

	Element *address;
	address = list->head;
	
	if(list->head == NULL && list-> tail == NULL){
		return NULL;
	}
	
	if(list->head == list->tail){
		list->head = NULL;
		list->tail = NULL;
	}
	else{
		 list->head = list->head->next;
		 list->tail->next = NULL;
	}
	
	list->length = list->length - 1 ;
	
	return address;
}
