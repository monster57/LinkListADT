#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include "expr_assert.h"
#include "linkList.h"


#define log(test_description) int log = printf("\t  ==>%s\n\n", test_description)
#define string char*
int number;
void *data = &number;
Node_ptr new_node,new_node2;
LinkedList list;
LinkedList_ptr list_ptr;
void test_create_node_creates_a_node_that_returns_the_address_of_the_node_for_int_type(){
	number = 10;
	new_node = create_node(data);
	assert(new_node!=NULL);
	free(new_node);
}

void test_create_node_create_a_new_node_that_intializes_data_of_int_type(){
	number = 10;
	new_node = create_node(data);
	assertEqual(*(int*)new_node->data, number);
	free(new_node);
}

void test_create_node_creates_a_new_node_that_initializes_next_to_null_of_int_type(){
	number = 10;
	new_node = create_node(data);
	assertEqual((int)new_node->next, 0);
	free(new_node);
}

void test_createList_creates_an_empty_link_list(){
	list = createList();
	assertEqual((int)list.head, 0);
	assertEqual((int)list.tail, 0);
	assertEqual(list.count, 0);
}

void test_add_to_list_return_1_for_adding_a_node_to_a_list(){
	list_ptr = &list;
	number = 10;
	new_node = create_node(data);
	list = createList();
	assertEqual(add_to_list(list_ptr, new_node), 1);
	free(new_node);
}


void test_add_to_list_should_increments_count_to_1_if_node_added_to_Linked_List(){
	list_ptr = &list;
	number = 10;
	new_node = create_node(data);
	new_node2 = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	assertEqual(list.count, 1);
	add_to_list(list_ptr, new_node2);
	assertEqual(list.count, 2);
	free(new_node);
	free(new_node2);
} 
void test_add_to_list_should_set_head_as_address_of_first_node(){
	list_ptr = &list;
	number = 10;
	new_node = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	assert(new_node==list.head);
	free(new_node);
}

void test_add_to_list_should_set_tail_as_address_of_last_node(){
	list_ptr = &list;
	number = 10;
	new_node = create_node(data);
	new_node2 = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	add_to_list(list_ptr, new_node2);
	assert(new_node2==list.tail);
	free(new_node);
}

void test_get_first_element_should_return_head_of_given_linked_list(){
	list_ptr = &list;
	number = 10;
	new_node = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	assert((Node_ptr)get_first_element(list)==list.head);
	free(new_node);
}

void test_get_last_element_should_return_tail_of_given_linked_list_if_head_and_tail_are_same(){
	list_ptr = &list;
	number = 10;
	new_node = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	assert((Node_ptr)get_first_element(list)==list.tail);
	free(new_node);
}

void test_get_last_element_should_return_tail_of_given_linked_list_if_head_and_tail_are_different(){
	list_ptr = &list;
	number = 10;
	new_node = create_node(data);
	new_node2 = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	add_to_list(list_ptr, new_node2);
	assert((Node_ptr)get_last_element(list)==list.tail);
	free(new_node);
	free(new_node2);
}

void increment(void* data){
	*(int*)data += 1;
}

void test_traverse_should_increment_all_list_elements_by_1_with_increment_function_in_INT(){
	int a = 10, b = 20, c = 30;
	Node_ptr new_node3;
	list_ptr = &list;
	data = &a;
	new_node = create_node(data);
	data = &b;
	new_node2 = create_node(data);
	data = &c;
	new_node3 = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	add_to_list(list_ptr, new_node2);
	add_to_list(list_ptr, new_node3);
	traverse(list,increment);
	assertEqual(*(int*)new_node->data, 11);
	assertEqual(*(int*)new_node2->data, 21);
	assertEqual(*(int*)new_node3->data, 31);
	free(new_node);
	free(new_node2);
	free(new_node3);
}

void myToUpper(void* data){
	*(char*)data = (char)toupper(*(char*)data);
}

