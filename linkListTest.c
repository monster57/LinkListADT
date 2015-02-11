typedef char* string;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expr_assert.h"
#include "linkList.h"

void test_createList_create_a_empty_link_list(){
	LinkList new_list;
	new_list = createList();
	assertEqual(((int)new_list.head), 0);
	assertEqual(((int)new_list.tail), 0);
	assertEqual(new_list.numOfElements,0);
}

void test_create_node_create_a_new_node(){
	Node *new_node;
	int a = 10;
	new_node = create_node(&a);
	assert(new_node!=NULL);
	free(new_node);
}
void test_create_node_returns_0_if_data_is_NULL(){
	Node *new_node;
	int a = 0;
	new_node = create_node(&a);
	assert(new_node == NULL);
	free(new_node);
}
void test_create_node_create_a_new_node_with_data_value_15(){
	int a = 15;
	Node *new_node = create_node(&a);
	assertEqual(*(int*)new_node->data, a);
	free(new_node);
}
void test_create_node_create_a_new_node_with_float_data_type(){
	float a = 12.2;
	Node *new_node = create_node(&a);
	assertEqual(*(float*)new_node->data, a);
	free(new_node);
}
void test_create_node_create_a_new_node_with_char_data_type(){
	char a = 'a';
	Node *new_node = create_node(&a);
	assertEqual(*(signed char *)new_node->data, a);
	free(new_node);
}
void test_create_node_create_a_new_node_with_unsigned_char_data_type(){
	unsigned char a = 255;
	Node *new_node = create_node(&a);
	assertEqual(*(unsigned char *)new_node->data, a);
	free(new_node);
}
void test_create_node_create_a_new_node_with_signed_char_data_type(){
	signed char a = 122;
	Node *new_node = create_node(&a);
	assertEqual(*(string)new_node->data, a);
	free(new_node);
}
void test_create_node_create_a_new_node_with_string_data_type(){
	string a = "head";
	Node *new_node = create_node(&a);
	assertEqual(strcmp(*(string *)new_node->data, "head"),0);
	free(new_node);
}
void test_create_node_create_a_new_node_with_a_double_data_type(){
	double a = 22.1;
	Node *new_node = create_node(&a);
	assertEqual(*(double*)new_node->data, a);
	free(new_node);
}
void test_create_node_create_a_new_node_with_a_longint_data_type(){
	long int a = 12345678;
	Node *new_node = create_node(&a);
	assertEqual(*(long int*)new_node->data, a);
	free(new_node);
}
void test_add_to_list_add_an_integer_data_to_a_list(){
	int a= 5;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list, node);
	assertEqual(*(int *)(list.head)->data, 5);
}
void test_add_to_list_add_a_char_data_to_a_list(){
	char a = 'a';
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list,node);
	assertEqual(*(char *)(list.head)->data, 'a');
}
void test_add_to_list_add_a_float_data_to_a_list(){
	float a = 1.2;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list,node);
	assertEqual(*(float *)(list.head)->data, (float)1.2);
}
void test_add_to_list_add_a_string_data_to_a_list(){
	string a = "hiii";
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list,node);
	assertEqual(strcmp(*(string *)(list.head)->data, "hiii"),0);
	free(node);
}
void test_add_to_list_add_a_double_data_to_a_list(){
	double a = 1.2;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list,node);
	assertEqual(*(double *)(list.head)->data, (double)1.2);
	free(node);
}
void test_add_to_list_add_a_long_int_data_to_a_list(){
	long int a = 12345678;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list,node);
	assertEqual(*(long int *)(list.head)->data, (long int)12345678);
	free(node);
}
void test_add_to_list_add_a_signed_char_data_to_a_list(){
	signed char a = 123;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list,node);
	assertEqual(*(signed char *)(list.head)->data, (signed char)123);
	free(node);
}
void test_add_to_list_add_a_unsigned_char_data_to_a_list(){
	unsigned char a = 255;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list,node);
	assertEqual(*(unsigned char *)(list.head)->data, (unsigned char)255);
	free(node);
}
void test_add_to_list_add_two_integer_data__to_a_list(){
	int a=5, b=6;
	LinkList list = createList();
	Node *first_node  = create_node(&a);
	Node *second_node  = create_node(&b);
	add_to_list(&list, first_node);
	assertEqual(*(int *)(list.head)->data, 5);
	add_to_list(&list, second_node);
	assertEqual(*(int *)(list.tail)->data, 6);
	free(first_node);
	free(second_node);
}
void test_add_to_list_add_two_float_data__to_a_list(){
	float a=1.2, b=2.3;
	LinkList list = createList();
	Node *first_node  = create_node(&a);
	Node *second_node  = create_node(&b);
	add_to_list(&list, first_node);
	assertEqual(*(float *)(list.head)->data, (float)1.2);
	add_to_list(&list, second_node);
	assertEqual(*(float *)(list.tail)->data, (float)2.3);
	free(first_node);
	free(second_node);
}
void test_add_to_list_add_two_char_data__to_a_list(){
	char a='a', b='b';
	LinkList list = createList();
	Node *first_node  = create_node(&a);
	Node *second_node  = create_node(&b);
	add_to_list(&list, first_node);
	assertEqual(*(char *)(list.head)->data, 'a');
	add_to_list(&list, second_node);
	assertEqual(*(char *)(list.tail)->data, 'b');
	free(first_node);
	free(second_node);
}
void test_add_to_list_add_two_double_data__to_a_list(){
	double a=2.2, b=3.3;
	LinkList list = createList();
	Node *first_node  = create_node(&a);
	Node *second_node  = create_node(&b);
	add_to_list(&list, first_node);
	assertEqual(*(double *)(list.head)->data, (double)2.2);
	add_to_list(&list, second_node);
	assertEqual(*(double *)(list.tail)->data, (double)3.3);
	free(first_node);
	free(second_node);
}
void test_add_to_list_add_two_signed_char_data__to_a_list(){
	signed char a=122, b=123;
	LinkList list = createList();
	Node *first_node  = create_node(&a);
	Node *second_node  = create_node(&b);
	add_to_list(&list, first_node);
	assertEqual(*(signed char *)(list.head)->data, (signed char)122);
	add_to_list(&list, second_node);
	assertEqual(*(signed char *)(list.tail)->data, (signed char)123);
	free(first_node);
	free(second_node);
}
void test_add_to_list_add_two_unsigned_char_data__to_a_list(){
	unsigned char a = 255, b = 254;
	LinkList list = createList();
	Node *first_node  = create_node(&a);
	Node *second_node  = create_node(&b);
	add_to_list(&list, first_node);
	assertEqual(*(unsigned char *)(list.head)->data, (unsigned char)255);
	add_to_list(&list, second_node);
	assertEqual(*(unsigned char *)(list.tail)->data, (unsigned char)254);
	free(first_node);
	free(second_node);
}
void test_add_to_list_add_two_string_data__to_a_list(){
	string a = "ant" , b = "bat";
	LinkList list = createList();
	Node *first_node  = create_node(&a);
	Node *second_node  = create_node(&b);
	add_to_list(&list, first_node);
	assertEqual(strcmp(*(string  *)(list.head)->data, "ant"),0);
	add_to_list(&list, second_node);
	assertEqual(strcmp(*(string  *)(list.tail)->data, "bat"),0);
	free(first_node);
	free(second_node);
}
void test_add_to_list_add_two_different_data_type_to_the_list(){
	int  a = 12;
	float b = 5.5;
	LinkList list = createList();
	Node *first_node  = create_node(&a);
	Node *second_node  = create_node(&b);
	add_to_list(&list, first_node);
	assertEqual(*(int *)(list.head)->data, 12);
	add_to_list(&list, second_node);
	assertEqual(*(float *)(list.tail)->data, (float)5.5);
	free(first_node);
	free(second_node);
}
void test_add_to_list_add_more_that_two_element_of_integer_type(){
	int a=12, b=13, c = 15;
	LinkList list = createList();
	Node *first_node = create_node(&a);
	Node *second_node = create_node(&b);
	Node *third_node = create_node(&c);
	add_to_list(&list, first_node);
	assertEqual(*(int *)(list.head)->data, 12);
	add_to_list(&list, second_node);
	assertEqual(*(int *)(list.tail)->data, 13);
	add_to_list(&list, third_node);
	assertEqual(*(int *)(list.tail)->data, 15);
	free(first_node);
	free(second_node);
	free(third_node);
}
void test_get_first_element_should_get_the_first_integer_element_from_the_linked_list(){
	int a = 5, *result;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list, node);
	result = get_first_element(list);
	assertEqual(*result, a);
	free(node);
}
void test_get_first_element_should_get_the_first_float_element_from_the_linked_list(){
	float a = 5.2, *result;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list, node);
	result = get_first_element(list);
	assertEqual(*result, a);
	free(node);
}
void test_get_first_element_should_get_the_first_char_element_from_the_linked_list(){
	char a = 'a', *result;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list, node);
	result = get_first_element(list);
	assertEqual(*result, a);
	free(node);
}
void test_get_first_element_should_get_the_first_signed_char_element_from_the_linked_list(){
	signed char a = 123, *result;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list, node);
	result = get_first_element(list);
	assertEqual(*result, a);
	free(node);
}
void test_get_first_element_should_get_the_first_unsigned_char_element_from_the_linked_list(){
	unsigned char a = 255, *result;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list, node);
	result = get_first_element(list);
	assertEqual(*result, a);
	free(node);
}
void test_get_first_element_should_get_the_first_string_element_from_the_linked_list(){
	string a = "hiii", *result;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list, node);
	result = get_first_element(list);
	assertEqual(strcmp(*result, "hiii"),0);	
	free(node);
}
void test_get_first_element_should_get_the_first_double_element_from_the_linked_list(){
	double a = 2.2, *result;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list, node);
	result = get_first_element(list);
	assertEqual((*(double *)result), (double)2.2);
	free(node);	
}
void test_get_first_element_should_get_the_first_lon_int_element_from_the_linked_list(){
	long int a = 123456789, *result;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list, node);
	result = get_first_element(list);
	assertEqual((*(long int *)result), (long int)123456789);
	free(node);	
}
void get_first_element_will_returns_null_if_no_element_in_a_List(){
	int *result;
	LinkList list = createList();
	result = get_first_element(list);
	assertEqual(*(int *)result, 0);
}
void test_get_last_element_should_get_the_last_int_element_from_the_linked_list(){
	int a = 5, *result;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list, node);
	result = get_last_element(list);
	assertEqual(*(int *)result, 5);
	free(node);	
}
void test_get_last_element_should_get_the_last_float_element_from_the_linked_list(){
	float a = 1.2, *result;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list, node);
	result = get_last_element(list);
	assertEqual(*(float *)result, (float)1.2);
	free(node);
}
void test_get_last_element_should_get_the_last_double_element_from_the_linked_list(){
	double a = 1.2, *result;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list, node);
	result = get_last_element(list);
	assertEqual(*(double *)result, (double)1.2);
	free(node);
}
void test_get_last_element_should_get_the_last_char_element_from_the_linked_list(){
	char a = 'a', *result;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list, node);
	result = get_last_element(list);
	assertEqual(*(string)result, a);
	free(node);
}
void test_get_last_element_should_get_the_last_signed_char_element_from_the_linked_list(){
	signed char a = 122, *result;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list, node);
	result = get_last_element(list);
	assertEqual(*(signed char *)result, (signed char)122);
	free(node);
}
void test_get_last_element_should_get_the_last_unsigned_char_element_from_the_linked_list(){
	unsigned char a = 255, *result;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list, node);
	result = get_last_element(list);
	assertEqual(*(unsigned char *)result, (unsigned char)255);
	free(node);
}
void test_get_last_element_should_get_the_last_long_int_element_from_the_linked_list(){
	long int a = 123456789, *result;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list, node);
	result = get_last_element(list);
	assertEqual(*(long int *)result, a);
	free(node);
}
void test_get_last_element_should_get_the_last_string_element_from_the_linked_list(){
	string a = "hello", *result;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list, node);
	result = get_last_element(list);
	assertEqual(strcmp(*result, "hello"),0);
	free(node);		
}
void test_last_element_and_first_element_will_be_same_for_single_node_in_a_link_list(){
	int a = 12, *result1, *result2;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list, node);
	result1 = get_first_element(list);
	result2 = get_last_element(list);
	assertEqual(*(int *)result1, a);	
	assertEqual(*(int *)result2, a);
	free(node);
}
void test_the_last_element_should_get_the_last_element_everytime(){
	int a=1,b=2,c=3, *result;
	LinkList list = createList();
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);
	add_to_list(&list, firstNode);
	result = get_last_element(list);
	assertEqual(*(int*)result, a);
	add_to_list(&list, secondNode);
	result = get_last_element(list);
	assertEqual(*(int*)result, b);
	add_to_list(&list, thirdNode);
	result = get_last_element(list);
	assertEqual(*(int*)result, c);
	free(firstNode);
	free(secondNode);
	free(thirdNode);	
}
void increamentby1(void *data){
	*(int*)data +=1;
}

