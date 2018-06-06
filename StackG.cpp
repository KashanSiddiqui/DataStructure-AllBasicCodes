#include<stdio.h>
#include<conio.h>
int top=-1;
int size=10;
int stack[10];//={9,8,7,5,6,4,3,2,1,0};
	
int isfull(){
//	printf("%d\n",size);
//	printf("\t\t%d\n\n\n",*top);
	if(top==size-1){
		return 1;
	}
	else{
		return 0;
	}
}
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
		printf("Stack is Empty!\n\n");
	}
	else{
//		printf("%d ",stack[top]);
		top--;
	}
}
push(int value){
// 	printf("%d\n",size);
//	printf("\t\t%d\n\n\n",*top);
	 	if(isfull()){
 			printf("Stack is Full!\n\n");
		 }
		 else{
		 	top++;
		 	stack[top]=value;
		 	
		 }
}
display(){
//	if(*size==-1){
//		printf("Empty!");
//	}
	//else{
	for(int i=top;i>=0;i--){
		printf("%d \n",stack[i]);
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
//	push(1);
//	push(9);
//	push(8);
//	push(11);
//	pop();
//	display();

}
