#include <stdio.h>
#include <string.h>

int main()
{
    int N, len, i, flagmath, flagchar, flag;
    char a[81], *p;

    scanf("%d", &N);
    getchar();
    for(i = 0; i < N; i++)
    {
        gets(a);
        len = strlen(a);
        if(len < 6)
            printf("Your password is tai duan le.\n");
        else
        {
            p = a; flagmath = 0; flagchar = 0; flag = 0;
            while(*p)
            {
                if(*p >= '0' && *p <= '9') flagmath = 1;
                else if((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) flagchar = 1;
                else if(*p == '.');
                else
                {
                    flag = 1;
                    printf("Your password is tai luan le.\n");
                    break;
                }
                p++;
            }
            if(!flag && flagmath && !flagchar)
                printf("Your password needs zi mu.\n");
            if(!flag && !flagmath && flagchar)
                printf("Your password needs shu zi.\n");
            if(!flag && flagmath && flagchar)
                printf("Your password is wan mei.\n");
        }
    }
    return 0;
}
