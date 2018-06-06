#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int top=-1;
struct node{
	int num;
	struct node *next;
	
};//={9,8,7,5,6,4,3,2,1,0};
	
	struct node *head=NULL;
//int isfull(){
////	printf("%d\n",size);
////	printf("\t\t%d\n\n\n",*top);
//	if(top==size-1){
//		return 1;
//	}
//	else{
//		return 0;
//	}
//}
int isempty(){
	if(top==-1){
		return 1;
	}
	else{
		return 0;
	}
}
pop(){
	
	if(isempty()){
		printf("Stack is Empty!");
	}
	else{
//		printf("%d ",stack[top]);
		top--;
		struct node* temp;
		temp=head;
		head=temp->next;
		free(temp);
		
	}
}
push(int value){
// 	printf("%d\n",size);
//	printf("\t\t%d\n\n\n",*top);
//	 	if(isfull()){
// 			printf("Stack is Full!\n");
//		 }
//		 else{
		 	top++;
		 	struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node));
		temp->num=value;
		
		temp->next=head;
		head=temp;
		 	
	//	 }
}
display(){
//	if(*size==-1){
//		printf("Empty!");
//	}
	//else{
	struct node* temp;
	temp=head;
	while(temp!=NULL){
		printf("%d\n",temp->num);
		temp=temp->next;
	}
}
	
//}
int main(){
			int choice;
	while(choice!=4){
	printf("\t===================\n");
	printf("\t\tSTACK\n");
	printf("\t===================\n");
	printf("Choose One\n\n");
	printf("1)PUSH\n");
	printf("2)POP\n");
	printf("3)Display\n");
	printf("4)Logout\n\n");
	printf("\t\t\t\t\t\tBY: KZS\n");
	int option;
	int a;
	scanf("%d",&option);
		switch(option){
			case 1:
				
				printf("Enter Number:\n");
				scanf("%d",&a);
				push(a);
				break;
			case 2:
				pop();
				break;
			case 3:	
				display();
				break;
			case 4:
				choice=4;
				break;
			default:
			printf("Wrong Input\n\n");
					
		}
//	push(7);
//	push(6);
//	push(5);
//	push(4);
//	push(3);
//	push(2);
//	push(1);
//	push(9);
//	push(8);
//	push(11);
//	display();
//	
//	pop();
//	printf("***************\n");
//	display();

}
}
