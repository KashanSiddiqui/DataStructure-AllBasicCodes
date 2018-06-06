#include<stdio.h>
#include<conio.h>
#include<string.h>

// Structure Position
struct cordinates {
  int row;
  int col;
};

// solved N Queen Problem
 int solveNQueen(int n,int row,struct cordinates *cor){
   if(n==row){
    return 1;
   }
   else
   {
    for( int col =0; col<n ; col++){
     int safe = 1;
     for(int queen =0; queen < row; queen++){
      if((cor+queen)->col == col || (cor+queen)->row - (cor+queen)->col == row-col ||  (cor+queen)->row + (cor+queen)->col == row+col){
	 safe = 0;
	 break;
      }
     }
     if(safe){
      (cor+row)->row = row;
      (cor+row)->col = col;
      if(solveNQueen(n,row+1,cor)){
       return 1;
      }
     }
    }
   }
   return 0;
 }
 //Display
 void display(int n,struct cordinates *cor){
  printf("Co-Ordinate For Queen Placement.\n");
 
  for(int i =0; i<n ; i++){
   printf("[ %d , %d] \n",(cor+i)->row,(cor+i)->col);
  }
 
 }


 int main(){
 
 int k;
 int j=1;
 while(j!=2){
 printf("1)Queen game\n");
 printf("2)Logout\n");
 scanf("%d",&j);
 switch(j){
 	case 1:
 printf("\nEnter Numbers Of Queen:\n");
 scanf("%d",&k);
 if(k==2){
 	printf("No solution possible\n\n\n");
 	break;
 }

 struct cordinates cor[50];
 solveNQueen(k,0,cor);
 display(k,cor);
 j=1;
     break;
   case 2:
 	j=2;
 	  break;
 	  default:
 	  	printf("Not an Option\n");
}
}
 }
