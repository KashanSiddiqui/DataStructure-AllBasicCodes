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
struct treeNode *temp =*parent;
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
		return;
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
		return;
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
		return;
	}
	else{
		
		inOrder(&(temp->left));
		printf("%d \t",temp->key);
		inOrder(&(temp->right));
		
		
	}
}
delete(struct treeNode **del,int key){
	struct treeNode *temp=*del;
	struct treeNode *currentNode=NULL;
	struct treeNode *parentNode=NULL;
	search(&temp,key,&currentNode,&parentNode);
	
	if(currentNode->left==NULL && currentNode->right==NULL){
		if(currentNode->key >= parentNode->key){
			parentNode->right=NULL;
		}
		else{
			parentNode->left=NULL;
		}
		free(currentNode);
	}
	
	else if(currentNode->left!=NULL && currentNode->right==NULL){
		if(currentNode->key >= parentNode->key){
			parentNode->right=currentNode->left;
		}
		else{
			parentNode->left=currentNode->left;
		}
		free(currentNode);
	}
	
	else if(currentNode->left==NULL && currentNode->right!=NULL){
		if(currentNode->key >= parentNode->key){
			parentNode->right=currentNode->right;
		}
		else{
			parentNode->left=currentNode->right;
		}
		free(currentNode);
	}
	
	else{
		struct treeNode *temp1=currentNode->right;
		minimumNumber(&temp1);
		if(currentNode->key >= parentNode->key){
			parentNode->right=currentNode->right;
			temp1->left=currentNode->left;
		}
		else{
			parentNode->left=currentNode->right;
			temp1->left=currentNode->left;
		}
		free(currentNode);		
	}
	
}
int search(struct treeNode **root,int key,struct treeNode **current,struct treeNode **parent){
	struct treeNode *temp=*root;
	if(temp==NULL){
		printf("Value Not Found\n\n");
		return 0;
	}
	//else{
		else if(temp->key==key){
			*current=&temp;
			printf("Current : ");
			printf("%d\n",temp->key);
			return 1;
		}
		else if(key > temp->key){
			int check=search(&(temp->right),key,&(*current),&(*parent));
			if(check){
				*parent=&temp;
				printf("Parent : ");
				printf("%d\n",temp->key);
				return NULL;
			}
		}
		else if(key < temp->key){
			int check=search(&(temp->left),key,&(*current),&(*parent));
			if(check){
				*parent=&temp;
				printf("Parent : ");
				printf("%d\n",temp->key);
				return NULL;
			}
		}
	//}
	
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
			printf("Maximum Number : ");
			printf("%d\n\n",temp->key);
			return NULL;
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
		int check=minimumNumber(&(temp->left));
		if(check){
			printf("Maximum Number : ");
			printf("%d\n\n",temp->key);
			return NULL;
		}
	}
}


int main(){
	struct treeNode *root;
	struct treeNode *current=NULL;
	struct treeNode *parent=NULL;
	root=NULL;
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
				insert(&root,a);
				break;
			case 2:
//				search(&root,a,&current,&parent);
				printf("Enter Number:\n");
				scanf("%d",&a);
				delete(&root,a);
//				printf("\n=====================================================\n");
//				printf("\nYou are not Allowed to Cut Tree due to Global Warming <--\n");
//				printf("\n\tMORE TREE LESS GLOBAL WARMING");
//				printf("\n=====================================================\n");
				break;
			case 3:
				
			printf("\n=====================================================\n");	
				printf("\nPre Order = \t");
	            preOrder(&root);
				printf("\nPost Order = \t");
				postOrder(&root);
				printf("\nIn Order= \t");
				inOrder(&root);
				printf("\n=====================================================\n");
				break;
			case 4:
				maxNumber(&root);
				break;
			case 5:
				minimumNumber(&root);
				break;
			case 6:
				
				printf("Enter Number:\n");
				scanf("%d",&a);
				search(&root,a,&current,&parent);
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
