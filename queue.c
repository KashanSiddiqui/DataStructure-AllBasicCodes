#include<stdio.h>
#include<conio.h>
int front=-1;
int rear=-1;
int queue[10];
int size=10;
int isfull(){
	if(rear==size-1){
		return 1;
	}
	else{
		return 0;
	}
}
int isempty(){
	if(rear==-1){
		return 1;
	}
	else{
		return 0;
	}
}
enqueue(int num){
	if(isfull()){
	printf("Queue is FULL\n");
	}
	else{
	rear++;
	queue[rear]=num;
		if(front==-1)
		front++;
	}
}
dequeue(){
	if(isempty() || front==rear+1){
		printf("\n\nQueue is empty\n\n");
	}
	else{
		front++;
//		printf("%d\n\n\n",front);
	}
}
display(){
	if(isempty()){
		printf("\n\nQueue is empty\n\n\n");
	}
	else{
		int k;
		printf("\n\n");
		for(k=front;k<=rear;k++){
			printf("%d\n",queue[k]);
		}
	}
}
int main(){
	int choice;
	while(choice!=4){
	printf("\t\tQUEUE SINGULAR\n");
	printf("Choose One\n\n");
	printf("1)Enqueue\n");
	printf("2)Dequeue\n");
	printf("3)Display\n");
	printf("4)Logout\n\n");
	rintf("\t\t\t\t\t\tBY: KZS\n");
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
