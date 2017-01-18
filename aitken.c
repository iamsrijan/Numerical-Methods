#include<stdio.h>
#include<math.h>

float func(float x){
	return 2*x-cos(x)-3;
	}
float nextfunc(float x){
	return 0.5*(cos(x)+3) ;
	}
int main()
{
		FILE *fp;
	fp=fopen("aitken.txt","w+");
		float x1,x2;
	printf("Enter the value of x1:");
	scanf("%f",&x1);
			int i=1;
		printf("\n\n");
  	printf("\ni\t x1\t\t  x2\t 	abserror   \toc");
  	printf("\n\n");
	double abserror,oc=0,e2=0,e1=0,k,delx=0,a,b,c,del2x=0;
	do
	{
		
		
		x2=nextfunc(x1);
		delx=x2-x1;
		if(i>=2)
		{
			del2x=x2-2*b+a;
			x2=x2-(delx*delx)/del2x;
		}
		a=x1;
		b=x2;
		
		e2=fabs(x2-x1);
		abserror=fabs(e2-e1);
		printf("\n%d 	%f	  %lf	%f    %lf",i,x1,x2,abserror,oc);
		fprintf(fp,"\n%f	%f",x1,x2);
	if(e1 && e2)
	{
	
		oc=fabs(log(e2)/log(e1));
	}
		e1=e2;
		
		x1=x2;
		i++ ;
	}while(e2>=0.001);
		
	printf("\nProgram converges after %d iterations",i-1);
		fclose(fp);
	return 0;
}

