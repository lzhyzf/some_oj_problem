#include <stdio.h>

struct Node
{
    int co, ex;
}pol[1001];

int main()
{
    int N, M, i, mulans[10001] = {}, j, addans[10001] = {}, flag = 0, co, ex;

    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d %d", &pol[i].co, &pol[i].ex);
        addans[pol[i].ex] += pol[i].co;
    }
    scanf("%d", &M);
    for(i = 0; i < M; i++)
    {
        scanf("%d %d", &co, &ex);
        addans[ex] += co;
        for(j = 0; j < N; j++)
            mulans[ex + pol[j].ex] += (co * pol[j].co);
    }
    for(i = 10000; i >= 0; i--)
    {
        if(mulans[i] != 0)
        {
            if(flag == 0)
            {
                printf("%d %d", mulans[i], i);
                flag = 1;
            }
            else
                printf(" %d %d", mulans[i], i);
        }
    }
    if(flag == 0)
        printf("0 0");
    printf("\n");
    for(i = 10000, flag = 0; i >= 0; i--)
    {
        if(addans[i] != 0)
        {
            if(flag == 0)
            {
                printf("%d %d", addans[i], i);
                flag = 1;
            }
            else
                printf(" %d %d", addans[i], i);
        }
    }
    if(flag == 0)
        printf("0 0");
    return 0;
}
