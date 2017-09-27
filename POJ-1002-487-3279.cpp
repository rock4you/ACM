#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

void delchar(char str[], char c)
{
    int i=0, j=0;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]=='A' || str[i]=='B' || str[i]=='C')
            str[i]='2';
        else if(str[i]=='D'||str[i]=='E' || str[i]=='F')
            str[i]='3';
        else if(str[i]=='G'||str[i]=='H' || str[i]=='I')
            str[i]='4';
        else if(str[i]=='J'||str[i]=='K' || str[i]=='L')
            str[i]='5';
        else if(str[i]=='M'||str[i]=='N' || str[i]=='O')
            str[i]='6';
        else if(str[i]=='P'||str[i]=='R' || str[i]=='S')
            str[i]='7';
        else if(str[i]=='T'||str[i]=='U' || str[i]=='V')
            str[i]='8';
        else if(str[i]=='W'||str[i]=='X' || str[i]=='Y')
            str[i]='9';
        if(str[i]!=c)
        {
            str[j]=str[i];
            j++;
        }

    }
    str[j]='\0';
}

int compare(const void *i, const void *j)
{
    return strcmp(*(char **)i, *(char(**))j);
}


void unvs(char a[])
{
    int i;
    for(i=6;i>2;i--)
    {
        a[i+1]=a[i];
    }
    a[3]='-';
    a[8]='\0';
}

int iseql(char a[], char b[])
{
    int i;
    for (i=0;a[i]!='\0'&&b[i]!='\0';i++)
    {
        if(a[i]!=b[i])
            return 0;
    }
    return 1;
}


int main()
{
    int i, n;
    scanf("%d", &n);
    char **a = (char **)malloc(sizeof(char *)*n);
    for(i=0;i<n;i++)
    {
        a[i]=(char *)malloc(sizeof(char )* 16);

    }
    for(i=0;i<n;i++)
    {
        scanf("%s",a[i]);
        delchar(a[i],'-');
        //change(a[i]);
    }

    qsort(a, n, sizeof(char *), compare);


    int* cnt = (int*)malloc(sizeof(int)*n);
    cnt[0]=1;
    int j=0;

    for(i=1;i<n;i++)
    {
        cnt[i]=0;
        if(!strcmp(a[i],a[j]))
        {
            cnt[j]++;
        }
        else
        {
            cnt[i]=1;
            j=i;
        }
    }

    for(i=0;i<n;i++)
        unvs(a[i]);

    int num=0;
    for(i=0;i<n;i++)
    {
        if(cnt[i]>1)
        {
            printf("%s %d\n", a[i], cnt[i]);
        }
        else
        {
            num++;
        }
    }
    if(num==n)
        printf("No duplicates. ");

    return 0;
}
