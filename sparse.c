#include<stdio.h>
int main(){
	int c,i,j,k;
	printf("Enter the number of rows and columns");
	int m, n;
	scanf("%d %d", &m, &n);
	int sparse [m][n];
	printf("Enter the elements of the matrix \n"); 
	for (i=0;i<n;i++) {
		for (j=0; j < n; j++){
			scanf("%d", &sparse [i][j]);
			if (sparse [i][j] != 0){
				c++;
			}
		}
	}
	int zeros=(m*n)-c; 
	if(zeros=((m*n)/2)){
		printf("It is a Sparse Matrix \n");
	}
	else{
		printf("It is not a Sparse Matrix \n");
	}
	int sparse_final[3][c];
	int c1 = 0;
	for(i=0;i<m;i++){
		for(j=0;j< n; j++){
			if (sparse[i][j]!=0){
				for (k = 0; k < 3; k++){
					if (k == 0){ 
						sparse_final[k][c1] = i;
					}
					else if(k==1){
						sparse_final[k][c1] = j;
					}
					else{
						sparse_final[k][c1] = sparse[i][j];
					}
					c1++;
				}
			}
		}
	}
	printf("The sparse matrix is ");
	for(i=0;i<3;i++){
		for(j=0;j<c;j++){
			printf(sparse_final[i][j]);
		}
		printf("\n");
	}
	return 0;
}

