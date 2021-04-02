#include <stdio.h>

int main()
{
    int N, M, score[101], answer[101], i, sum, temp, j;

    scanf("%d %d", &N, &M);
    for(i = 1; i <= M; i++)
        scanf("%d", &score[i]);
    for(i = 1; i <= M; i++)
        scanf("%d", &answer[i]);
    for(i = 0 ; i < N; i++)
    {
        for(j = 1, sum = 0; j <= M; j++)
        {
            scanf("%d", &temp);
            if(temp == answer[j])
                sum += score[j];
        }
        printf("%d\n", sum);
    }
    return 0;
}
