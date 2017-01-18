#include <stdio.h>
#include <math.h>
void row_operations();
void print_matrix();
int main(void)
{
	int choice, i, j;
	int n=3;//no.of variables
/*Enter the coefficient of variables in equations in x1,x2,x3.......,b order*/
	float c[3][6], c1[3][6];
	printf("Enter elements\n");
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) 
			scanf("%f",&c[i][j]);
			
	}
	for(i=0;i<n;i++) {
			for(j=n;j<2*n;j++) {
			if(i==j%n) c[i][j]=1;
			else c[i][j]=0;
}
}
	float max,temp, temp1, x[n], sum;
	printf("\nAugmented matrix :\n\n");
	print_matrix(n,c);
	row_operations(n,c);
	printf("The matrix after the operation will be:\n\n"); 
	print_matrix(n,c);
	printf("inverse matrix is\n");
	for(i=0; i<n; i++) {
	        for(j=n; j<2*n; j++) {
	            printf("%f\t",c[i][j]);
        }
	printf("\n");
    }
   
}



void row_operations(int n,float c[n][2*n]) {
	int j;
	int i,k;
	float max,temp, temp1, x[n], sum;
	for(j=0; j<n; j++) {
        for(i=0; i<n; i++) {
            if(i!=j) {
                temp1=c[i][j]/c[j][j];
                for(k=0; k<2*n; k++)
                {
                    c[i][k]=c[i][k]-temp1*c[j][k];
                }
            }
        }
            	if(c[j][j] != 1) {
		for(k=2*n;k>j;k--) {
			c[j][k] = c[j][k]/c[j][j];
}
}
	printf("After row qperation:\n");//printing each row operations
	print_matrix(n,c);
	printf("\n");
	}
	}
	
void print_matrix(int n,float c[n][2*n]) {
	int i,j;
	for(i=0; i<n; i++) {
	        for(j=0; j<2*n; j++) {
	            printf("%f\t",c[i][j]);
        }
	printf("\n");
    }
}

