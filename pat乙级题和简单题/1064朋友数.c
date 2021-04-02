#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, friendcard[37] = {}, i, number, cnt = 0, format = 0, ge, shi, bai, qian;
    char temp[6];

    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%s", temp);
        sscanf(temp, "%d", &number);
        ge = number % 10;
        qian = number / 1000;
        bai = number % 1000 / 100;
        shi = number % 100 / 10;
        number = ge + shi + bai +qian;
        friendcard[number]++;
    }
    for(i = 0; i < 37; i++)
    {
        if(friendcard[i] >= 1) cnt++;
    }
    printf("%d\n", cnt);
    for(i = 0; i < 37; i++)
    {
        if(friendcard[i] >= 1 && format == 0)
        {
            printf("%d", i);
            format = 1;
        }
        else if(friendcard[i] >= 1)
            printf(" %d", i);
    }
    return 0;
}