void test_travarse_increase_each_element_value_by_1_for_1_node_in_a_list(){
	int a=5;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list, node);
	traverse(list, increamentby1);
	assertEqual(*(int*)(*(Node*)(list.head)).data, 6);
	free(node);
}

void increamentby2(void *data){
	*(float *)data +=2;
}

void test_travarse_increase_each_element_value_by_2_for_1_node_in_a_list(){
	float a=2.2;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list, node);
	traverse(list, increamentby2);
	assertEqual(*(float*)(*(Node*)(list.head)).data, (float)4.4);
	free(node);
}

void increamentby3(void *data){
	*(double *)data +=3;
}

void test_travarse_increase_each_element_value_by_3_for_1_node_in_a_list(){
	double a=2.2;
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list, node);
	traverse(list, increamentby3);
	assertEqual(*(double*)(*(Node*)(list.head)).data, (double)5.4);
	free(node);
}

void toUppercase(void *data){
	*(char*)data -=32; 
}
void test_travarse_change_the_lower_case_to_upperCase(){
	char  a='a';
	LinkList list = createList();
	Node *node = create_node(&a);
	add_to_list(&list, node);
	traverse(list, toUppercase);
	assertEqual(*(char*)(*(Node*)(list.head)).data, (char)'A');
	free(node);
}
void test_travarse_change_the_lower_case_to_upperCase_for_all_element(){
	char  a='a' , b='b' , c= 'c';
	LinkList list = createList();
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);

	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);

	traverse(list, toUppercase);
	assertEqual(*(char*)firstNode->data , (char)'A');
	assertEqual(*(char*)secondNode->data, (char)'B');
	assertEqual(*(char*)thirdNode->data, (char)'C');
	free(firstNode);
	free(secondNode);
	free(thirdNode);
}
void test_getElementAt_get_the_element_from_the_link_list_according_to_the_index(){
	int a = 5 , b= 6, c= 7 , result;
	LinkList list = createList();
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);

	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	assertEqual(*(int*)getElementAt(list,1),6);
	free(firstNode);
	free(secondNode);
	free(thirdNode);
}
void test_getElementAt_get_the_second_element_from_a_character_link_list(){
	char a= 'a',  b= 'b', c = 'c';
	LinkList list = createList();
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);

	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	assertEqual(*(char*)getElementAt(list,1),'b');
	free(firstNode);
	free(secondNode);
	free(thirdNode);
}
void test_getElementAt_get_the_second_element_from_the_float_list(){
	float a= 1.1,  b= 2.2, c = 3.3;
	LinkList list = createList();
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);

	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	assertEqual(*(float *)getElementAt(list,1),(float)2.2);	
	free(firstNode);
	free(secondNode);
	free(thirdNode);
}
void test_getElementAt_get_the_second_element_from_the_double_list(){
	double a= 1.1,  b= 2.2, c = 3.3;
	LinkList list = createList();
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);

	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	assertEqual(*(double *)getElementAt(list,1),(double)2.2);	
	free(firstNode);
	free(secondNode);
	free(thirdNode);
}
void test_getElementAt_get_the_second_element_from_the_unsigned_char_list(){
	unsigned char  a= 255,  b= 254, c = 253;
	LinkList list = createList();
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);

	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	assertEqual(*(unsigned char*)getElementAt(list,1),(unsigned char)254);	
	free(firstNode);
	free(secondNode);
	free(thirdNode);
}
void test_getElementAt_get_the_second_element_from_the_signed_char_list(){
	signed char  a= 100,  b= 101, c = 102;
	LinkList list = createList();
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);

	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	assertEqual(*(signed char*)getElementAt(list,1),(signed char)101);	
	free(firstNode);
	free(secondNode);
	free(thirdNode);
}
void test_getElementAt_get_the_second_element_from_the_string_list(){
	string  a="hii",  b= "hello", c = "bye";
	LinkList list = createList();
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);

	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	assertEqual(strcmp(*(string*)getElementAt(list,1),"hello"),0);	
	free(firstNode);
	free(secondNode);
	free(thirdNode);
}
void test_indexOf_returns_the_index_from_an_integer_linkList_for_given_element(){
	int  a= 1,  b= 2, c = 3;
	LinkList list = createList();
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);
	int element = 1;

	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	assertEqual(indexOf(list,&element),0);	
	free(firstNode);
	free(secondNode);
	free(thirdNode);
}
void test_indexOf_returns_the_index_from_an_float_linkLink_for_given_element(){
	float  a= 1.4,  b= 2.5, c = 3.6;
	float element = 2.5;
	LinkList list = createList();
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);
	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	assertEqual(indexOf(list,&element),1);		
	free(firstNode);
	free(secondNode);
	free(thirdNode);
}

