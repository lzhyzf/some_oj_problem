#include <stdio.h>

struct student
{
    char name[5];
    int a[11];
};

int main()
{
    int M, N, i, ban[10000] = {}, temp, cntpri, cntsum = 0, K, j, cntstu = 0;
    char name[5];

    scanf("%d %d", &N, &M);
    for(i = 0 ; i < M; i++)
    {
        scanf("%d", &temp);
        ban[temp] = 1;
    }
    for(i = 0; i < N; i++)
    {
        scanf("%s %d", name, &K);
        for(j = 0, cntpri = 0; j < K; j++)
        {
            scanf("%d", &temp);
            if(ban[temp] == 1)
            {
                cntpri++;
                if(cntpri == 1)
                    printf("%s: %04d", name, temp);
                else if(cntpri > 1)
                    printf(" %04d", temp);
            }
        }
        if(cntpri > 0)
        {
            printf("\n");
            cntstu++;
            cntsum += cntpri;
        }
    }
    printf("%d %d\n", cntstu, cntsum);
    return 0;
}