void test_traverse_should_convert_all_list_chars_in_upperCase_with_myToUpper_function_in_CHAR(){
	char a = 'a', b = 'b', c = 'c';
	Node_ptr new_node3;
	list_ptr = &list;
	data = &a;
	new_node = create_node(data);
	data = &b;
	new_node2 = create_node(data);
	data = &c;
	new_node3 = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	add_to_list(list_ptr, new_node2);
	add_to_list(list_ptr, new_node3);
	traverse(list,myToUpper);
	assertEqual(*(char*)new_node->data, 'A');
	assertEqual(*(char*)new_node2->data, 'B');
	assertEqual(*(char*)new_node3->data, 'C');
	free(new_node);
	free(new_node2);
	free(new_node3);
}

void myCeil(void* data){
	*(float*)data = (float)ceil(*(float*)data);
}

void test_traverse_should_convert_all_list_float_in_their_Ceil_value_with_myCeil_function_in_FLOAT(){
	float a = 1.54, b = 0.012, c = 99.9;
	Node_ptr new_node3;
	list_ptr = &list;
	data = &a;
	new_node = create_node(data);
	data = &b;
	new_node2 = create_node(data);
	data = &c;
	new_node3 = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	add_to_list(list_ptr, new_node2);
	add_to_list(list_ptr, new_node3);
	traverse(list,myCeil);
	assertEqual(*(float*)new_node->data, 2.000000);
	assertEqual(*(float*)new_node2->data, 1.000000);
	assertEqual(*(float*)new_node3->data, 100.000000);
	free(new_node);
	free(new_node2);
	free(new_node3);
}

void myFloor(void* data){
	*(double*)data = (double)floor(*(double*)data);
}

void test_traverse_should_convert_all_list_double_in_their_floor_value_with_myFloor_function_in_DOUBLE(){
	double a = 1.54, b = 0.012, c = 99.9;
	Node_ptr new_node3;
	list_ptr = &list;
	data = &a;
	new_node = create_node(data);
	data = &b;
	new_node2 = create_node(data);
	data = &c;
	new_node3 = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	add_to_list(list_ptr, new_node2);
	add_to_list(list_ptr, new_node3);
	traverse(list,myFloor);
	assertEqual(*(double*)new_node->data, 1.000000);
	assertEqual(*(double*)new_node2->data, 0.000000);
	assertEqual(*(double*)new_node3->data, 99.000000);
	free(new_node);
	free(new_node2);
	free(new_node3);
}

void stringToUpper(void* data){
	int i, length = strlen(data);
	for(i=0; i < length; i++){
		((char*)data)[i] = (char)toupper(((char*)data)[i]);
	}
}

void test_traverse_should_convert_string_to_upperCase_with_stringToUpper_function_for_STRING(){
	char a[] = "Jungle Jungle baat chali hai";
	char expected[] = "JUNGLE JUNGLE BAAT CHALI HAI";
	list_ptr = &list;
	data = a;
	new_node = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	traverse(list,stringToUpper);
	assertEqual(strcmp((char*)new_node->data,expected),0);
	free(new_node);
}

void test_getElementAt_should_return_NULL_if_given_index_is_not_exist_in_list_of_INT(){
	list_ptr = &list;
	number = 10;
	new_node = create_node(data);
	new_node2 = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	add_to_list(list_ptr, new_node2);
	assert(getElementAt(list,3)==NULL);
	free(new_node);
	free(new_node2);
}

void test_getElementAt_should_return_element_on_the_given_index_in_list_of_CHAR(){
	char a = 'a', b = 'b', c = 'c';
	Node_ptr new_node3;
	list_ptr = &list;
	data = &a;
	new_node = create_node(data);
	data = &b;
	new_node2 = create_node(data);
	data = &c;
	new_node3 = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	add_to_list(list_ptr, new_node2);
	add_to_list(list_ptr, new_node3);
	assert(*(char*)getElementAt(list,0)==a);
	assert(*(char*)getElementAt(list,1)==b);
	assert(*(char*)getElementAt(list,2)==c);
	free(new_node);
	free(new_node2);
	free(new_node3);
}

