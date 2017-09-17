#include<stdio.h>


int main()
{
    int i=2;
    float s=0;
    float c;
    while(1)
    {
        scanf("%f", &c);
        if(c==0)
            return 0;
        else
        {
            while(s<c)
            {
                s+=1.000/i;
                i++;
            }
            printf("%d card(s)\n", i-2);
            i=2;
            s=0;

        }
    }

}
