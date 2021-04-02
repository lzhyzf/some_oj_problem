#include <stdio.h>

int main()
{
    int N, a[10] = {0}, sum = 0, temp, i, j;

    scanf("%d", &N);
    for(i = 1 ; i <= N; i++)
    {
        scanf("%d" , &temp);
        if(a[temp]  == 1)
            sum += (temp * 10 + temp);
        else
            a[temp] = 1;
    }
    for(i = 1; i <= 9; i++)
    {
        if(a[i] == 1)
        {
            for(j = 1; j <= 9; j++)
            {
                if(a[j] == 1 && j != i)
                    sum += (10 * i + j);
            }
        }
    }
    printf("%d", sum);
    return 0;
}
