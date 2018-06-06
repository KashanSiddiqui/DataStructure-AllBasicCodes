#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int roll_number;
	struct node *next;
	
};

struct node *head=NULL;

enqueue(int id){
	if(head==NULL){
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node));
		temp->roll_number=id;
		temp->next=NULL;
		head=temp;
	}
	else if(head!=NULL){
		struct node *temp;
		struct node *temp1;
		temp=(struct node*)malloc(sizeof(struct node));
		temp->roll_number=id;
		temp->next=NULL;
		temp1=head;
		while(temp1->next!=NULL){
		temp1=temp1->next;
		}
		temp->next=temp1->next;
		temp1->next=temp;
		
	}
}
dequeue(){
	struct node *temp=head;
		head=temp->next;
		free(temp);
		
}

display(){
	struct node *temp=head;
	if(temp==NULL){
		printf("List is Empty\n");
	}
	else{
	printf("Students DATA: \n\n");
	while(temp!=NULL){
		printf("Student roll number:\t");
		printf("%d \n",temp->roll_number);
		temp=temp->next;
	}
}
}
int main(){
	int choice;
	while(choice!=4){
	printf("\t\tQUEUE Using LinkedList\n");
	printf("Choose One\n\n");
	printf("1)Enqueue\n");
	printf("2)Dequeue\n");
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
				enqueue(a);
				break;
			case 2:
				dequeue();
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
}
}
