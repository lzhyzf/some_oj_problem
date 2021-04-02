#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M, i, *a, j, sum, max, min, flagmax, flagmin, cnt;
    double avg;

    scanf("%d %d", &N, &M);
    a = (int *)malloc(sizeof (int) * N);
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
            scanf("%d", (a + j));
        for(j = 1, max = 0, cnt = 0, min = M; j < N; j++)
        {
            if(a[j] <= M && a[j] >= 0)
            {
                cnt++;
                if(max < a[j])
                    max = a[j];
                if(min > a[j])
                    min = a[j];
            }
        }
        for(j = 1, sum = 0, flagmax = 0, flagmin = 0; j < N; j++)
        {
            if(a[j] <= M && a[j] >= 0)
            {
                if(!flagmax && a[j] == max)
                {
                    a[j] = 0;
                    flagmax = 1;
                }
                if(!flagmin && a[j] == min)
                {
                    a[j] = 0;
                    flagmin = 1;
                }
                sum += a[j];
            }
        }
        avg = (double)sum / (cnt - 2);
        printf("%d\n", (int)((a[0] + avg + 1) / 2));
    }
    return 0;
}
