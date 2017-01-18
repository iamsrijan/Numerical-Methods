#include<stdio.h>
#include<math.h>
float f(float x){
	return exp(x)-2*x-1;
}
float df(float x){
	return exp(x)-2;
}
float ddf(float x){
    return exp(x);
}
main(void)
{
	int count=1;
	float a,b,err,prv_err,oc;
	do
	{
	printf("enter the initial value:");
	scanf("%f",&a);
	}
	while(((f(a)*ddf(a))/(df(a)*df(a)))>=1);
	printf("\nitr no\tx\t f(x) \terr\t OC\n");
    do
	{
		prv_err=err;
		b=a-(f(a)/df(a));
		err=b-a;
		if(err<0)
			err*=-1;
		oc=log(err)/log(prv_err);
		if(count<2)
			printf("%d |%.4f | %.4f\n",count,a,f(a));
		else
			printf("%d |%.4f | %.4f | %.4f |%.4f\n",count,a,f(a),err,oc);
		a=b;
		count++;
	}
	while(err>=0.00005);
	return 0;
}