void test_indexOf_returns_the_index_from_an_character_linklist_for_given_element(){
	char  a= 'a',  b='b', c = 'c';
	char element = 'c';
	LinkList list = createList();
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);
	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	assertEqual(indexOf(list,&element),2);
	free(firstNode);
	free(secondNode);
	free(thirdNode);			
}

void test_indexOf_returns_the_index_from_an_double_linklist_for_given_element(){
	double  a= 2.1,  b=3.4, c = 6.4;
	double element = 3.4;
	LinkList list = createList();
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);
	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	assertEqual(indexOf(list, &element),1);
	free(firstNode);
	free(secondNode);
	free(thirdNode);				
}

void test_indexOf_returns_the_index_from_an_signed_char_linklist_for_given_element(){
	signed char  a= 100,  b=101, c = 102;
	signed char element = 101;
	LinkList list = createList();
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);
	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	assertEqual(indexOf(list, &element),1);
	free(firstNode);
	free(secondNode);
	free(thirdNode);	
}

void test_indexOf_returns_the_index_from_an_unsigned_char_linklist_for_given_element(){
	unsigned char  a= 255,  b=254, c = 253;
	unsigned char element = 253;
	LinkList list = createList();
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);
	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	assertEqual(indexOf(list, &element),2);
	free(firstNode);
	free(secondNode);
	free(thirdNode);	
}

