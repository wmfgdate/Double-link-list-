// hot_cold.cpp : �w�q�D���x���ε{�����i�J�I�C
//



#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <conio.h>
#include <stdbool.h>
#include "struc_link.h"


void printList(Node *);      //�C�L��C�ϧ� 
void printList_V2(Node *);   //�C�L��Cdata & addr
void Insert_data(Node **,Node** ,Node **, int );

void printList_tail(Node *);
void printList_V2_tail(Node*);


Node* AddNode(Node* , int );  //��C�C�L��� 
void inital_hotcold();
Node* Check_List(Node*, int);



using namespace std;

/*
	ptr_X_top :  ��C head addr

	ptr_X_in  :  ��Clast data addr

	ptr_h_tail : ��C last addr

	--------------------------------------------
	�@�}�l����JHOT_len and COLD_len
	eg:   2   4
	    120 240	
	--------------------------------------------
		INPUT :  WorR LBA  
	eg: W 123
		R 789



	�n�d�ߦb����List ��J   "C0"   0 =>�Ʀr0




*/





int main(){
	
	Node HOT, COLD;


	Node *ptr_h_top = &HOT;
	Node *ptr_c_top = &COLD;

	Node *ptr_c_in;
	Node *ptr_h_in;

	Node *ptr_h_tail = &HOT;
	Node *ptr_c_tail = &COLD;

	Node *ptr;

	unsigned int hot_length  = 3;
	unsigned int cold_length = 5;
	char RequestType = '0';
	unsigned int LBA = 0;
	
	
	/*---------------------��link list---------------------------------------------------------------------------------*/
	
	while (true){
		printf("Please enter HOT_len and COLD_len \n");

		scanf_s("%d %d", &hot_length, &cold_length);
		if ((hot_length <= 5000 && hot_length >= 1) && (cold_length <= 10000 && cold_length >= 1)){

			break;
			
		}
		printf("PLZ enter H=1~5000  C=1~10000 \n");
	}

	



	//HOT.front = NULL;
	HOT.data = 0;
	HOT.next = NULL;

	//COLD.front = NULL;
	COLD.data = 0;
	COLD.next = NULL;

	//printf(" %d %d\n", hot_length, cold_length);

	//printList(ptr_h_top);
	//printList(ptr_c_top);

	//printf("\n---------------------------------------------\n");


	for (unsigned int i = 1; i < hot_length; i++){
		ptr_h_top = AddNode(ptr_h_top, 0);
		
		//printList(ptr_h);
	}
	
	for (int i = 1; i < cold_length; i++){
		ptr_c_top = AddNode(ptr_c_top, 0);
		
		//printList(ptr_c_top);
	}
	ptr_h_in = ptr_h_top;
	ptr_c_in = ptr_c_top;


	/*--------------------------------------------------------------------------------------------------------------------*/   

	/*                                                //input data HOT(initial)
	//printList(ptr_h_top);   
	//printList(ptr_c);

	ptr_h_in = ptr_h_top;
	ptr_h_in->data = 5;

	//printList_V2(ptr_h_top);
	ptr_h_in = ptr_h_in->next;
	ptr_h_in->data = 2;
	//printList_V2(ptr_h_top);
	ptr_h_in = ptr_h_in->next;
	ptr_h_in->data = 7;



	printList_V2(ptr_h_top);
	printList(ptr_h_top);
	*/


	/*--------------------------------------*/

	/*                                                 //input data COLD(initial)
	//printList(ptr_c_top);                             
	//printList(ptr_c);

	ptr_c_in = ptr_c_top;
	ptr_c_in->data = 4;

	//printList_V2(ptr_h_top);
	ptr_c_in = ptr_c_in->next;
	ptr_c_in->data = 3;
	//printList_V2(ptr_h_top);
	ptr_c_in = ptr_c_in->next;
	ptr_c_in->data = 1;

	

	//printList_V2(ptr_c_top);
	//printList(ptr_c_top);




	//printf("\nH_TOP: %p  H_in: %p  H_Tail: %p\n", ptr_h_top, ptr_h_in, ptr_h_tail);
	//printf("\nC_TOP: %p  C_in: %p  C_Tail: %p\n", ptr_c_top, ptr_c_in, ptr_c_tail);

	*/

	/*------------------------------------------------------------------------------------------------------------------------*/
																//���JLBA
	//Insert_data(&ptr_c_top, &ptr_c_in, &ptr_c_tail, 123);
	
	
	




	/*----------------*/


	//printf("\nH_Tail: %p \n", ptr_h_tail);
	//printf("\nC_Tail: %p \n", ptr_c_tail);
	

	
	/*----------------------------------------------*/

	
	while(true){
		//scanf_s("%d-%d",&RequestType,&LBA);  //�ǩǪ��L�k��scan %c �A %d 
		//scanf_s("%d", &LBA);                 //��ΥH�U��k
		RequestType = '0';
		LBA = 0;
		
		

		printf("HOT:\n");                                      //    <--------- �q�����U�� �O��ܥثeHOT COLD LBA ����
		printList(ptr_h_top);
		//printList_V2(ptr_h_top);

		printf("Cold:\n");
		printList(ptr_c_top);
		//printList_V2(ptr_c_top);							   //    <--------------------------------------------------------


		/*printf("\nHOT_in: %p -- HOT_tail: %p  \n", ptr_h_in, ptr_h_tail);
		printf("COLD_in: %p -- COLD_tail: %p  \n", ptr_c_in, ptr_c_tail);*/

		cin >> RequestType >> LBA  ;

		//printList_V2(ptr_c_top);
		//printf("%p\n", ptr_c_top);
		//printf("%p\n", Check_List(ptr_h_top, (int)3));
		//printf("%s\n", RequestType);

		if (RequestType == 'W' || RequestType == 'R')  
		{
			//printf("W\n");
			if (Check_List(ptr_h_top, LBA) != NULL){          //in hot              XXXXXXXXXX
				//��LBA����HOT�̫e��
				//Case1:�bHOT. head
				//Case2:�bHOT. mid
				//Case3:�bHOT. tail
				

				ptr = Check_List(ptr_h_top, LBA);

				if (ptr == ptr_h_top){         //Case 1
					//do-nop
				}
				else if (ptr == ptr_h_in){     //Case 3
					
					Insert_data(&ptr_h_top, &ptr_h_in, &ptr_h_tail, LBA);
				
				}
				else{							//Case 2
										
					ptr->front->next = ptr->next;
					ptr->next->front = ptr->front;
					ptr->next = ptr_h_top;
					ptr_h_top->front = ptr;
					ptr_h_top = ptr;

				}
				//printf("ptr: %p \n", ptr);
				

				
				ptr_h_in = ptr_h_tail;                         //�q����
				while ((ptr_h_tail)->data == 0){              //��ptr_in
			
					(ptr_c_in) = (ptr_c_in)->front;

				}


				
			}
			else if (Check_List(ptr_c_top, LBA) != NULL){     //in cold      OK
				//��LBA�qCOLD ���� HOT 
				ptr = Check_List(ptr_c_top, LBA);
				
				while (ptr->next != NULL){                  //��list data ���e��
					ptr->data = ptr->next->data;
					ptr = ptr->next;
				
				}
				
				

				//printf("HOT_in: %p -- HOT_tail: %p  \n", ptr_h_in,ptr_h_tail);
				//printf("COLD_in: %p -- COLD_tail: %p  \n", ptr_c_in, ptr_c_tail);

				if (ptr_h_in == ptr_h_tail){   // hot ���F
					Insert_data(&ptr_c_top, &ptr_c_in, &ptr_c_tail, ptr_h_tail->data);
			
				}

				Insert_data(&ptr_h_top, &ptr_h_in, &ptr_h_tail, LBA);
				
				
			
			}
			
			
			
			else{                                             //�����bHOT and COLD   OK
				
				Insert_data(&ptr_c_top, &ptr_c_in, &ptr_c_tail, LBA);//��LBA+��COLD
				
			}
			
			////not in hot and cold     --1 
			//if (Check_List(ptr_h_top, LBA) == NULL){        //���bHOT
			//	printf("not in Hot\n");
			//	if (Check_List(ptr_c_top, LBA) == NULL){    //���bCOLD 
			//		printf("not in Cold\n");
			//		Insert_data(&ptr_c_top, &ptr_c_tail, LBA);
			//		printList(ptr_c_top);
			//	}
			//}
			////in cold but not in hot  --1




			//printf("%p\n", Check_List(ptr_h_top, LBA));
		}
		
		else if (RequestType == 'C' ) //C0   OK
		{
			printf("Check in Cold or Hot\n");
			printf("Please enter LBA number:\n");
			while (true){
				cin >> LBA;
				if (Check_List(ptr_h_top, LBA)!=NULL){ //���ߪ��ܪ�ܦbHOT
					printf("HOT\n");
				}
				else{
					printf("Cold\n");
				}
			};		
		}   




		//printf("%c %d \n", RequestType, LBA);
		printf("-----------------------\n");
	};
	
	
	
	







	system("pause");
	
	return 0;
}

