#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
struct treeNode{
	struct treeNode *left;
	struct treeNode *right;
	int key;
};

void insert(struct treeNode **parent,int key){
struct treeNode *temp;
    temp=*parent;
	if(temp==NULL){
		temp=(struct treeNode*)malloc(sizeof(struct treeNode));
		temp->key=key;
		temp->left=NULL;
		temp->right=NULL;
		*parent = temp;
	}
	else{
		if(key < temp->key){
			insert(&(temp->left),key);
		}
		else{
			insert(&(temp->right),key);
		}
	}
	return;
}
preOrder(struct treeNode **parent){
	struct treeNode *temp;
	temp =*parent;
	if(*parent==NULL){
		return NULL;
	}
	else{
		
		printf("%d \t",temp->key);
		preOrder(&(temp->left));
		preOrder(&(temp->right));
	}
}
postOrder(struct treeNode **parent){
	struct treeNode *temp;
	temp =*parent;
	if(*parent==NULL){
		return NULL;
	}
	else{
		
		postOrder(&(temp->left));
		postOrder(&(temp->right));
		
		printf("%d \t",temp->key);
	}
}
inOrder(struct treeNode **parent){
	struct treeNode *temp;
	temp =*parent;
	if(*parent==NULL){
		return NULL;
	}
	else{
		
		inOrder(&(temp->left));
		printf("%d \t",temp->key);
		inOrder(&(temp->right));
		
		
	}
}

delete(struct treeNode **del,int key){
	struct treeNode *urado=*del;
	
}
int maxNumber(struct treeNode **parent){
	struct treeNode *temp;
	temp=*parent;
	if(temp==NULL){
		return 1;
	}
	else{
		int check=maxNumber(&(temp->right));
		if(check){
			printf("%d",temp->key);
			break;
		}
	}
}
int minimumNumber(struct treeNode **parent){
	struct treeNode *temp;
	temp=*parent;
	if(temp==NULL){
		return 1;
	}
	else{
		int check=maxNumber(&(temp->left));
		if(check){
			printf("%d",temp->key);
			break;
		}
	}
}


int main(){
	struct treeNode *parent;
	parent=NULL;
	int choice;
	while(choice!=7){
	printf("\t\tTREE\n");
	printf("Choose One\n\n");
	printf("1)Insert\n");
	printf("2)Delete\n");
	printf("3)Display\n");
	printf("4)Maximum Number\n");
	printf("5)Minimum Number\n");
	printf("6)Search\n");
	printf("7)Logout\n\n");
	printf("\t\t\t\t\t\tBY: KZS\n");
	int option;
	int a;
	scanf("%d",&option);
	system("cls");
		switch(option){
			case 1:
				
				printf("Enter Number:\n");
				scanf("%d",&a);
				insert(&parent,a);
				break;
			case 2:
				printf("\n=====================================================\n");
				printf("\nYou are not Allowed to Cut Tree due to Global Warming <--\n");
				printf("\n\tMORE TREE LESS GLOBAL WARMING");
				printf("\n=====================================================\n");
				break;
			case 3:
				
			printf("\n=====================================================\n");	
				printf("\nPre Order = \t");
	            preOrder(&parent);
				printf("\nPost Order = \t");
				postOrder(&parent);
				printf("\nIn Order= \t");
				inOrder(&parent);
				printf("\n=====================================================\n");
				break;
			case 4:
				maxNumber(&parent);
				break;
			case 5:
				minimumNumber(&parent);
				break;
			case 7:
				choice=7;
				break;
			default:
			printf("Wrong Input or Option Under Construction :) \n\n");
					
		}
		
	
//	insert(&parent,4);
//	insert(&parent,5);
//	insert(&parent,7);
//	insert(&parent,1);
//	insert(&parent,8);
//	insert(&parent,2);
//	insert(&parent,6);
//	insert(&parent,3);
	

		}
	}
