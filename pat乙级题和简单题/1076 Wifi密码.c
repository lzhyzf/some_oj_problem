#include <stdio.h>

int main()
{
    int N, i;
    char a, b;

    scanf("%d", &N);
    for(i = 0; i < N * 4; i++)
    {
        getchar();
        scanf("%c-%c", &a, &b);
        if(b == 'T')
            printf("%d", a - 'A' + 1);
    }
    return 0;
}
