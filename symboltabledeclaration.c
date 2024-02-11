#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
void main()
{
 int x=0, n, i=0,j=0;
 void *mypointer,*T4Tutorials_address[5];
 char ch,T4Tutorials_Search,T4Tutorials_Array2[15],T4Tutorials_Array3[15],c;
 printf("Input the expression ending with $ sign:");
 while((c=getchar())!='$')
 {
  T4Tutorials_Array2[i]=c;
  i++;
 }
 n=i-1;
 printf("Given Expression:");
 i=0;
 while(i<=n)
 {
  printf("%c",T4Tutorials_Array2[i]);
  i++;
 }
 printf("\n Symbol Table display\n");
 printf("Symbol \t addr \t type");
 while(j<=n){
    c=T4Tutorials_Array2[j];
  if(isalpha(toascii(c)))
  {
   mypointer=malloc(c);
   T4Tutorials_address[x]=mypointer;
   T4Tutorials_Array3[x]=c;
   printf("\n%c \t %d \t identifier\n",c,mypointer);
   x++;
   j++;
  }
  else
  {
   ch=c;
   if(ch=='+'||ch=='-'||ch=='*'||ch=='=')
   {
    mypointer=malloc(ch);
    T4Tutorials_address[x]=mypointer;
    T4Tutorials_Array3[x]=ch;
    printf("\n %c \t %d \t operator\n",ch,mypointer);
    x++;
    j++;
   }
   }
   }
}
