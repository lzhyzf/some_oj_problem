#include <stdio.h>

int main()
{
    int T, K, n1, b, t, n2, i;

    scanf("%d %d", &T, &K);
    for(i = 0; i < K; i++)
    {
        scanf("%d %d %d %d", &n1, &b, &t, &n2);
        if(t <= T)
        {
            if((n1 > n2 && b == 0) || (n1 < n2 && b == 1))
            {
                T += t;
                printf("Win %d!  Total = %d.\n", t, T);
            }
            else
            {
                T -= t;
                printf("Lose %d.  Total = %d.\n", t, T);
                if(T == 0)
                {
                    printf("Game Over.\n");
                    break;
                }
            }
        }
        else
            printf("Not enough tokens. Total = %d.\n", T);
    }
    return 0;
}


