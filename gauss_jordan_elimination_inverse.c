#include<stdio.h>
float eq(int i, int j) {
	float equation1[3][6]={1,5,3,1,0,0,1,3,2,0,1,0,2,4,-6,0,0,1};
	return equation1[i][j];

}
void row_op(float equation2[3][6],int r_i, int r_j) {
	float equation3[3][6];
	int i,j;
	for(i=0;i<3;i++) {
		for(j=0;j<6;j++) {
			equation3[i][j]=equation2[i][j];
		}
	}	
	for(i=r_i;i<r_i+1;i++) {		
		for(j=0;j<6;j++) {
  			equation2[i][j]=equation3[r_j][j];
		}
	}	
	for(i=r_j;i<r_j+1;i++) {		
		for(j=0;j<6;j++) {
  			equation2[i][j]=equation3[r_i][j];
		}
	}
}
int main() {
	int i,j; float equ[3][6];
	int k=0,store=0,p;
	int I,J;
	for(i=0;i<3;i++) {
		for(j=0;j<6;j++) {
			equ[i][j]=eq(i,j);
		}
	}
		while(k<2) {
		for(p=0;p<2;p++) {
			store=p;
			if(eq(p,k)<eq(p+1,k)) {
				store=p+1;
	
			}
		}
		row_op(equ,store,k);
		for(i=0;i<3;i++) {
			for(j=0;j<6;j++) {
				printf("%f    ",equ[i][j]);
			}
		printf("\n");	
		}
	    I=k+1;
		float Mik=equ[I][k]/equ[k][k];
		J=k;
		while(I<3) {
			J=k;
			Mik=equ[I][k]/equ[k][k];
			while(J<6) {
				equ[I][J]=equ[I][J]-(equ[k][J]*Mik);
				J=J+1;
			}
			
			I=I+1;
		}
		k=k+1;
		printf("\n");
	}
	float temp;
	for(i=0;i<3;i++) {
		temp=1;
		for(j=0;j<6;j++) {
			if(i==j) {
				temp=equ[i][j];
			}
			equ[i][j]=equ[i][j]/temp;
		}
	}
	k=0;
	temp=1;J=0;I=0;
	int h=1;
	for(i=0;i<2;i++) {
		I=0;h=1;J=0;
		for(j=i+1;j<3;j++) {
			J=0;
			temp=equ[i][j];
			printf("temp= %f \n",temp);
				while(J<6) {
					float y=equ[i][J],z=temp*equ[h][J];	
					equ[i][J]=equ[i][J]-(temp*equ[j][J]);
					printf("%f = %f - %f \n",equ[i][J],y,z);
					J++;
				}
		}
	}
	printf("\n");
	for(i=0;i<3;i++) {
		for(j=0;j<6;j++) {
			printf("%f ",equ[i][j]);
		}
	printf("\n");	
	}		
}
