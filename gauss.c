#include<stdio.h>
void input_matrix(float A[10][10]){
                        int i,j,n=4;
                        
                        printf("\nEnter the elements of augmented matrix row-wise:\n\n");
                        for(i=1; i<=n; i++)
                        {
                         for(j=1; j<=(n+1); j++)
                         {
                            printf("A[%d][%d] : ", i,j);
                            scanf("%f",&A[i][j]);
                         }
                      }
}
void guass_elimination(float A[10][10]){
           int i,n=4,j,k;
             float c,x[10],sum=0.0;
           for(j=1; j<=n; j++) /* loop for the generation of upper triangular matrix*/
            {
                      for(i=1; i<=n; i++)
                                  {
                                    if(i>j)
                        {
                                         c=A[i][j]/A[j][j];
                     for(k=1; k<=n+1; k++)
                                              {
                                A[i][k]=A[i][k]-c*A[j][k];
                                            }
                                    }
                                }
                           }
                           x[n]=A[n][n+1]/A[n][n];
                           /* this loop is for backward substitution*/
                           for(i=n-1; i>=1; i--)
                              {
                               sum=0;
                               for(j=i+1; j<=n; j++)
                                 {
                                    sum=sum+A[i][j]*x[j];
                               }
                               x[i]=(A[i][n+1]-sum)/A[i][i];
                           }
                           printf("\nThe solution is: \n");
                           for(i=1; i<=n; i++)
                             {
                               printf("\nx%d=%f\t",i,x[i]); /* x1, x2, x3 are the required solutions*/
                           }
                           printf("\n");
}

int main()			// Main function
{
    int n;
    float A[10][10];
    input_matrix(A);
    guass_elimination(A);
    return 0;
}