void test_indexOf_returns_the_index_from_an_long_int_linklist_for_given_element(){
	long int  a= 123456789,  b=123456788, c = 123456787;
	long int element = 123456789;
	LinkList list = createList();
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);
	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	assertEqual(indexOf(list, &element),0);
	free(firstNode);
	free(secondNode);
	free(thirdNode);		
}
void test_indexOf_returns_the_index_from_an_string_linklist_for_given_element(){
	string  a= "hello",  b="hiiii", c = "bye";
	string element = "bye";
	LinkList list = createList();
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);
	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	assertEqual(indexOf(list, &element),2);
	free(firstNode);
	free(secondNode);
	free(thirdNode);	
}
void test_deleteElement_delete_an_element(){
	int removed_element;
	int a=2, b=4, c=6 , index = 1;
	LinkList list  = createList();
	Node *firstNode = create_node(&a);
	Node *secondNode  = create_node(&b);
	Node *thirdNode = create_node(&c);

	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);

	assertEqual(list.numOfElements, 3);	
	removed_element= *(int*)deleteElementAt(&list,index); 
	assertEqual(list.numOfElements, 2);
	free(firstNode);
	free(secondNode);
	free(thirdNode);	
}
void test_deleteElement_returns_the_deleted_value(){
	int removed_element;
	int a=2, b=4, c=6 , index = 1;
	LinkList list  = createList();
	Node *firstNode = create_node(&a);
	Node *secondNode  = create_node(&b);
	Node *thirdNode = create_node(&c);

	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);

	removed_element= *(int*)deleteElementAt(&list,index); 
	assertEqual(removed_element, 4);
	free(firstNode);
	free(secondNode);
	free(thirdNode);		
}

