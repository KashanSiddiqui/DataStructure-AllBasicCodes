#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
struct expressionTree{
	char value;
	struct expressionTree *right;
	struct expressionTree *left;
	
}*arr[100];
int ptop=-1;
int top1=-1;



int isFull(){
if(top1==101-1)
{printf("Stack Overflow\n");
return 1;
}
else
return 0;
}
 
/*PUSH FUNCTION*/
void push (char stack[], char item,int* top)//
{   
	*top=*top+1;
	stack[*top] = item;
    }
 
/*POP FUNCTION*/
int pop (char stack[],int* top)
{  
    int ret;
    if (*top == -1)
    {   ret = 0;
    }
    else
    {   
	ret = stack [*top];
	*top=*top-1;
    }
return ret;
}
/*PUSH FUNCTION FOR ET*/


void PUSH(struct expressionTree* x)
{
if(isFull())
return;

arr[++ptop]=x;
}

 
/*POP FUNCTION FOR ET*/
struct expressionTree* POP()
{
    return(arr[ptop--]);
}

display(int stack[],int top){
	int loop;
	for(loop=0;loop<=top;loop++){
		printf("%d \t",stack[loop]);
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
//preOrder(struct expressionTree **parent){
//	struct expressionTree *temp;
//	temp =*parent;
//	if(*parent==NULL){
//		return;
//	}
//	else{
//		
//		printf("%c \t",temp->value);
//		preOrder(&(temp->left));
//		preOrder(&(temp->right));
//	}
//}
//postOrder(struct expressionTree **parent){
//	struct expressionTree *temp;
//	temp =*parent;
//	if(*parent==NULL){
//		return;
//	}
//	else{
//		
//		postOrder(&(temp->left));
//		postOrder(&(temp->right));
//		
//		printf("%c \t",temp->value);
//	}
//}
//inOrder(struct expressionTree **parent){
//	struct expressionTree *temp;
//	temp =*parent;
//	if(*parent==NULL){
//		return;
//	}
//	else{
//		
//		inOrder(&(temp->left));
//		printf("%c \t",temp->value);
//		inOrder(&(temp->right));
//		
//		
//	}
//}
int main(){
	char stack1[25];
	
	int top2=-1;
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
				push(stack1,infix[i],&top1);
//				top++;
//				stack[top]=infix[i];
				i++;
			}
			else if(infix[i]==')'){
				while(stack1[top1]!='('){
					postFix[j]=pop(stack1,&top1);
					j++;
				}
				i++;
				char rem=pop(stack1,&top1);
			}
			else{
				while(pre(stack1[top1])>=pre(infix[i])){
					postFix[j]=pop(stack1,&top1);
					j++;
				}
				push(stack1,infix[i],&top1);
				i++;
			}
		}
	}
	while(top1!=-1){
		postFix[j]=pop(stack1,&top1);
		j++;
	}
	printf("Your Post Fix Expression: ");
	printf("%s",postFix);
	printf("\n\n\n\n");
	
	//START OF EXPRESSION TREE
int s=0;
//	
	while(postFix[s++]!='\0'){
		if(isalnum(postFix[s])){
		struct expressionTree *temp;
		temp=(struct expressionTree*)malloc(sizeof(struct expressionTree));
		temp->value=postFix[s];
		PUSH(temp);
		}
		else{
		struct expressionTree* temp;
		temp=(struct expressionTree*)malloc(sizeof(struct expressionTree));
		temp->value=postFix[s];
		temp->right=POP();
		temp->left=POP();
		PUSH(temp);
		}
	}
	
//	   while( (ch=pofx[j++]) != '\0'){
//    	if(isalnum(ch)){
//    		pushP(createNode(ch));
//		}
//		else{
//			Node *root = createNode(ch);
//			root->right = popP();
//			root->left = popP();
//			printf("%u\n",root);
//			pushP(root);
//		}
//		//arr[j] = createNode(ch);
//	}






//		struct expressionTree *show=stack2[0];
//				printf("\n=====================================================\n");	
//				printf("\nPre Order = \t");
//	            preOrder(&show);
//				printf("\nPost Order = \t");
//				postOrder(&show);
//				printf("\nIn Order= \t");
//				inOrder(&show);
//				printf("\n=====================================================\n");
	
	
}}
//temp=(struct treeNode*)malloc(sizeof(struct treeNode));
//		temp->key=key;
//		temp->left=NULL;
//		temp->right=NULL;
