#include "struc_link.h"
#include <stdio.h>
#include <stdlib.h>




Node* AddNode(Node *top, int data)           //新增一個node 
{
	Node* newnode;
	newnode = (Node*)malloc(sizeof(Node));

	if (newnode == NULL){
		printf("\n Fail to add");

		exit(1);
	}
	else{
		printf("\n succ add\n");

	}

	newnode->data = data;
	top->front = newnode;
	newnode->next = top;
	top = newnode;
	return top;

}