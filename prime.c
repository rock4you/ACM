#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//�����ӷֽ� naive�汾 ����Ӧ��2^63���µ�����
typedef unsigned __int64 xint;

int main()
{
    xint a, i, k=0, num[200], cishu[200], index=0;
    a=(xint)pow(2,63)-1;

    memset(num, 0, sizeof(num));///����Ӧ����sizeof������200.�ǰ����ֽ����
    memset(cishu, 0, sizeof(cishu));
    printf("%I64d=",a);
    for(i=2; (a>1)&&(i<(xint)sqrt(a)+1); i++)
    {
        if(a%i==0)
        {
            index++;
            num[k]=i;
            cishu[k]=1;
            a=a/i;
            while(a%i==0)
            {
                cishu[k]+=1;
                a=a/i;
            }
            k++;
        }
    }

    for(i=0; i<200; i++)
    {
        if(num[i]!=0)
            printf("%I64u(%I64u)", num[i], cishu[i]);
        if(index>1)
        {
            printf("*");
            index--;
        }
    }
    if(a!=1)
    {
        if(index==1)
            printf("*");
        printf("%I64u(%d)", a, 1);
    }
    return 0;
}
