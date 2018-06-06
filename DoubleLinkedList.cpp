#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int marks;
	int roll_number;
	struct node *next;
	struct node *previous;
	
};

struct node *head=NULL;

add_at_start(int marks,int id){
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->marks=marks;
	temp->roll_number=id;
	temp->next=head;
	head=temp;
	temp->previous=NULL;
}

add_at_end(int marks,int id){
	if(head==NULL){
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node));
		temp->marks=marks;
		temp->roll_number=id;
		temp->next=NULL;
		
		head=temp;
		temp->previous=NULL;
	}
	else if(head!=NULL){
		struct node *temp;
		struct node *temp1;
		temp=(struct node*)malloc(sizeof(struct node));
		temp->marks=marks;
		temp->roll_number=id;
		temp->next=NULL;
		temp1=head;
		while(temp1->next!=NULL){
		temp1=temp1->next;
		}
		temp->next=temp1->next;
		temp1->next=temp;
		temp->previous=temp1;
		
	}
}

add_in_middle(int marks,int id){
	if(head!=NULL){
	struct node *temp;
	struct node *temp2;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->marks=marks;
	temp->roll_number=id;
	int i,loc;
	loc=2;
	struct node *temp1;
	temp1=head;
	for(i=0;i<loc-2;i++){
		temp1=temp1->next;
	}
	temp2=temp1->next;
	temp->next=temp1->next;
	temp1->next=temp;
	temp->previous=temp1;
	temp2->previous=temp;
	
	}
	else{
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node));
		temp->marks=marks;
		temp->roll_number=id;
		temp->next=head;
		head=temp;
		temp->previous=NULL;
	}
}

remove(int marks,int id){
	struct node *temp;
	struct node *prev=NULL;
	
	temp=head;
	
		while(temp!=NULL){
			if(temp->marks==marks && temp->roll_number==id){
				if(temp==head)
				{	
					struct node *temp1;
					temp1=temp->next;
					head=temp->next;
					
					temp1->previous=NULL;
					free(temp);
					break;
				}
				else
				{
			
			prev->next=temp->next;
			if(temp->next!=NULL){
			struct node *temp1;
			temp1=temp->next;
			temp1->previous=prev;	
			}
			free(temp);
			break;
		}
			}
			else{
			prev=temp;
			temp=temp->next;
			}
		}
	}


search(int marks,int id){
	struct node *temp1;
	temp1=head;
		
	while(temp1!=NULL){
		if(temp1->marks==marks && temp1->roll_number==id){
		printf("Your searched student:\n");
		printf("Student Roll Number:\t%d \n",temp1->roll_number);
		printf("Student marks:\t\t%d \n\n\n",temp1->marks);
		return NULL;
		}
		temp1=temp1->next;
		}
		printf("STUDENT NOT FOUND!\n\n");
		return NULL;
	if(temp1->marks!=marks && temp1->roll_number!=id){
		printf("STUDENT NOT FOUND! \n\n");
	}
	
	
}

display(){
	struct node *temp=head;
	printf("Students DATA: \n\n");
	while(temp!=NULL){
		printf("Student roll number:\t");
		printf("%d \n",temp->roll_number);
		printf("Student marks: \t\t");
		printf("%d \n\n",temp->marks);
		temp=temp->next;
	}
}

main(){
	
	bool logout=false;
	while(logout==false){
	printf("Choose any option:\n\n");
	printf("1)Add Data At Start\n");
	printf("2)Add Data in End\n");
	printf("3)Add Data in Middle\n");
	printf("4)Display List\n");
	printf("5)Search Student\n");
	printf("6)Remove Data\n");
	printf("7)End Program\n");
	printf("\t\t\t\t\t\tBY: KZS\n");
	int choice;
	scanf("%d",&choice);
	switch(choice){
		case 1:
			int a,b;
			printf("Enter marks:\n");
			scanf("%d",&a);
			printf("Enter Roll Number:\n");
			scanf("%d",&b);
			add_at_start(a,b);
			break;
		case 2:
			int c,d;
			printf("Enter marks:\n");
			scanf("%d",&c);
			printf("Enter Roll Number:\n");
			scanf("%d",&d);
			add_at_end(c,d);
			break;
		case 3:
			int e,f;
			printf("Enter marks:\n");
			scanf("%d",&e);
			printf("Enter Roll Number:\n");
			scanf("%d",&f);
			add_in_middle(e,f);
			break;		
		case 4:
			display();
			break;
		case 5:
			int g,h;
			printf("Enter marks:\n");
			scanf("%d",&g);
			printf("Enter Roll Number:\n");
			scanf("%d",&h);
			search(g,h);
			break; 
		case 6:
			int i,j;
			printf("Enter marks:\n");
			scanf("%d",&i);
			printf("Enter Roll Number:\n");
			scanf("%d",&j);
			remove(i,j);
			break;
		case 7:
			logout=true;
			break;
	}
}
}
//	add_at_start(98,29,&head);
//	add_at_end(77,68,&head);
//	add_at_start(50,30,&head);
//	add_at_start(90,20,&head);
//	add_at_start(87,10,&head);
//	add_at_start(57,70,&head);
//	add_in_middle(79,44,&head);
//	display();
//	remove(79,44,&head);	
//	display();	
//}
