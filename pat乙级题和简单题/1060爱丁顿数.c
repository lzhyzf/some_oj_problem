#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)   //Ωµ–Ú≈≈¡–
{
    return *(int *)b - *(int *)a;
}

int main()
{
    int a[1000001], N, i;

    scanf("%d", &N);
    for(i = 1; i <= N; i++)
        scanf("%d", &a[i]);
    qsort(a + 1, N, sizeof(int), cmp);
    int ans = 0, p = 1;
    while(ans <= N && a[p] > p) {
        ans++;
        p++;
    }
    printf("%d", ans);
    return 0;
}
