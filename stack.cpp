#include<stdio.h>
#include<conio.h>
int isfull(int *top,int size){
//	printf("%d\n",size);
//	printf("\t\t%d\n\n\n",*top);
	if(*top==size-1){
		return 1;
	}
	else{
		return 0;
	}
}
int isempty(int *top){
	if(*top==-1){
		return 1;
	}
	else{
		return 0;
	}
}
pop(int *top,int arr[]){
	
	if(isempty(top)){
		printf("Stack is Empty!");
	}
	else{
		printf("%d",&arr[*top]);
		top--;
	}
}
push(int *top,int value,int arr[],int size){
// 	printf("%d\n",size);
//	printf("\t\t%d\n\n\n",*top);
	 	if(isfull(top,size)){
 			printf("Stack is Full!\n");
		 }
		 else{
		 	top++;
		 	arr[*top]=value;
		 	printf("%d\n",arr[*top]);
		 }
}
display(int arr[],int size){
//	if(*size==-1){
//		printf("Empty!");
//	}
	//else{
	for(int i=size;i>=0;i--){
		printf("%d",arr[i]);
	}
}
	
//}
int main(){
	int size=10;
	int stack[10];//={9,8,7,5,6,4,3,2,1,0};
	int top=-1;
	push(&top,0,stack,size);
	push(&top,1,stack,size);
	push(&top,2,stack,size);
	push(&top,3,stack,size);
	push(&top,4,stack,size);
	push(&top,5,stack,size);
	push(&top,6,stack,size);
	push(&top,7,stack,size);
	push(&top,8,stack,size);
	push(&top,9,stack,size);
	push(&top,9,stack,size);
	
	display(stack,size);
	pop(&top,stack);
	printf("\n\n\n\n");
	display(stack,size);
}
