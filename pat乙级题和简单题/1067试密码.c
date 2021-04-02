#include <stdio.h>
#include <string.h>

int main()
{
    int N, i, len1, cnt = 0, len2;
    char password[21], temp[100];

    scanf("%s %d", password, &N);
    getchar();
    len1 = strlen(password);
    while(1)
    {
        gets(temp);
        len2 = strlen(temp);
        if(*temp == '#' && len2 == 1)
            break;
        if( len1 != len2)
        {
            printf("Wrong password: %s\n", temp);
            cnt++;
        }
        else
        {
            for(i = 0; *(temp + i) && *(temp + i) == *(password + i); i++);
            if(i != len1)
            {
                printf("Wrong password: %s\n", temp);
                cnt++;
            }
            else
            {
                printf("Welcome in\n");
                break;
            }
        }
        if(cnt == N)
        {
            printf("Account locked\n");
            break;
        }
    }
    return 0;
}