void test_indexOf_should_return_minus_1_if_given_element_is_not_found_in_list(){
	int num = 12;
	list_ptr = &list;
	number = 10;
	new_node = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	assertEqual(indexOf(list,&num),-1);
	free(new_node);
}

void test_indexOf_should_return_index_of_given_element_if_found_in_list_of_INT(){
	list_ptr = &list;
	number = 10;
	new_node = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	assertEqual(indexOf(list,data),0);
	free(new_node);
}

void test_indexOf_should_return_index_of_given_element_if_found_in_list_of_CHAR(){
	char a = 'a', b = 'b', c = 'c',d = 'd';
	Node_ptr new_node3;
	list_ptr = &list;
	data = &a;
	new_node = create_node(data);
	data = &b;
	new_node2 = create_node(data);
	data = &c;
	new_node3 = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	add_to_list(list_ptr, new_node2);
	add_to_list(list_ptr, new_node3);
	assertEqual(indexOf(list,&a),0);
	assertEqual(indexOf(list,&b),1);
	assertEqual(indexOf(list,&c),2);
	assertEqual(indexOf(list,&d),-1);
	free(new_node);
	free(new_node2);
	free(new_node3);
}


// void test_createList_001() {
// 	log("create list creates a blank list");
// 	LinkedList list = createList(),tmp = {0,0,0};
// 	assertEqual(list.head,tmp.head);
// 	assertEqual(list.count,tmp.count);
// 	assertEqual(list.tail,tmp.tail);
// }

// void test_create_node_001() {
// 	log("create_node creates a node with given integer");
// 	int c = 9;
// 	Node *intNode = create_node(&c);
// 	assertEqual(*(int *)((*intNode).data),9);
// 	assertEqual((*intNode).next,0);
// }

// void test_create_node_002() {
// 	log("create_node creates a node with given character");
// 	char c = 'A';
// 	Node *intNode = create_node(&c);
// 	assertEqual(*(char *)((*intNode).data),'A');
// 	assertEqual((*intNode).next,0);
// }

// void test_create_node_003() {
// 	log("create_node creates a node with given string");
// 	string c = "Prasenjit";
// 	Node *intNode = create_node(&c);
// 	assertEqual(*(string *)((*intNode).data),"Prasenjit");
// 	assertEqual((*intNode).next,0);
// }

// void test_create_node_004() {
// 	log("create_node creates a node with given float");
// 	float c = 19.2;
// 	Node *intNode = create_node(&c);
// 	assertEqual(*(float *)((*intNode).data),19.2);
// 	assertEqual((*intNode).next,0);
// }

// void test_create_node_005() {
// 	log("create_node creates a node with given double");
// 	double c = 19.2;
// 	Node *intNode = create_node(&c);
// 	assertEqual(*(double *)((*intNode).data),19.2);
// 	assertEqual((*intNode).next,0);
// }

// void test_create_node_006() {
// 	log("create_node creates a node with given longint");
// 	long int c = 2147483647;
// 	Node *intNode = create_node(&c);
// 	assertEqual(*(long int *)((*intNode).data),2147483647);
// 	assertEqual((*intNode).next,0);
// }

// void test_create_node_007() {
// 	log("create_node creates a node with given signed char");
// 	signed char c = 127;
// 	Node *intNode = create_node(&c);
// 	assertEqual(*(signed char *)((*intNode).data),127);
// 	assertEqual((*intNode).next,0);
// }

// void test_create_node_008() {
// 	log("create_node creates a node with given unsigned char");
// 	unsigned char c = 255;
// 	Node *intNode = create_node(&c);
// 	assertEqual(*(unsigned char *)((*intNode).data),255);
// 	assertEqual((*intNode).next,0);
// }

