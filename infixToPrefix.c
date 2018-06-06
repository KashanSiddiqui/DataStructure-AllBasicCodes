#include<stdio.h>
#include<conio.h>
#include<string.h>
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
int main(){
	char infix[25];
	char preFix[25];
	printf("Enter Your Expression:\n");
	scanf("%s",&infix);
	int i=strlen(infix);
    i=i-1;
	
	int j=0;
	while(i>=0){
		if(isOperand(infix[i])){
			preFix[j]=infix[i];
			i--;
			j++;
		}
		else{
			if(infix[i]==')'){
			

				push(infix[i]);
//				top++;
//				stack[top]=infix[i];
				i--;
			}
			else if(infix[i]=='('){			
			
			while(stack[top]!=')'){
					preFix[j]=pop();
					j++;
				}	
				char rem=pop();
				i--;
			}
			else{
				while(pre(stack[top])>=pre(infix[i])){
					preFix[j]=pop();
					j++;
				}
				push(infix[i]);
				i--;
			}
		}
	}
	
	while(top!=-1){
		preFix[j]=pop();
		j++;
	}
	int length=strlen(preFix);
	int k;
for(k=length-1;k>=0;k--)
	printf("%c",preFix[k]);
	printf("\t\t\t\t\t\tBY: KZS\n");
}
