#include<stdio.h>
int main(){
    int arr1[100],arr2[100],Union[100],intersection[100],i,j,k,n1,n2;
    printf("ENTER THE NUMBER OF ELEMENTS OF ARRAY 1 ");
    scanf("%d",&n1);
    printf("Enter element of array 1\n");
    for(i=0;i<n1;i++){
        scanf("%d",&arr1[i]);
    }
    printf("ENTER THE NUMBER OF ELEMENTS OF ARRAY 2 ");
    scanf("%d",&n2);
    printf("Enter element of array 2\n");
    for(i=0;i<n2;i++){
        scanf("%d",&arr2[i]);
    }
    j=0;
    for(i=0;i<n1;i++){
    	Union[j]=arr1[i];
    	j++;
    }
    j=n1;
    
    for(i=0;i<n2;i++){
    	Union[j]=arr2[i];
    	j++;
    }
    printf("UNION \n");
    for(i=0;i<(n1+n2);i++){
    	printf("%d \t",Union[i]);
	}
	
	k=0;
   for(i=0;i<n1;i++){
      for(j=0;j<n2;j++){
         if(arr1[i]==arr2[j]){
            intersection[k]=arr1[i];
            k++;
         }
      }
   }
	int removerepeated(int size,int arr1[]){
   int i,j,k;
   for(i=0;i<size;i++){
      for(j=i+1;j<size;){
         if(arr1[i]==arr1[j]){
            for(k=j;k<size;k++){
               arr1[k]=arr1[k+1];
            }
            size--;
         }else{
            j++;
         }
      }
   }
   return(size);
}
	int size=removerepeated(k,intersection);
   printf("\nArray after intersection\n");
   if(size>0){
      for(i=0;i<size;i++){
         printf("%d\n",intersection[i]);
      }
   }else{
      printf("No intersection\n");
   }
		
    return 0;
}
