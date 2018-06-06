#include<stdio.h>
#include<conio.h>
int front=-1;
int rear=-1;
int queue[10];
int size=10;
int isfull(){
	if((front==0 && rear==size-1) || (rear==front-1) ){
		return 1;
	}
	else{
		return 0;
	}
}
//int isempty(){
//	if((front==0 && rear!=size-1) || (front!=0 && rear!=front-1)){
//		return 1;
//	}
//	else{
//		return 0;
//	}
//}
enqueue(int num){
	if(isfull()){
		printf("Queue is FULL\n\n");
	}
	else{
		if(rear==size-1){
			rear=0;
			queue[rear]=num;
			////printf("%d and %d\n",front,rear);
		}
		else{
			rear++;
			queue[rear]=num;
			if(front==-1)
			front++;
			////printf("%d and %d\n",front,rear);
		}
	}
}
dequeue(){
	if(rear==-1 || rear==front){
		printf("Queue is EMPTY\n");
	}
	else{
		if(front==size-1){
			front=0;
			////printf("%d and %d\n",front,rear);
		}
		else{
			front++;
			////printf("%d and %d\n",front,rear);
		}
	}
}

display(){
		if(rear==-1){
		printf("\n\nQueue is empty\n\n\n");
	}
	else{
	int k=front;
	while(k!=rear){
		if(k==size){
			k=0;
		}
		printf("%d\n",queue[k]);
		k++;
		
	}
	printf("%d\n",queue[k]);
	}
}
int main(){
	int choice;
	while(choice!=4){
	printf("\t\tQUEUE CIRCULAR\n");
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
	
	
	
	
	
	
	
	
	
//	enqueue(0);
//	enqueue(1);
//	enqueue(2);
//	enqueue(3);
//	enqueue(4);
//	enqueue(5);
//	enqueue(0);
//	enqueue(1);
//	enqueue(2);
//	enqueue(3);
//	display();
//	dequeue();
//	display();
//	enqueue(50);
//	display();
//	enqueue(0);
//	enqueue(1);
//	enqueue(2);
//	enqueue(3);
//	enqueue(4);
//	enqueue(5);
//	enqueue(6);
//	enqueue(7);
//	enqueue(8);
//	enqueue(9);
//	printf("\n=================\n");
//	dequeue();
//	dequeue();
//	dequeue();
//	dequeue();
//	dequeue();
//	dequeue();
//	printf("\n+++++++++++++++\n");
//	enqueue(10);
//	enqueue(11);
//	enqueue(12);
//	enqueue(13);
//	enqueue(14);
//	enqueue(15);
//	
//	printf("\n%%%%%%%%%%%%%%%%%%%\n");
//	dequeue();
//	dequeue();
//	dequeue();
//	dequeue();
//	dequeue();
//	dequeue();
//	dequeue();
//	dequeue();
//	dequeue();
//display();
//	int i;
//	for(i=0;i<10;i++){
//		printf("%d\n",queue[i]);
//	}
}
