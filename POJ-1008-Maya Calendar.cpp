#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;



int main()
{
    int i, j, n, num, day;
    scanf("%d", &n);
    char *Haab[19]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    char *tzol[20]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
    char month[10];
    char tmp;
    int year;
    int m;
    int total;
    int tzoyear, tzomonth, tzoday;
    //freopen("a.out","w",stdout);
    printf("%d\n", n);
    for(i=0;i<n;i++)
    {
        scanf("%d %c %s %d", &num, &tmp, month, &year);
        //printf("\n%d %s %d", num, month, year);
        for(j=0;j<19;j++)
        {
            if(!strcmp(month, Haab[j]))
            {
                m=j;
                j=19;
            }
        }
        total=year*365+m*20+num;
        tzoyear=total/260;
        tzoday=total%260;

        tzomonth=tzoday%20;
        tzoday=tzoday%13+1;

        printf("%d %s %d\n", tzoday, tzol[tzomonth], tzoyear);

    }
    //fclose(stdout);
    return 0;
}
