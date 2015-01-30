#include <stdio.h>
#include <stdlib.h>
#include "linkList.h"

LinkedList createList(void){
	LinkedList list;
	list.head = 0;
	list.tail = 0;
	list.count = 0;
	return list;
};

Node * create_node(void *data){
	Node_ptr link = calloc(1,sizeof(Node));
	link->data = data;
	link->next = NULL;
	return link;
};


int add_to_list(LinkedList *list,Node *node){
	(!list->head)?(list->head=node):(list->tail->next = node);
	list->tail = node;
	list->count++;
	return 1;
};

void *get_first_element(LinkedList list){
	return list.head;
};

void *get_last_element(LinkedList list){
	return list.tail;
};

void traverse(LinkedList list, FunctionRef func){
	Node_ptr walker = list.head;
	while(walker != NULL){
		 func(walker->data);
		 walker = walker->next;
	}
};

void * getElementAt(LinkedList list, int index){
	int counter;
	Node_ptr walker =list.head;
	if(index>=list.count){
		return NULL;
	} 
	for(counter=0;counter<index;counter++){
		walker=walker->next;
	}
	return walker->data;
};


int indexOf(LinkedList list, void *element){
	Node_ptr walker = list.head;
	int index = 0;
	while(walker != NULL){
		if(walker->data == element)
			return index;
		 index++;
		 walker = walker->next;
	}
	return -1;
};

