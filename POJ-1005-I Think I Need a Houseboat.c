#include<stdio.h>
#include<math.h>
#define pi 3.14159265

int main()
{
    float r;
    float x, y;
    int i;
    int n;
    int year;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%f %f", &x, &y);
        r=sqrt(x*x+y*y);
        year=ceil(pi*r*r/100);
        printf("Property %d: This property will begin eroding in year %d.\n", i+1, year);
    }
    printf("END OF OUTPUT.");
    return 0;

}
