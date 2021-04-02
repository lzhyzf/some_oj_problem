#include <stdio.h>

int main()
{
    int i, N, troop, num, grade, max = 0, index;
    int sum[1001] = {0};

    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%d-%d %d", &troop, &num, &grade);
        sum[troop] += grade;
        if(max < sum[troop])
        {
            max = sum[troop];
            index = troop;
        }
    }
    printf("%d %d", index, max);
    return 0;
}