// void test_add_to_list_001() {
// 	log("adds an integer data element to the empty linklist");
// 	int c = 9;
// 	LinkedList list = createList();
// 	Node *intNode = create_node(&c);
// 	add_to_list(&list,intNode);
// 	assertEqual(*(int *)(*(list.head)).data,9);
// }

// void test_add_to_list_002() {
// 	log("adds an integer data element to the existing linklist");
// 	int c = 9,d = 10;
// 	LinkedList list = createList();
// 	Node *node1 = create_node(&c),*node2 = create_node(&d);
// 	add_to_list(&list,node1);
// 	add_to_list(&list,node2);
// 	assertEqual(*(int *)(*(list.head)).data,9);
// 	assertEqual(*(int *)(*(list.tail)).data,10);
// }

// void test_add_to_list_003() {
// 	log("adds an integer data element to the empty character linklist");
// 	char c = 'A';
// 	LinkedList list = createList();
// 	Node *charNode = create_node(&c);
// 	add_to_list(&list,charNode);
// 	assertEqual(*(char *)(*(list.head)).data,'A');
// }

// void test_add_to_list_004() {
// 	log("adds a character data element to the existing character linklist");
// 	char c = 'A',d = 'B';
// 	LinkedList list = createList();
// 	Node *node1 = create_node(&c),*node2 = create_node(&d);
// 	add_to_list(&list,node1);
// 	add_to_list(&list,node2);
// 	assertEqual(*(char *)(*(list.head)).data,'A');
// 	assertEqual(*(char *)(*(list.tail)).data,'B');
// }

// void test_add_to_list_005() {
// 	log("adds a string data element to the empty linklist for strings");
// 	string c = "Prasenjit";
// 	LinkedList list = createList();
// 	Node *charNode = create_node(&c);
// 	add_to_list(&list,charNode);
// 	assertEqual(*(string *)(*(list.head)).data,"Prasenjit");
// 	assertEqual(*(string *)(*(list.tail)).data,"Prasenjit");
// }

// void test_add_to_list_006() {
// 	log("adds a string data element to the existing linklist for string");
// 	string c = "Prasenjit",d = "Chakraborty";
// 	LinkedList list = createList();
// 	Node *node1 = create_node(&c),*node2 = create_node(&d);
// 	add_to_list(&list,node1);
// 	add_to_list(&list,node2);
// 	assertEqual(*(string *)(*(list.head)).data,"Prasenjit");
// 	// assertEqual(*(string *)(*(list.tail)).data,"Chakraborty"); Checkpoint
// }

// void test_add_to_list_007() {
// 	log("adds a float data element to the empty linklist for floats");
// 	float c = 72.3;
// 	LinkedList list = createList();
// 	Node *charNode = create_node(&c);
// 	add_to_list(&list,charNode);
// 	assertEqual(*(float *)(*(list.head)).data,72.3);
// 	assertEqual(*(float *)(*(list.tail)).data,72.3);
// }

// void test_add_to_list_008() {
// 	log("adds a float data element to the existing float linklist");
// 	float c = 72.3,d = 65.3;
// 	LinkedList list = createList();
// 	Node *node1 = create_node(&c),*node2 = create_node(&d);
// 	add_to_list(&list,node1);
// 	add_to_list(&list,node2);
// 	assertEqual(*(float *)(*(list.head)).data,72.3);
// 	assertEqual(*(float *)(*(list.tail)).data,65.3);
// }

// void test_add_to_list_009() {
// 	log("adds a long int data element to the empty linklist for long ints");
// 	long int c = 2147483647;
// 	LinkedList list = createList();
// 	Node *charNode = create_node(&c);
// 	add_to_list(&list,charNode);
// 	assertEqual(*(long int *)(*(list.head)).data,2147483647);
// 	assertEqual(*(long int *)(*(list.tail)).data,2147483647);
// }

