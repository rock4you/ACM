#include<stdio.h>

int main()
{
    int i=0;
    float a[12];
    float s=0;
    for(i=0;i<12;i++)
    {
        scanf("%f", &a[i]);
        s+=a[i];
    }
    printf("$%.2f", s/12);
    return 0;

}
