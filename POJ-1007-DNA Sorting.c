#include <stdio.h>

int main() {
    int n;//len of DNA
    int m;//num of DNA
    int i, j, k, t, mini, order;
    struct mychar{
        char str[50];
        int initorder;
        int inversion;
    };
    struct mychar DNA[100];
    scanf("%d %d", &n, &m);

    for (i=0;i<m;i++)
    {
        DNA[i].initorder=i+1;
        scanf("%s", &DNA[i].str);
        t=0;

        for(j=0;j<n;j++)
        {
            for(k=j+1;k<n;k++)
            {
                if(DNA[i].str[j]>DNA[i].str[k])
                {
                    t+=1;
                }
            }
        }
        DNA[i].inversion=t;
        //printf("inver=%d\n", DNA[i].inversion);
    }
    //printf("\n\n");

    for(i=0;i<m;i++)
    {
        mini=4951;
        for(j=0;j<m;j++)
        {

            if(DNA[j].inversion<mini)
            {
                mini=DNA[j].inversion;
                order=j;
            }
        }
        //printf("mini is:%d\n", mini);
        printf("%s\n",DNA[order].str);
        DNA[order].inversion=4951;
    }
    return 0;
}

/*
10 6
AACATGAAGG
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
CCCGGGGGGA
ATCGATGCAT
*/
