#include "../expr_assert.h"
#include "../linkList.h"
#include <stdio.h>
int data =10,data1=20;
Node n1 ; 
LinkedList l1,l2;
void setup(){
	n1=(Node){&data,NULL};
	l1=(LinkedList){&n1,&n1,1};
	l2=(LinkedList){NULL,NULL,0};	
}
void test_creatLinkList_has_head_tail_and_count_initialized_to_NULL(){
	LinkedList list =createList();
	assert(list.head==NULL);
	assert(list.tail== NULL);
	assertEqual(list.count, 0);
}
void test_creat_node_contains_given_data(){
	Node* node =create_node(&data);
	assert(node->data==&data);
}
void test_add_to_List_adds_node_at_the_end_of_list(){
	add_to_list(&l1,create_node(&data1));	
	assertEqual(*(int*)(l1.tail->data),20);
}

void test_add_to_List_for_empty_list_sets_node_as_head(){
	add_to_list(&l2,create_node(&data1));
	assert((l2.head->data)==&data1);	
	assertEqual(*(int*)(l2.head->data),20);
}

void test_add_to_List_incress_count(){
	add_to_list(&l1,create_node(&data1));
	assertEqual((l1.count),2);
}
void test_tail_points_to_last_added_element(){
	add_to_list(&l1,create_node(&data1));
	assert((l1.tail->data)==&data1);	

}
void test_getFirstElement_in_list(){
	int * d = (int *)get_first_element(l1);
	assertEqual(*d, 10);	
}
void test_getlastElement_in_list(){
	int *d;
	add_to_list(&l1,create_node(&data1));

	d = (int *)get_last_element(l1);
	assertEqual(*d, 20);	
}

void add1(void* data){
	*(int*)data +=1;	
}
void test_add_1_to_each_element_of_list(){
	int *d;
	add_to_list(&l1,create_node(&data1));

	traverse(l1,add1);
	assertEqual(*((int*)l1.head->data),11);
	assertEqual(*((int*)l1.tail->data),21);
} 

void test_first_element_in_list_is_head(){
	int * result = getElementAt(l1,0);
	assertEqual(*(result),*((int*)l1.head->data));
}
void test_get_element_at_index_which_not_in_list_return_NULL(){
	int *result;
	result =getElementAt(l1, 1);
	assert(result==NULL);
} 
void test_getElement_at_index_gets_refrence_to_data_at_given_index(){
	int *result;
	add_to_list(&l1,create_node(&data1));

	result =getElementAt(l1, 1);
	assertEqual(*result,data1);
} 
void test_indexOf_gets_index_of_given_data_in_list(){
	int data2=12,data3=14,data4=16,result;
	l2.head =&n1;
	n1.next = create_node(&data2);
	n1.next->next=create_node(&data3);
	n1.next->next->next=create_node(&data4);
	result = indexOf(l2, &data3);
	assertEqual(result,2);
}
void test_indexOf_returns_minus_1_if_element_is_not_in_list(){
	int data2=12,data3=14,data4=16,result;
	l2.head =&n1;
	n1.next = create_node(&data2);
	n1.next->next=create_node(&data3);
	result = indexOf(l2,&data4 );
	assertEqual(result,-1);
}
void test_delete_Element_At_given_index_and_reduces_count(){
	int data2=12,data3=14,data4=16,*data;
	add_to_list(&l2, create_node(&data1));
	add_to_list(&l2, create_node(&data2));
	add_to_list(&l2, create_node(&data3));
	
	data=deleteElementAt(&l2,1);
	
	assertEqual(l2.count,2);
	assertEqual(*(int*)(l2.head->data),data1);
	assertEqual(*(int*)(l2.tail->data),data3);

}
void test_delete_At_0th_resets_the_head_to_the_next_of_head(){
	int data2=12,data3=14,data4=16,*data;
	add_to_list(&l2, create_node(&data1));
	add_to_list(&l2, create_node(&data2));
	add_to_list(&l2, create_node(&data3));
	
	data=deleteElementAt(&l2,0);
	
	assertEqual(*(int*)(l2.head->data),data2);
}
void test_delete_last_element_resets_the_tail_to_the_next_of_head(){
	int data2=12,data3=14,data4=16,*data;
	add_to_list(&l2, create_node(&data1));
	add_to_list(&l2, create_node(&data2));
	add_to_list(&l2, create_node(&data3));
	
	data=deleteElementAt(&l2,2);
	
	assertEqual(*(int*)(l2.tail->data),data2);
}