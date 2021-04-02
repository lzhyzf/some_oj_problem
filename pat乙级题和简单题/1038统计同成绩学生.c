#include <stdio.h>

int main()
{
    int N, M, i, a[101] = {}, temp;

    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        a[temp] += 1;
    }
    scanf("%d", &M);
    for(i = 0; i < M; i++)
    {
        scanf("%d", &temp);
        if(i == 0) printf("%d", a[temp]);
        else printf(" %d", a[temp]);
    }
    return 0;
}
