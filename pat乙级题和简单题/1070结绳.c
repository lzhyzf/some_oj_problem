#include <stdio.h>//一道考察数学能力的题目
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int main()
{
    int N, i, a[10000];
    float sum = 0;

    scanf("%d", &N);
    for(i = 0 ; i < N; i++)
        scanf("%d", &a[i]);
    qsort(a, N, sizeof(int), cmp);
    sum += a[0];
    for(i = 1 ; i < N; i++)
        sum = (sum + a[i]) / 2;
    printf("%d", (int)sum);
    return 0;
}
