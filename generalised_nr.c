#include <stdio.h>
#include <math.h>
float fx(float x)
	{
		return (pow(x,3) - 2*pow(x,2) - 4*x +8);      //creating fx function 
	}
float dfx(float x)
	{
		return (3*pow(x,2) -4*x - 4);                 // creating Differentiation of fx function 
	}
/*float ddfx(float x)
	{
		return (exp(x));
	}*/
int main(void)
	{	FILE *fp1,*fp2;
		fp1 = fopen("out1.txt","w+");
		fp2 = fopen("out2.txt","w+");
		int i=0;
		float xn,x0,abs_error,e[10],prove;            //initialising the variables
		x0 = 1.2;e[0]=10;
		printf("i\txi\t\tf(xi)\t\tabs_error\torder\n");
		printf("%d\tx%d=%1.3f\tf(x%d)=%1.3f\n",i+1,i+1,x0,i+1,fx(x0));
		do{
				
				xn = x0 - 2*fx(x0)/dfx(x0);             // changing newton raphson formula by multiplying by root
				abs_error = fabs(xn - x0);              // value of error
				//prove = fx(x0)*ddfx(x0)/dfx(x0)*dfx(x0);
				i++;
				e[i] = fabs(xn - x0);
				x0 = xn;
				fprintf(fp1,"%d\tx%d=%1.3f\tf(x%d)=%1.3f\t%f\t%f\n",i,i,x0,i,fx(x0),abs_error,(log(e[i])/log(e[i-1])));
				fprintf(fp2,"%1.3f\t%1.3f\n",x0,fx(x0));
				printf("%d\tx%d=%1.3f\tf(x%d)=%1.3f\t%1.3f\t\t%1.3f\n",i,i,x0,i,fx(x0),abs_error,(log(e[i])/log(e[i-1])));
				//printf("%f\n",prove);
		}while(abs_error >0.00001);                            // condition
		fclose(fp1);
		fclose(fp2);
		//getch();
		return 0;
}
