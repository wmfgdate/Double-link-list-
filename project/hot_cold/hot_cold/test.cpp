#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <conio.h>
#include <stdbool.h>
#include "struc_link.h"
#include "Check_List.h"

Node* AddNode(Node*, int);  //串列列印函數 


int main(){
	Node test;
	Node *ptr = &test;








}


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

	newnode->next = top;
	top = newnode;
	return top;

}