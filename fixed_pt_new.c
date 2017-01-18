#include <stdio.h>
#include <math.h>
float f(float x){
    return 2*x-cos(x)-3;
    }
float g(float x){
    return 2+sin(x);
    }
float dg(float x){
    float g1x;
    g1x=cos(x);
    if(g1x<0)
    {
        g1x*=-1;
    }
    return g1x;
    }
    main (void)
    {
    FILE *fp;
    fp=fopen("n3a.dat","w");
        int count=1;
        float x0, x1, err1=1, err2,oc;
        do{
            printf("enter the first guess:");
            scanf("%f",&x0);
    }
        while(dg(x0)>=1);
        printf("i\tx\tg'(x)\t f(x)\t error\t order of convergence\n");
        do{
            x1=g(x0);
            err2=err1;
            err1=x1-x0;
            if(err1<0)
            err1*=-1;
            if (count<2)
            printf("%d   %f    %f    %f\n",count,x0,dg(x0),f(x0));
        else
        {
            oc=log(err1)/log(err2);
            printf("%d  %f    %f    %f   %f  %f\n",count,x0,dg(x0),f(x0),err1,oc);
        }
        x0=x1;
        count++;
        }
    while(err1>0.000005);
    printf("the root is=%f",x0);
    fprintf(fp,"%f\t%f\n",x0,f(x0));
    fclose(fp);
    return 0;
    
}
