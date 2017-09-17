#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int ifprime(long long n)//判断是否为素数
{
    long long i;
    int x=0;
    if(n==2||n==1)  return 1;
    else
    {
        for(i=2;i<=sqrt(n+0.0)+1;i++)
            if(n%i==0)
            {
                x=1;
                break;
            }
        if(x)
            return 0;
        else
            return 1;
    }
}


long long quick_mod(long long a, long long b, long long m)///a^b%m
{
    long long x=1;
    while(b)
    {
        if(b&1)//如果b是奇数
        {
            x=(x*a)%m;
            b--;
        }
        b/=2;
        a=a*a%m;
    }
    return x;

}

int main()
{
    long long n, a, p;
    while(1)
    {
        scanf("%lld %lld", &p, &a);
        if(p==0&&a==0)  return 0;
        else
        {
            if(ifprime(p))
                printf("no\n");
            else
            {
                long long ans=1;
                ans=quick_mod(a, p, p);
                if(ans==a)
                    printf("yes\n");
                else
                    printf("no\n");
            }
        }
    }
    return 0;

}
