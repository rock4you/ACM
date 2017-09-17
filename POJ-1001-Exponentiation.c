#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
95.123 12
0.4321 20
5.1234 15
6.7592  9
98.999 10
1.0100 12

548815620517731830194541.899025343415715973535967221869852721
.00000005148554641076956121994511276767154838481760200726351203835429763013462401
43992025569.928573701266488041146654993318703707511666295476720493953024
29448126.764121021618164430206909037173276672
90429072743629540498.107596019456651774561044010001
1.126825030131969720661201
*/

void mult(char *result, char a[], char b[])
//字符数组格式的浮点数a 乘以字符数组格式的浮点数b 结果存在字符数组result中
{
    int i,j, xx, yy, zz, p, a_n_aft_pnt, b_n_aft_pnt;
    int a_len, b_len;
    int carry[110];
    int num[110];
    char aa[110], bb[110];

    for(i=109; i>0; i--)//计算浮点数a含有小数点时的长度,如1.2345的长度为6
    {
        if(a[i]!='0'&&a[i]!='\0')
        {
            a_len=i;
            break;
        }
    }
    
    for(i=109; i>0; i--)//计算浮点数b含有小数点时的长度,如1.2345的长度为6
    {
        if(b[i]!='0'&&b[i]!='\0')
        {
            b_len=i;
            break;
        }
    }

    for(i=0; i<110; i++)//初始化
    {
        aa[i]='0';
        bb[i]='0';
        carry[i]=0;
        num[i]=0;
    }

    for(i=1,j=a_len; j>0; j--)//将浮点数a倒序放入数组aa 并丢弃小数点
    {
        if(a[j]!='.')
        {
            aa[i]=a[j];
            i++;
        }
        else
        {
            a_n_aft_pnt=a_len-j;
        }
    }
    
    for(i=1,j=b_len; j>0; j--)//将浮点数b倒序放入数组bb 并丢弃小数点
    {
        if(b[j]!='.')
        {
            bb[i]=b[j];
            i++;
        }
        else
        {
            b_n_aft_pnt=b_len-j;//num after point
        }
    }

	//浮点数乘法 a*b 存入num, carry是进位
    for(i=1; i<a_len; i++)//a[i]
    {
        for(j=1; j<b_len; j++)//b[j]
        {
            xx=num[i+j-1];
            yy=carry[i+j-1];
            zz=(aa[i]-'0')*(bb[j]-'0');
            p=xx+yy+zz;
            num[i+j-1]=p%10;
            carry[i+j]=p/10;
            carry[i+j-1]=0;
        }
        num[i+j-1]=carry[i+j-1];
        carry[i+j-1]=0;
    }


    for(i=109; i>0; i--)//从右至左找到第一个不为零的下标
    {
        if(num[i]!=0)
        {
            break;
        }

    }
    int index=0;
    int w=1;


    if(i<(a_n_aft_pnt+b_n_aft_pnt))//如果该下标已经错过了小数点，就应该先把0.00打印出来
    {
        *(result+1)='0';
        *(result+2)='.';
        int t= (a_n_aft_pnt+b_n_aft_pnt)-i;
        for(w=3; w<t+3; w++)
        {
            *(result+w)='0';
        }
        for(i; i>0; i--)
        {
            *(result+w)=num[i]+'0';
            w++;
        }

    }
    else if(i==(a_n_aft_pnt+b_n_aft_pnt))//如果该下标行号在小数点的位置，就应该先把0.打印出来
    {
        *(result+1)='0';
        *(result+2)='.';
        w=3;
        for(i; i>0; i--)
        {
            *(result+w)=num[i]+'0';
            w++;
        }
    }
    else//如果该下标还没到小数点的位置，就应该先打印小数点之前的数，到了小数点的位置再打印小数点
    {
        w=1;
        for(i; i>0; i--)
        {

            if(i==(a_n_aft_pnt+b_n_aft_pnt))
            {
                *(result+w)='.';
                w++;
                *(result+w)=num[a_n_aft_pnt+b_n_aft_pnt]+'0';
                w++;
            }
            else
            {
                *(result+w)=num[i]+'0';
                w++;
            }

        }
    }

    if(a_n_aft_pnt+b_n_aft_pnt==0)//如果a和b都是整数，则存储的时候要补充一个小数点，然后紧跟着'\0'
    {
        *(result+w)='.';
        w++;
        *(result+w)='\0';
    }

    else
        *(result+w)='\0';


/*
    for(i=1; *(result+i)!='\0'; i++)
    {
        printf("%c", *(result+i));
    }
    printf("\n");
*/
}

int main()

{
    float r;
    int i, n;

    char result[110],a[110];
    for(i=0; i<110; i++)
    {
        a[i]='0';
        result[i]='0';
    }
    result[1]='1';
    result[2]='.';
    result[3]='0';
    while(scanf("%f%d", &r, &n)!=EOF)
    {
        //gcvt(r, 6, &a[1]);

        sprintf(&a[1],"%6f",r);//将浮点数转换为字符数组，从a[1]开始存储，a[0]用不到。
        for(i=7;i<110;i++)
            a[i]='0';
        /*
        for(i=0; i<20; i++)
        {
            printf("%c ", a[i]);
        }
        printf("\n");*/
        while(n)
        {
            if(n&1)
            {
                mult(result, result, a);
            }


            n>>=1;
            if(n>0)
                mult(a, a, a);//if (n>>=1)>0 then do this
        }
        //printf("Result is:");
        if(result[1]!='0')
            printf("%c", result[1]);
        for(i=2; result[i]!='\0'; i++)
        {
            if(result[i]=='.'&&result[i+1]=='\0')//对于两个整数相乘的结果，一定是.之后紧跟着'\0',这时候按照题目要求，不打印小数点
                break;
            else
                printf("%c", result[i]);
        }
        printf("\n");

        for(i=0; i<110; i++)
        {
            a[i]='0';
            result[i]='0';
        }
        result[1]='1';
        result[2]='.';
        result[3]='0';
    }
    return 0;
}