void test_deleteElement_returns_0_when_a_list_has_one_node(){
	void * removed_element;
	int a=2, index = 0;
	LinkList list  = createList();
	Node *firstNode = create_node(&a);
	removed_element= deleteElementAt(&list,index); 
	assertEqual((int)list.head, 0);
	free(firstNode);
}
void test_deleteElement_should_returns_null_if_index_is_wrong(){
	void * removed_element;
	int a=2, index = 5;
	LinkList list  = createList();
	Node *firstNode = create_node(&a);
	removed_element= deleteElementAt(&list,index); 
	assertEqual((int)removed_element, 0);
	free(firstNode);	
}
void test_deleteElement_should_return_null_if_linklist_is_empty(){
	void * removed_element;
	int index = 0;
	LinkList list  = createList();
	removed_element= deleteElementAt(&list,index); 
	assertEqual((int)removed_element, 0);
}
void test_deleteElement_delete_the_first_element_and_head_should_be_change(){
	void * removed_element;
	int a=2, b=4, c=6 , index = 0;
	LinkList list  = createList();
	Node *firstNode = create_node(&a);
	Node *secondNode  = create_node(&b);
	Node *thirdNode = create_node(&c);

	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	assertEqual(*(int*)list.head->data, 2);
	removed_element= deleteElementAt(&list,index); 
	assertEqual(*(int*)list.head->data, 4);
	free(firstNode);
	free(secondNode);
	free(thirdNode);			
}
void test_deleteElement_delete_the_last_element_and_tail_should_be_changed(){
	void * removed_element;
	int a=2, b=4, c=6 , index = 2;
	LinkList list  = createList();
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);
	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	assertEqual(*(int*)(list.tail->data), 6);
	removed_element= deleteElementAt(&list,index); 
	assertEqual(*(int*)(list.tail->data), 4);
	free(firstNode);
	free(secondNode);
	free(thirdNode);				
}

