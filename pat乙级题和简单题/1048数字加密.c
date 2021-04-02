#include <stdio.h>
#include <string.h>

int main()
{
    int i, len1, len2, m;
    char a[101], b[101], c[101];

    scanf("%s", a);
    getchar();
    scanf("%s", b);
    len1 = strlen(a);
    len2 = strlen(b);
    if(len1 != len2)
    {
        if(len1 > len2)
        {
            for(i = 0; i < len1 - len2; i++)
                c[i] = '0';
            c[i] = '\0';
            strcat(c, b);
            strcpy(b, c);
        }
        else
        {
            for(i = 0; i < len2 - len1; i++)
                c[i] = '0';
            c[i] = '\0';
            strcat(c, a);
            strcpy(a, c);
        }
    }
    len1 = strlen(a);

    for(i = 1; len1 > 0; len1--, i++)
    {
        if(i % 2 == 1)
            b[len1 - 1] = (b[len1 - 1] + a[len1 - 1] - 96) % 13 + 48;
        else
        {
            if(b[len1 - 1] >= a[len1 - 1])
                b[len1 - 1] = b[len1 - 1] - a[len1 - 1] + 48;
            else
                b[len1 - 1] = b[len1 - 1] - a[len1 - 1] + 48 + 10;
        }
    }
    while(b[len1] != '\0')
    {
        if(b[len1] >='0' && b[len1] <= '9')
            printf("%c", b[len1]);
        else if(b[len1] == '9' + 1)
            printf("J");
        else if(b[len1] == '9' + 2)
            printf("Q");
        else if(b[len1] == '9' + 3)
            printf("K");
        len1++;
    }
    return 0;
}