// void test_add_to_list_010() {
// 	log("adds a long int data element to the existing long int linklist");
// 	long int c = 2147483647,d = 2147483646;
// 	LinkedList list = createList();
// 	Node *node1 = create_node(&c),*node2 = create_node(&d);
// 	add_to_list(&list,node1);
// 	add_to_list(&list,node2);
// 	assertEqual(*(long int *)(*(list.head)).data,2147483647);
// 	assertEqual(*(long int *)(*(list.tail)).data,2147483646);
// }

// void test_add_to_list_0011() {
// 	log("adds a double data element to the empty linklist for doubles");
// 	double c = 21.1;
// 	LinkedList list = createList();
// 	Node *charNode = create_node(&c);
// 	add_to_list(&list,charNode);
// 	assertEqual(*(double *)(*(list.head)).data,21.1);
// 	assertEqual(*(double *)(*(list.tail)).data,21.1);
// }

// void test_add_to_list_012() {
// 	log("adds a double data element to the existing double linklist");
// 	double c = 21.1,d = 21.2;
// 	LinkedList list = createList();
// 	Node *node1 = create_node(&c),*node2 = create_node(&d);
// 	add_to_list(&list,node1);
// 	add_to_list(&list,node2);
// 	assertEqual(*(double *)(*(list.head)).data,21.1);
// 	assertEqual(*(double *)(*(list.tail)).data,21.2);
// }

// void test_get_first_element_001() {
// 	log("gives the first element of the link list for integer");
// 	int c = 9,*res;
// 	LinkedList list = createList();
// 	Node *intNode = create_node(&c);
// 	add_to_list(&list,intNode);
// 	res = get_first_element(list);
// 	assertEqual(*res, 9);
// }

// void test_get_first_element_002() {
// 	log("gives the first element of the link list for float");
// 	float c = 9.2,*res;
// 	LinkedList list = createList();
// 	Node *intNode = create_node(&c);
// 	add_to_list(&list,intNode);
// 	res = get_first_element(list);
// 	assertEqual(*res, 9.2);
// }

// void test_get_first_element_003() {
// 	log("gives the first element of the link list for char");
// 	char c = 'A',*res;
// 	LinkedList list = createList();
// 	Node *intNode = create_node(&c);
// 	add_to_list(&list,intNode);
// 	res = get_first_element(list);
// 	assertEqual(*res, 'A');
// }

// void test_get_first_element_004() {
// 	log("gives the first element of the link list for string");
// 	string c = "Prasenjit",*res;
// 	LinkedList list = createList();
// 	Node *intNode = create_node(c);
// 	add_to_list(&list,intNode);
// 	res = get_first_element(list);
// 	assertEqual(res, "Prasenjit");
// }

// void test_get_first_element_005() {
// 	log("gives the first element of the link list for double");
// 	double c = 19.2,*res;
// 	LinkedList list = createList();
// 	Node *intNode = create_node(&c);
// 	add_to_list(&list,intNode);
// 	res = get_first_element(list);
// 	assertEqual(*res,19.2);
// }

// void test_get_first_element_006() {
// 	log("gives the first element of the link list for long int");
// 	long int c = 2147483647,*res;
// 	LinkedList list = createList();
// 	Node *intNode = create_node(&c);
// 	add_to_list(&list,intNode);
// 	res = get_first_element(list);
// 	assertEqual(*res,2147483647);
// }

// void test_get_first_element_007() {
// 	log("gives the first element of the link list for signed char");
// 	signed char c = 127,*res;
// 	LinkedList list = createList();
// 	Node *intNode = create_node(&c);
// 	add_to_list(&list,intNode);
// 	res = get_first_element(list);
// 	assertEqual(*res,127);
// }

// void test_get_first_element_008() {
// 	log("gives the first element of the link list for unsigned char");
// 	unsigned char c = 255,*res;
// 	LinkedList list = createList();
// 	Node *intNode = create_node(&c);
// 	add_to_list(&list,intNode);
// 	res = get_first_element(list);
// 	assertEqual(*res,255);
// }