void test_asArray_should_create_an_array_of_length_same_as_the_number_of_node_in_the_list(){
	LinkList list = createList();
	int a=2,b=3,c=4 , count;
	void **array;
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);
	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	array = malloc(list.numOfElements*sizeof(int*));
	count = asArray(list,array);
	assertEqual(count, 3);
	assertEqual(*(int*)array[0],2);
	free(array);
	free(firstNode);
	free(secondNode);
	free(thirdNode);					
}

void test_asArray_should_create_an_array_of_integer_type(){
	LinkList list = createList();
	int a=2,b=3,c=4 , count;
	void **array;
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);
	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	array = malloc(list.numOfElements*sizeof(int*));
	count = asArray(list,array);
	assertEqual(*(int*)array[0],2);
	assertEqual(*(int*)array[1],3);
	assertEqual(*(int*)array[2],4);
	free(array);
	free(firstNode);
	free(secondNode);
	free(thirdNode);					
}

void test_asArray_should_create_an_array_of_float_type(){
	LinkList list = createList();
	float a=2.3,b=3.4,c=4.5 ;
	int count;
	void **array;
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);
	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	array = malloc(list.numOfElements*sizeof(float*));
	count = asArray(list,array);
	assertEqual(*(float*)array[0],(float)2.3);
	assertEqual(*(float*)array[1],(float)3.4);
	assertEqual(*(float*)array[2],(float)4.5);
	free(array);
	free(firstNode);
	free(secondNode);
	free(thirdNode);					
}
void test_asArray_should_create_an_array_of_char_type(){
	LinkList list = createList();
	char a='a',b='b',c='c';
	int count;
	void **array;
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);
	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	array = malloc(list.numOfElements*sizeof(char*));
	count = asArray(list,array);
	assertEqual(*(char*)array[0],'a');
	assertEqual(*(char*)array[1],'b');
	assertEqual(*(char*)array[2],'c');
	free(array);
	free(firstNode);
	free(secondNode);
	free(thirdNode);					
}
void test_asArray_should_create_an_array_of_signed_char_type(){
	LinkList list = createList();
	signed char a=100,b=101,c=102;
	int count;
	void **array;
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);
	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	array = malloc(list.numOfElements*sizeof(signed char*));
	count = asArray(list,array);
	assertEqual(*(signed char*)array[0],(signed char)100);
	assertEqual(*(signed char*)array[1],(signed char)101);
	assertEqual(*(signed char*)array[2],(signed char)102);
	free(array);
	free(firstNode);
	free(secondNode);
	free(thirdNode);					
}
void test_asArray_should_create_an_array_of_unsigned_char_type(){
	LinkList list = createList();
	unsigned char a=255,b=254,c=253 ;
	unsigned char count;
	void **array;
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);
	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	array = malloc(list.numOfElements*sizeof(unsigned char*));
	count = asArray(list,array);
	assertEqual(*(unsigned char*)array[0],(unsigned char)255);
	assertEqual(*(unsigned char*)array[1],(unsigned char)254);
	assertEqual(*(unsigned char*)array[2],(unsigned char)253);
	free(array);
	free(firstNode);
	free(secondNode);
	free(thirdNode);					
}

