#include<stdio.h>
#include<math.h>
float f(float x)
{
	return exp(x)-2*x-1;
}
main(void)
{
FILE *fp;
fp=fopen("n5.dat","w");
	int count=1;
	float x0,x1,err1=1,err2,oc,gx1=100,gx2;
	do{
		printf("Enter two approximations\n");
		scanf("%f%f",&x0,&x1);
	}
	while((f(x0)*f(x1))>0);
	printf("i\tx  \t f(x) \t   error\t  OC\n");
	do{
		err2=err1;
		gx2=gx1;
		gx1=(x0*f(x1)-x1*f(x0))/(f(x1)-f(x0));
		err1=gx2-gx1;
		if(err1<0)
		{
	    	err1*=-1;
	    }
		if(count<2)
		printf("%d   %f   %f\n",count,gx1,f(gx1));
		else{
			oc=log(err1)/log(err2);
			printf("%d   %f   %f   %f   %f\n",count,gx1,f(gx1),err1,oc);
		}
		err2=err1;
		if(gx1==0)
		{
			break;
		}
		if((f(x0)*f(gx1))<0)
		{
		    x1=gx1;
		}
		else
		{
		    x0=gx1;
		}
		count++;
	}
	while(err1>0.00005);
	printf("the root is=%f",gx1);
	fprintf(fp,"%f\t%f\n",gx1,f(gx1));
	fclose(fp);
}
