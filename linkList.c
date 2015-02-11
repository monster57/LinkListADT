#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkList.h"


LinkList createList(void){
	LinkList list;
	list.head = NULL;
	list.tail = NULL;
	list.numOfElements = 0;
	return list;
}

Node * create_node(void *data){
	Node* new_node = malloc(sizeof(Node));
	new_node->data = data;
	new_node ->next = NULL;
	return *(int*)data?new_node:0;
}

int add_to_list(LinkList * list,Node * node){
	if(!node) return 0;
	!list->head?(list->head = node):(list->tail->next = node);
	list->tail = node;
	list->numOfElements++;
	return 1;
}

void *get_first_element(LinkList list){
	return list.head->data;
}

void *get_last_element(LinkList list){
	return list.tail->data;
}
void traverse(LinkList list, void (*function)(void *data)){
	Node *node;
	for(node=list.head;node;node=node->next)
		function(node->data);
}
void * getElementAt(LinkList list, int index){
	int counter;
	Node *node = list.head;
	if(index>list.numOfElements)return 0;
	for(counter = 0;counter<index;counter++)
		node = node->next;
	return node->data;
}
int indexOf(LinkList list, void *element){
	int count=0;
	Node *node;
	for(node = list.head;node;node = node->next){
		if(!memcmp(element,node->data , sizeof((void)element))) return count;
		count++;		
	}
	return -1;
}

void * deleteElementAt(LinkList *list, int index){
	int counter; 
	void *data;
	Node *node=list->head , *previousNode = NULL;
	if(index>=list->numOfElements || index<=-1) return NULL;
	for(counter=0;counter<index;counter++){
		previousNode = node; 
		node=node->next;
	}
	(node==list->tail)&&(list->tail=previousNode)&&(list->tail->next=NULL);
	data = node->data;
	(previousNode)?(previousNode->next = node->next):(list->head = list->head->next);
	list->numOfElements--;
	// free(node);
	// free(previousNode);
	return data;
}

int asArray(LinkList list, void **array){
	int counter=0;
	Node *node = list.head;
	for(;node;node=node->next){
		(array)[counter] = node->data;
		counter++;
	}
	free(node);
	return counter;
}

LinkList * filter(LinkList list, int (*func)(void *data)){
	Node *node = list.head;
	LinkList *new_list = calloc(sizeof(LinkList) ,1);
	for(;node;node = node->next){
		func(node->data) && add_to_list(new_list, node);
	}
	return new_list;
}