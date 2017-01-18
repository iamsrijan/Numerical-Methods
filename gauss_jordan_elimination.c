#include<stdio.h>
float eq(int i, int j) {
	float equation1[4][5]={1,1,-1,1,2,2,1,1,-3,1,3,-1,-1,1,2,5,1,3,-2,7};
	return equation1[i][j];

}
void row_op(float equation2[4][5],int r_i, int r_j) {
	float equation3[4][5];
	int i,j;
	for(i=0;i<4;i++) {
		for(j=0;j<5;j++) {
			equation3[i][j]=equation2[i][j];
		}
	}	
	for(i=r_i;i<r_i+1;i++) {		
		for(j=0;j<5;j++) {
  			equation2[i][j]=equation3[r_j][j];
		}
	}	
	for(i=r_j;i<r_j+1;i++) {		
		for(j=0;j<5;j++) {
  			equation2[i][j]=equation3[r_i][j];
		}
		
	}	
}
int main() {
	int k=0,p,store=0;
	int i,j;
	int m,l;
	int flag=0;
	float equ[4][5];
	int I,J;
	float error=0.00001;
	for(i=0;i<4;i++) {                   
		for(j=0;j<5;j++) {
			equ[i][j]=eq(i,j);
		}
	}
	while(k<3) {
		for(p=0;p<3;p++) {
			store=p;
			if(eq(p,k)<eq(p+1,k)) {
				store=p+1;
	
			}
		}
		row_op(equ,store,k);
		for(i=0;i<4;i++) {
			for(j=0;j<5;j++) {
				printf("%f    ",equ[i][j]);
			}
		printf("\n");	
		}
	    I=k+1;
		float Mik=equ[I][k]/equ[k][k];
		J=k;
		while(I<4) {
			J=k;
			Mik=equ[I][k]/equ[k][k];
			while(J<5) {
				int z=equ[I][J];
				equ[I][J]=equ[I][J]-(equ[k][J]*Mik);
				J=J+1;
			}
			printf("\n");
			I=I+1;
		}
		k=k+1;
	}
		printf("\n");
		for(i=0;i<4;i++) {
			for(j=0;j<5;j++) {
				printf("%f    ",equ[i][j]);
			}
		printf("\n");	
		}	
	float X[4];	
	X[3]=equ[3][4]/equ[3][3];
	I=2;
	while(I>=0){
		J=I+1; float S=equ[I][4];
		while(J<4) {
			S=S-(equ[I][J]*X[J]);
			J=J+1;
		}
		X[I]=S/equ[I][I];
		I=I-1;
	}
	printf("\n Solution : \n");
	for(i=0;i<4;i++) {
		printf("%f    \n",X[i]);
	}	
}
