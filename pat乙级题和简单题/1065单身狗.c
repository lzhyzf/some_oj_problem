#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int main()
{
    int N, M, i, temp1, temp2, flag = 0, cnt = 0, *b, a[100000], pre[100000] = {};

    for(i = 0; i < 100000; i++)
        a[100000] = -1;
    scanf("%d", &N);
    for(i = 0; i < N; i++)             //下标是自己的id，内部存couple的坐标
    {
        scanf("%d %d", &temp1, &temp2);
        a[temp1] = temp2;
        a[temp2] = temp1;
    }
    scanf("%d", &M);
    b = (int*)malloc(sizeof(int)*M);
    for(i = 0; i < M; i++)
        scanf("%d", &b[i]);
    qsort(b, M, sizeof(int), cmp);
    for(i = 0; i < M; i++)
        pre[b[i]] = 1;
    for(i = 0; i < M; i++)
    {
        if(a[b[i]] == -1 || pre[a[b[i]]] == 0)
            cnt++;
    }
    printf("%d\n", cnt);
    for(i = 0; i < M; i++)
    {
        if(a[b[i]] == -1 || pre[a[b[i]]] == 0){
            if(flag == 0){
                printf("%05d", b[i]);
                flag = 1;
            }
            else
                printf(" %05d", b[i]);
        }
    }

    return 0;
}
