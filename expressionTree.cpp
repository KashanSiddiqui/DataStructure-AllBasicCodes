#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


struct expressionTree{
	char value;
	struct expressionTree *right;
	struct expressionTree *left;
	
}*arr[100];
struct expressionTree *root = NULL;
int ptop=-1;


//bool isFull(){
//if(top==100)
//{printf("Stack Overflow\n");
//return true;
//}
//else
//return false;
//}


void PUSH(struct expressionTree* x)
{
//if(isFull())
//return;

arr[++ptop]=x;
}


struct expressionTree* POP()
{
    return(arr[ptop--]);
}




char stack[25];
int top=-1;
char pop(){
//		printf("%d ",stack[top]);
		return(stack[top--]);
	}
push(char value){
// 	printf("%d\n",size);
//	printf("\t\t%d\n\n\n",*top);
	top++;
	stack[top]=value;
		 	
	}
	
	
	
	
	
	
	
	
int isOperand(char check){
	int result;
	if(check=='*' || check=='/' || check=='+' || check=='-' || check=='(' || check==')'){
		result=0;
	}
	else{
		result=1;
	}
	return result;
}







int pre(char check){
	int result;
	if(check=='+'){
	result=1;
	}
	else if(check=='-'){
		result=1;
	}
	else if(check=='*'){
		result=2;
	}
	else if(check=='/'){
		result=2;
	}
	else{
		result=0;
	}
	return result;
}






//
//
//inOrder(struct expressionTree **parent){
//	struct expressionTree *temp;
//	temp =*parent;
//	if(*parent==NULL){
//		return NULL;
//	}
//	else{
//		
//		inOrder(&(temp->left));
//		printf("%d \t",temp->value);
//		inOrder(&(temp->right));
//		
//		
//	}
//}

void inOrder (expressionTree *root){
	if(root == NULL){
		return;
	}
	//struct Node* temp = root;
		inOrder((root->left));
		printf("%c",root->value);
		inOrder((root->right));
}



int main(){
	char infix[25];
	char postFix[25];
	printf("Enter Your Expression:\n");
	scanf("%s",&infix);
	int i=0;
	int j=0;
	while(infix[i]!='\0'){
		if(isOperand(infix[i])){
			postFix[j]=infix[i];
			i++;
			j++;
		}
		else{
			if(infix[i]=='('){
				push(infix[i]);
//				top++;
//				stack[top]=infix[i];
				i++;
			}
			else if(infix[i]==')'){
				while(stack[top]!='('){
					postFix[j]=pop();
					j++;
				}
				i++;
				char rem=pop();
			}
			else{
				while(pre(stack[top])>=pre(infix[i])){
					postFix[j]=pop();
					j++;
				}
				push(infix[i]);
				i++;
			}
		}
	}
	while(top!=-1){
		postFix[j]=pop();
		j++;
	}
	printf("**************************************\n\n");
	printf("Your Post Fix Expression: %s\n\n",postFix);
	
	
	
	
	
	
	
	
	
	
	
	///EXPRESSION TREE START
	int s=0;
	while(postFix[s]!='\0'){
		if(isalnum(postFix[s])){
		//	printf("$$$$\n");
		struct expressionTree *temp;
		temp=(struct expressionTree*)malloc(sizeof(struct expressionTree));
		temp->value=postFix[s];
		temp->left=NULL;
		temp->right=NULL;
		PUSH(temp);
		s++;
		}
		else{
			//printf("$$$$***\n");
		struct expressionTree* temp;
		temp=(struct expressionTree*)malloc(sizeof(struct expressionTree));
		temp->value=postFix[s];
		temp->right=POP();
		temp->left=POP();
		PUSH(temp);
		s++;
		}
	}
	root = arr[ptop];
	
	//PRINTING TREE
	printf("**************************************\n\n");
	printf("After Expression Tree== ");
	inOrder(root);
	printf("\n\n**************************************\n");
	
	
	
	
	
	
	
	
	
	
}
