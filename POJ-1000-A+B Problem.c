#include<stdio.h>

int main()
{
    long long int a, b;
    while(scanf("%lld %lld", &a, &b)==2)
        printf("%lld", a+b);
    return 0;
}