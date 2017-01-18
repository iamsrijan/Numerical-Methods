#include<stdio.h>
#include<math.h>


float func(float x){
	return x*x*x-x*x-x+1;
	}
float dfunc(float x){
	return 3*x*x-2*x-1;
	}
	float ddfunc(float x){
	return 6*x-2;
	}
int main()
{
		FILE *fp;
	fp=fopen("newton.txt","w+");
	float x1,x2,x3;
	printf("Enter the value of x1:");
	scanf("%f",&x1);
	int i=1;
		printf("\n\n");
  	
	double abserror,oc=0,e2=0,e1=0;
	if(fabs(func(x1)*ddfunc(x1)/(dfunc(x1)*dfunc(x1)))<1)
	{
	printf("\ni\t x1\t\t  x2\t 	abserror   \toc");
  	printf("\n\n");
	do{
	
		
		x2=x1-2*(func(x1)/dfunc(x1));
		x3=x1-(dfunc(x1)/ddfunc(x1));
	  e2=fabs(x2-x1);
		abserror=fabs(x2-x3);
	
	printf("\n%d 	%f	  %lf	%f    %lf",i,x1,x2,abserror,oc);
	fprintf(fp,"\n%f	%f",x1,x2);
	if(e1>0 && e2>0)
	{
	
		oc=fabs(log(e2)/log(e1));
	}
		e1=e2;
		x1=x2;
		  i++ ;
		
	}while(abserror>=0.0001);
		printf("\n\n\ndouble Root is %f", x2);
	printf("\nProgram converges after %d iterations",i-1);
}
else
printf("worng input");
	fclose(fp);
return 0;
}