Node *Check_List(Node *first,int Data_LBA){

	Node *node = first; //�Nnode���V�Ĥ@�Ӹ`�I

	if (first == NULL){
		printf("List is empty!\n");
	}
	else{
		while (node != NULL){
			//printf("%d\n   ", node->data);
			if (int(node->data) == Data_LBA  ){
				
				//printf("a\n");
				return node;
			}
			else if (node->data == 0){
				
				//printf("b\n");
				return NULL;
			}
			else{
				node = node->next;
			}
			
		}
		return NULL;
		printf("\n");
	}

	
}

void printList(Node *first){
	Node *node = first; //�Nnode���V�Ĥ@�Ӹ`�I
	if (first == NULL){
		printf("List is empty!\n");
	}
	else{
		while (node != NULL){
			printf(" %4d ", node->data);
			if (node->next != NULL){
				printf("->");
			}
			node = node->next;

		}
		printf("\n");
	}
	

}
void printList_tail(Node *tail){
	//Node *node = tail; //�Nnode���V�Ĥ@�Ӹ`�I
	if (tail == NULL){
		printf("List is empty!\n");
	}
	else{
		while (tail != NULL){
			printf(" %3d ", tail->data);
			if (tail->front != NULL){
				printf("->");
			}
			tail = tail->front;

		}
		printf("\n");
	}


}
Node* AddNode(Node *top, int data)           //�s�W�@��node 
{
	Node* newnode;
	newnode = (Node*)malloc(sizeof(Node));
	
	if (newnode == NULL){
		printf("\n Fail to add");
		
		exit(1);
	}
	else{
		//printf("\n succ add\n");
	
	}

	newnode->data = data;
	top->front = newnode;

	newnode->next = top;
	top = newnode;
	return top;

}

void printList_V2(Node *first){
	//Node *node = first; //�Nnode���V�Ĥ@�Ӹ`�I
	while (first != NULL){
		printf("addr=%p, ", first);
		printf("front=%p ", first->front);
		printf("data=%d ", first->data);
		printf("next=%p\n ", first->next);
		first = first->next;
	}

}

void printList_V2_tail(Node *tail){
	//Node *node = first; //�Nnode���V�Ĥ@�Ӹ`�I
	while (tail != NULL){
		printf("addr=%p, ", tail);
		printf("data=%d ", tail->data);
		printf("next=%p\n ", tail->front);
		tail = tail->front;
	}

}

void Insert_data(Node **top, Node** in , Node **tail, int LBA){
	
	
	(*tail)->front->next = NULL;
	(*tail)->data = LBA;
	(*tail)->next = (*top);
	(*top)->front = (*tail);
	(*top) = (*tail);
	(*tail) = (*tail)->front;

	(*top)->front = NULL;



	(*in) = (*tail);                       //�qtail��
	while ((*in)->data == 0){              //��ptr_in

		(*in) = (*in)->front;
		printf("in: %p", (*in));
	
	}
	printf("\nINSTRT\n");

	

}

