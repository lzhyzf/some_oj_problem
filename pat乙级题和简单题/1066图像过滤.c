#include <stdio.h>

int main()
{
    int N, M, A, B, C, temp, i, j, flag = 0;

    scanf("%d %d %d %d %d", &N, &M, &A, &B, &C);
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            scanf("%d", &temp);
            if(temp >= A && temp <= B)
                temp = C;
            if(flag == 0)
            {
                printf("%03d", temp);
                flag = 1;
            }
            else
                printf("% 03d", temp);
        }
        flag = 0;
        printf("\n");
    }
    return 0;
}
