#include <stdio.h>
#include <string.h>

void cc()
{
    int i, cnt;
    char a[10000];
    gets(a);
    for(i = 0; i < strlen(a); i++)
        {
            cnt = 0;
            while(a[i] == a[i + 1])
            {
                cnt++;
                i++;
            }
            if(cnt != 0) printf("%d", cnt + 1);
            printf("%c", a[i]);
        }
}

void dd()
{   int i, j, cnt;
    char a[10000];
    gets(a);
    for(i = 0; i < strlen(a); i++)
        {
            cnt = 0;
            while(a[i] >= '0' && a[i] <= '9')
                cnt = 10 * cnt + a[i++] - '0';
            for(j = 0; j < cnt; j++)
                printf("%c", a[i]);
            if(cnt == 0)
                printf("%c", a[i]);
        }
}

int main()
{
    char cm;

    scanf("%c", &cm);
    getchar();
    if(cm == 'C') cc();
    else if(cm == 'D') dd();
    return 0;
}