// void test_get_first_element_009() {
// 	log("gives the first element of the link list for unsigned int");
// 	unsigned int c =  4294967295,*res;
// 	LinkedList list = createList();
// 	Node *intNode = create_node(&c);
// 	add_to_list(&list,intNode);
// 	res = get_first_element(list);
// 	assertEqual(*res, 4294967295);
// }

// void test_get_first_element_010() {
// 	log("gives the first element of the link list for short int");
// 	short int c =  32767,*res;
// 	LinkedList list = createList();
// 	Node *intNode = create_node(&c);
// 	add_to_list(&list,intNode);
// 	res = get_first_element(list);
// 	assertEqual(*res, 32767);
// }

// void test_get_last_element_001() {
// 	log("gives the last element of the link list if there is only one element for int linklist");
// 	int c = 9,*res;
// 	LinkedList list = createList();
// 	Node *intNode = create_node(&c);
// 	add_to_list(&list,intNode);
// 	res = get_last_element(list);
// 	assertEqual(*res, 9);
// }

// void test_get_last_element_002() {
// 	log("gives the first element of the link list if there is only one element for float linklist");
// 	float c = 9.5,*res;
// 	LinkedList list = createList();
// 	Node *intNode = create_node(&c);
// 	add_to_list(&list,intNode);
// 	res = get_last_element(list);
// 	assertEqual(*res, 9.5);
// }

// void test_get_last_element_003() {
// 	log("gives the first element of the link list if there is only one element for char linklist");
// 	char c = 'A',*res;
// 	LinkedList list = createList();
// 	Node *intNode = create_node(&c);
// 	add_to_list(&list,intNode);
// 	res = get_last_element(list);
// 	assertEqual(*res, 'A');
// }

// void test_get_last_element_004() {
// 	log("gives the first element of the link list if there is only one element for string linklist");
// 	string c = "Prasenjit",*res;
// 	LinkedList list = createList();
// 	Node *intNode = create_node(c);
// 	add_to_list(&list,intNode);
// 	res = get_last_element(list);
// 	assertEqual(res, "Prasenjit");
// }

// void add(void* data) {
// 	*(int*)data += 1;
// }

// void test_traverse_001() {
// 	log("traverse through a int node and increases each element by one");
// 	int c = 9;
// 	LinkedList list = createList();
// 	Node *intNode = create_node(&c);
// 	add_to_list(&list,intNode);
// 	traverse(list,add);
// 	assertEqual(*(int*)(*(Node*)(list.head)).data, 10);
// }

// void test_getElementAt_001() {
// 	log("getElementAt gives the data at given position for integer");
// 	int c = 9,d = 10;
// 	LinkedList list = createList();
// 	Node *node1 = create_node(&c),*node2 = create_node(&d);
// 	add_to_list(&list,node1);
// 	add_to_list(&list,node2);
// 	assertEqual(*((int*)getElementAt(list,0)),9);
// 	assertEqual(*((int*)getElementAt(list,1)),10);
// }

// void test_indexOf_001() {
// 	log("indexOf gives the position of the given element in an integer link list");
// 	int c = 9,d = 10;
// 	LinkedList list = createList();
// 	Node *node1 = create_node(&c),*node2 = create_node(&d);
// 	add_to_list(&list,node1);
// 	add_to_list(&list,node2);
// 	assertEqual(((int *)indexOf(list,&c)),0);
// 	assertEqual(((int *)indexOf(list,&d)),1);
// }

// void test_deleteElementAt_001() {
// 	log("deleteElementAt deletes the element at the given position");
// 	int c = 9,d = 10,e = 11;
// 	LinkedList list = createList();
// 	Node *node1 = create_node(&c),*node2 = create_node(&d),*node3 = create_node(&e);
// 	add_to_list(&list,node1);
// 	add_to_list(&list,node2);
// 	add_to_list(&list,node3);
// 	assertEqual(((int *)indexOf(list,&e)),2);
// 	deleteElementAt(list,1);
// 	assertEqual(((int *)indexOf(list,&e)),1);
// }