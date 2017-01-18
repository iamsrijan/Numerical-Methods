#include<stdio.h>
#include<math.h>
float f(float x)
{
	return  x*sin(x)+cos(x);
}
main(void)
{
    FILE *fp;
    fp=fopen("bisection.dat","w");
	int count=0,k=0;
	float a,b,m=0,err[100],m1,oc;
	printf("Enter lower bound and upper bound\n");
	scanf("%f%f",&a,&b);
	printf("\nitr no\t  Lb\t UB\t midpoint\t f(m)\t err \t   OC\n");
		if(f(a)*f(b)<0)
		{
	while(f(m)!=0){
		m1=m;
		m=(a+b)/2;
		err[k+1]=m1-m;
		if(err[k+1]<0)
			err[k+1]*=-1;
		oc=log(err[k+1])/log(err[k]);
		if(count<1)
			printf("%d | %f | %f | %f | %f | %f\n",count,a,b,m,f(m),err[k+1]);
		else
		    printf("%d | %f | %f | %f | %f | %f | %f \n",count,a,b,m,f(m),err[k+1],oc);
		if(err[k+1]<=0.000001)
			break;
		else if((f(m)*f(a))<0)
		    b=m;
		else
			a=m;
		count++;
		k++;
	}} 
	else
	printf("Error");
	fprintf(fp,"%f\t%f\t",m,f(m));
	fclose(fp);
	return 0;
}

