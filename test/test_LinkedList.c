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

void test_List_addFirst_should_add_element_to_first_slot_testing_with_3_elements(){
	LinkedList *list;
	list = createLinkedList();
	
	Element arrayElem[] = {{.next = &arrayElem[1], .data = 1}, 
							{.next = NULL, .data = 2},
							{.next = NULL, .data = 3}};
	list->length = 3;
	list->head = &arrayElem[0];
	list->tail = &arrayElem[(list->length) - 1];

	List_addFirst(list, arrayElem);
	
	TEST_ASSERT_EQUAL_PTR(&arrayElem[3], arrayElem[2].next);
	TEST_ASSERT_EQUAL_PTR(&arrayElem[2], arrayElem[1].next);
	TEST_ASSERT_EQUAL_PTR(&arrayElem[1], arrayElem[0].next);
	TEST_ASSERT_NULL(arrayElem[3].next);
	TEST_ASSERT_EQUAL(3, arrayElem[3].data);
	TEST_ASSERT_EQUAL(2, arrayElem[2].data);
	TEST_ASSERT_EQUAL(1, arrayElem[1].data);
	TEST_ASSERT_EQUAL(5, arrayElem[0].data);
	
}

void test_List_addFirst_should_add_element_to_first_slot_testing_with_2_elements(){
	LinkedList *list;
	list = createLinkedList();
	
	Element arrayElem[] = {{.next = &arrayElem[1], .data = 1}, 
							{.next = NULL, .data = 2}};
	list->length = 2;
	list->head = &arrayElem[0];
	list->tail = &arrayElem[(list->length) - 1];

	List_addFirst(list, arrayElem);
	
	TEST_ASSERT_EQUAL_PTR(&arrayElem[2], arrayElem[1].next);
	TEST_ASSERT_EQUAL_PTR(&arrayElem[1], arrayElem[0].next);
	TEST_ASSERT_NULL(arrayElem[2].next);
	TEST_ASSERT_EQUAL(2, arrayElem[2].data);
	TEST_ASSERT_EQUAL(1, arrayElem[1].data);
	TEST_ASSERT_EQUAL(5, arrayElem[0].data);
	
}

void test_List_addFirst_should_add_element_to_first_slot_testing_with_1_elements(){
	LinkedList *list;
	list = createLinkedList();
	
	Element arrayElem[] = {{.next = NULL, .data = 1}};
	list->length = 1;
	list->head = &arrayElem[0];
	list->tail = &arrayElem[(list->length) - 1];

	List_addFirst(list, arrayElem);
	
	TEST_ASSERT_EQUAL_PTR(&arrayElem[1], arrayElem[0].next);
	TEST_ASSERT_NULL(arrayElem[1].next);
	TEST_ASSERT_EQUAL(1, arrayElem[1].data);
	TEST_ASSERT_EQUAL(5, arrayElem[0].data);
}

void test_List_removeFirst_should_remove_first_element_and_head_to_second_element(){
	LinkedList *list;
	list = createLinkedList();
	
	Element arrayElem[] = {{.next = &arrayElem[1], .data = 1},
							{.next = NULL, .data = 2}};
	
	list->length = 2;
	list->head = &arrayElem[0];
	list->tail = &arrayElem[1];

	List_removeFirst(list);
	TEST_ASSERT_NOT_NULL(list->head);
	TEST_ASSERT_EQUAL(&arrayElem[1],list->head);
	TEST_ASSERT_EQUAL(1, list->length);
	
}






