#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void display(int matrix [5][5],int No_Ofvertices){
	
printf("\nMatrix is\n");

for(int i=0; i<No_Ofvertices;i++){

for (int j=0;j<No_Ofvertices;j++){

printf("value at %d row  %d column is %d\n",i,j,matrix[i][j]);	
}
}	

}
int index(int vertex,int* arr,int No_Ofvertices){
	
	int i;
	
	for (i=0;i<No_Ofvertices;i++){
		
		if(arr[i]==vertex){
			
			break;
		}
	}
	
	return i;	
}

void Adjacent (int vertex,int * arr,int No_Ofvertices,int matrix [5][5]){
	
	int row =index(vertex,arr,No_Ofvertices);
	int index=0;
	int Adjacent [No_Ofvertices];
	
	for(int j=0;j<No_Ofvertices;j++){
		
		if(matrix[row][j]==1){
			
			
			Adjacent[index]=j;
			index++;
		}
	}
	
	if(index!=0){
	
	printf("\nAdjacent Vertices Are\n");
	for (int i=0;i<index;i++){
		
	int ind	=Adjacent[i];
	
	printf("%d\n",arr[ind]);
	
}
	}
	else{
		
		printf("\nVertex %d does not possess any Adjacent Vertex\n",vertex);
	}
}

void insertEdge (int vertex1, int vertex2,int *arr,int No_Ofvertices,int matrix[5][5]){
	
	int row = index(vertex1,arr,No_Ofvertices);
	int col= index(vertex2,arr,No_Ofvertices);
	matrix[row][col]=1;
	matrix[col][row]=1;
	
	
}

void deleteEdge (int vertex1, int vertex2,int *arr,int No_Ofvertices,int matrix[5][5]){
	
	int row = index(vertex1,arr,No_Ofvertices);
	int col= index(vertex2,arr,No_Ofvertices);
	matrix[row][col]=0;
	matrix[col][row]=0;
	
	
}

int main(){

int vertex1,vertex2;

int No_Ofvertices;

printf("How many Vertices you want to create\n");
scanf("%d",&No_Ofvertices);	

int size = 4*(No_Ofvertices);

int *arr= (int*)malloc(No_Ofvertices *sizeof(int));

int matrix [5][5];

int count=0;
int i;

for(i=0; i<5;i++){

printf("Enter data for %d Vertices\n",++count);
scanf("%d",&arr[i]);
		
}

printf("Vertices are\n");

for(int i=0; i<No_Ofvertices;i++){

printf("%d\n",arr[i]);	
}

for(int i=0; i<5;i++){

for (int j=0;j<5;j++){

matrix[i][j]=0;
}
}
bool logout=true;
while(logout==true){

int num;
int choice;
int cont,repeat,data;

printf("\nSelect Menu!\n");
printf("1.Insert Edge\n2.Delete Edge\n3.Display\n4.Adjacent Vertex\n5.Logout\n");
printf("\nYour Selection is :");
scanf("%d",&choice);

switch(choice){
	
	case 1:

		printf("\nEnter the starting vertex\n");
		scanf("%d",&vertex1);
		printf("\nEnter the Adjacent vertex\n");
		scanf("%d",&vertex2);
		insertEdge (vertex1,vertex2,arr,No_Ofvertices,matrix);

	
	break;
	
	case 2 :
		
		printf("\nEnter the starting vertex\n");
		scanf("%d",&vertex1);
		printf("\nEnter the Adjacent vertex\n");
		scanf("%d",&vertex2);
		deleteEdge (vertex1,vertex2,arr,No_Ofvertices,matrix);
	
	break;
	
	case 3 :
	
		display(matrix,No_Ofvertices); 

	break;
	
	case 4:
		
		printf("\nEnter the starting vertex\n");
		scanf("%d",&vertex1);
	    Adjacent (vertex1,arr,No_Ofvertices,matrix);
		
	break;
	case 5:
		logout=false;
		break;
	default :
		
	printf("Invalid Selection!\n");
}

}
	
	
}
