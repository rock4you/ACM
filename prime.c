#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//�����ӷֽ� naive�汾 ����Ӧ��2^41���µ�����


int main()
{
    __int64 a, i, k=0, num[200], cishu[200], index=0;
    a=(__int64)pow(2,41)-1;

    memset(num, 0, sizeof(num));///����Ӧ����sizeof������200.�ǰ����ֽ����
    memset(cishu, 0, sizeof(cishu));

    for(i=2; (a>1)&&(i<(__int64)sqrt(a)+1); i++)
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
    printf("%I64d=",a);
    for(i=0; i<200; i++)
    {
        if(num[i]!=0)
            printf("%I64d(%I64d)", num[i], cishu[i]);
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
        printf("%I64d(%d)", a, 1);
    }
    return 0;
}