void test_asArray_should_create_an_array_of_double_type(){
	LinkList list = createList();
	double a=2.4,b=3.6,c=4.8;
	int count;
	void **array;
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);
	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	array = malloc(list.numOfElements*sizeof(double*));
	count = asArray(list,array);
	assertEqual(*(double*)array[0],(double)2.4);
	assertEqual(*(double*)array[1],(double)3.6);
	assertEqual(*(double*)array[2],(double)4.8);
	free(array);
	free(firstNode);
	free(secondNode);
	free(thirdNode);					
}
void test_asArray_should_create_an_array_of_long_int_type(){
	LinkList list = createList();
	long int a=123456789,b=123456788,c=123456787;
	int count;
	void **array;
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);
	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	array = malloc(list.numOfElements*sizeof(long int*));
	count = asArray(list,array);
	assertEqual(*(long int*)array[0],123456789);
	assertEqual(*(long int*)array[1],123456788);
	assertEqual(*(long int*)array[2],123456787);
	free(array);
	free(firstNode);
	free(secondNode);
	free(thirdNode);					
}

void test_asArray_should_pass_the_list_head_to_first_index(){
	LinkList list = createList();
	int a=2,b=3,c=4 , count;
	void **array;
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);
	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	array = malloc(list.numOfElements*sizeof(int*));
	count = asArray(list,array);
	assertEqual(*(int*)list.head->data, 2);
	assertEqual(*(int*)array[0],2);
	free(array);
	free(firstNode);
	free(secondNode);
	free(thirdNode);						
}

void test_asArray_should_pass_the_list_tail_to_last_index(){
	LinkList list = createList();
	int a=2,b=3,c=4 , count;
	void **array;
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);
	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	array = malloc(list.numOfElements*sizeof(int*));
	count = asArray(list,array);
	assertEqual(*(int*)list.tail->data, 4);
	assertEqual(*(int*)array[2],4);
	free(array);
	free(firstNode);
	free(secondNode);
	free(thirdNode);						
}

void test_asArray_should_return_NULL_for_empty_list(){
	LinkList list = createList();
	void **array;
	int count;
	array = malloc(list.numOfElements*sizeof(int*));
	count = asArray(list,array);
	assertEqual(count, 0);
}

void test_asArray_should_give_the_length_same_as_the_no_of_element_of_the_link_list(){
	LinkList list = createList();
	int a=2,b=3,c=4 , count;
	void **array;
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);
	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	array = malloc(list.numOfElements*sizeof(int*));
	count = asArray(list,array);
	assertEqual(count, list.numOfElements);
	free(array);
	free(firstNode);
	free(secondNode);
	free(thirdNode);							
}
int greaterThan5(void *data){
	return *(char*)data>5;
}
void test_filter_should_give_all_the_elements_which_are_graeter_than_5(){
	LinkList list = createList();
	LinkList *filtered_list;
	int a=4,b=5,c=6, d=7;
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);
	Node *fourthNode = create_node(&d);

	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	add_to_list(&list, fourthNode);
	filtered_list = filter(list,  greaterThan5);
	assertEqual(*((int *)getElementAt(*filtered_list,0)),6);
	assertEqual(*((int *)getElementAt(*filtered_list,1)),7);
}

void test_filter_should_give_null_for_false_condition(){
	LinkList list = createList();
	LinkList *filtered_list;
	int a=4,b=5,c=3, d=2;
	Node *firstNode = create_node(&a);
	Node *secondNode = create_node(&b);
	Node *thirdNode = create_node(&c);
	Node *fourthNode = create_node(&d);

	add_to_list(&list, firstNode);
	add_to_list(&list, secondNode);
	add_to_list(&list, thirdNode);
	add_to_list(&list, fourthNode);
	filtered_list = filter(list,  greaterThan5);
	assertEqual(list.numOfElements,4);
	assertEqual(filtered_list->numOfElements,0);
}