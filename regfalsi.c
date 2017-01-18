#include<stdio.h>
#include<math.h>
float f(float x)
{
	return x*sin(x)+cos(x);
}
main(void)
{
	int count=0,k=0;
	float a,b,c=0,d,err[100],oc,fa=0,fb=0;
	printf("Enter lower bound and upper bound\n");
	scanf("%f%f",&a,&b);
		printf("\nitr no\t Lb\t UB\t  c  \t    f(m)  \t err\t\t OC\n");
	if(f(a)*f(b)<0)
	{
while(f(c)!=0)
	{
		d=c;
		fa=f(a);
		fb=f(b);
		c=(a*f(b)-b*f(a))/(f(b)-f(a));
	    err[k+1]=c-d;
		if(err[k+1]<0)
			err[k+1]*=-1;
		oc=log(err[k+1])/log(err[k]);
		if(count<1)
			printf("%d | %f | %f | %f | %f | %f\n",count,a,b,c,f(c),err[k+1]);
		else
            printf("%d | %f | %f | %f | %f | %f | %f\n",count,a,b,c,f(c),err[k+1],oc);
		if(err[k+1]<0.000001)
			break;
		else if((f(a)*f(c))<0)
			b=c;
		else
			a=c;
		count++;
		k++;
	}}
	else
	printf("Error");
	return 0;
}
