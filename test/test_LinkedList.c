#include "unity.h"
#include "LinkedList.h"
#include <malloc.h>

void setUp() {}
void tearDown() {}

void test_createLinkedList_should_return_LinkedList_object(){
	LinkedList *list;
	
	list = createLinkedList();
	TEST_ASSERT_NOT_NULL(list);
	TEST_ASSERT_NULL(list->head);
	TEST_ASSERT_NULL(list->tail);
	TEST_ASSERT_EQUAL(0, list->length);
}

void test_List_addFirst_should_add_element_to_first_slot_testing_with_2_elements(){
	LinkedList *list = createLinkedList();
	
	Element elem = {.next = NULL, .data = 1};
	Element	elem2 = {.next = NULL, .data = 2};
	
	//printf("%p\n",&elem);
	//printf("%p\n",&elem2);
	
	list->length = 1;
	list->head = &elem;
	list->tail = &elem;

	List_addFirst(list, &elem2);
	
	TEST_ASSERT_EQUAL(1, elem.data);
	TEST_ASSERT_EQUAL(2, elem2.data);
	TEST_ASSERT_NULL(elem.next);
	TEST_ASSERT_EQUAL_PTR(list->head, &elem2);
	TEST_ASSERT_EQUAL_PTR(list->tail, &elem);
	TEST_ASSERT_EQUAL_PTR(elem2.next, &elem);
	TEST_ASSERT_EQUAL(2, list->length);
}

void test_List_addFirst_should_add_element_to_first_slot_testing_with_3_elements(){
	LinkedList *list;
	list = createLinkedList();
	
	Element elem = {.next = NULL, .data = 1}; 
	Element elem2 = {.next = &elem, .data = 2};
	Element elem3 = {.next = NULL, .data = 3};
	
	//printf("%p\n",&elem);
	//printf("%p\n",&elem2);
	//printf("%p\n",&elem3);
	
	list->length = 2;
	list->head = &elem2;
	list->tail = &elem;

	List_addFirst(list, &elem3);
	
	TEST_ASSERT_EQUAL(1, elem.data);
	TEST_ASSERT_EQUAL(2, elem2.data);
	TEST_ASSERT_EQUAL(3, elem3.data);
	TEST_ASSERT_NULL(elem.next);
	TEST_ASSERT_EQUAL_PTR(list->head, &elem3);
	TEST_ASSERT_EQUAL_PTR(list->tail, &elem);
	TEST_ASSERT_EQUAL_PTR(elem3.next, &elem2);
	TEST_ASSERT_EQUAL(3, list->length);
}

void test_List_removeFirst_should_remove_head_and_tail_and_return_null(){
	LinkedList *list;
	list = createLinkedList();
	
	list->head = NULL;
	list->tail = NULL;
	
	TEST_ASSERT_NULL(List_removeFirst(list));
}

void test_List_removeFirst_should_remove_first_element_and_head_and_tail_to_null(){
	LinkedList *list;
	list = createLinkedList();
	
	Element arrayElem[] = {{.next = NULL, .data = 1}};
	
	list->length = 1;
	list->head = &arrayElem[0];
	list->tail = &arrayElem[0];
	
	//printf("arrayElem[0].address: %p\n", &arrayElem[0]);

	TEST_ASSERT_EQUAL_PTR(&arrayElem[0], List_removeFirst(list));
	TEST_ASSERT_NULL(list->head);
	TEST_ASSERT_NULL(list->tail);
	TEST_ASSERT_EQUAL(0, list->length);
	
}

void test_List_removeFirst_should_remove_first_element_and_head_to_second_element(){
	LinkedList *list;
	list = createLinkedList();

	Element arrayElem[] = {{.next = &arrayElem[1], .data = 1},
							{.next = NULL, .data = 2}};
	
	list->length = 2;
	list->head = &arrayElem[0];
	list->tail = &arrayElem[1];
	
	//printf("arrayElem[0].address: %p\n", &arrayElem[0]);
	//printf("arrayElem[1].address: %p", &arrayElem[1]);

	TEST_ASSERT_EQUAL_PTR(&arrayElem[0], List_removeFirst(list));
	TEST_ASSERT_EQUAL_PTR(list->head, &arrayElem[1]);
	TEST_ASSERT_EQUAL_PTR(list->tail, &arrayElem[1]);
	TEST_ASSERT_NULL(arrayElem[1].next);
	TEST_ASSERT_EQUAL(1, list->length);
	
}

void test_List_removeFirst_should_remove_first_element_and_head_to_second_element_and_tail_to_third_element(){
	LinkedList *list;
	list = createLinkedList();

	Element arrayElem[] = {{.next = &arrayElem[1], .data = 1},
							{.next = &arrayElem[2], .data = 2},
							{.next = NULL, .data = 3}};
	
	list->length = 3;
	list->head = &arrayElem[0];
	list->tail = &arrayElem[2];
	
	//printf("arrayElem[0].address: %p\n", &arrayElem[0]);
	//printf("arrayElem[1].address: %p", &arrayElem[1]);

	TEST_ASSERT_EQUAL_PTR(&arrayElem[0], List_removeFirst(list));
	TEST_ASSERT_EQUAL_PTR(list->head, &arrayElem[1]);
	TEST_ASSERT_EQUAL_PTR(list->tail, &arrayElem[2]);
	TEST_ASSERT_NULL(arrayElem[2].next);
	TEST_ASSERT_EQUAL(2, list->length);
	
}




