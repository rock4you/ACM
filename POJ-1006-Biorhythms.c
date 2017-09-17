///POJ_1006_Biorhythms
///Solution:一次同余方程组--孙子定理
//23, 28, 33
#include<stdio.h>

int main()
{
    int p, e, i, d, temp;
    int x=0;
    int m=21252, M1=924, M2=759, M3=644;
    int M1_=6, M2_=19, M3_=2;
    int j=1;
    while(1)
    {
        scanf("%d %d %d %d", &p, &e, &i, &d);
        if(p==-1&&e==-1&&i==-1&&d==-1)  return 0;
        x=(((((M1%m)*(M1_%m))%m)*(p%m))%m+((((M2%m)*(M2_%m))%m)*(e%m))%m+((((M3%m)*(M3_%m))%m)*(i%m))%m)%m;
        temp=x;
        if(x==0)
            x=21252;
        x=x-d;
        if(x<0)
            x=21252-d+temp;
        printf("Case %d: the next triple peak occurs in %d days.\n", j, x);
        j++;
    }
    return 0;
}
