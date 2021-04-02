#include <stdio.h>
#include <string.h>

int main()
{
    int N, M, num[101] = {}, grade, i, j, k, len, flag, max = 0, temp, c;

    char a[101][16], b[16];
    scanf("%d %d", &N, &M);
    getchar();
    for(i = 1; i <= M; i++)
        gets(a[i]);
    for(i = 0; i < N; i++)
    {
        grade = 0;
        for(j = 1; j <= M; j++)
        {
            temp = 0;
            while((c = getchar()) != ')')
                b[temp++] = c;
            getchar();                           //吃掉回车或者空格
            b[temp] = '\0';
            len = strlen(b);
            for(k = 1, flag = 0; k < len; k++)
            {
                if(b[k] != a[j][k + 3]) flag = 1;
                if(flag == 1)
                {
                    num[j]++;
                    break;
                }
            }
            if(flag == 0)
                grade += (a[j][0] - '0');
        }
        printf("%d\n", grade);
    }
    for(i = 1; i <= M; i++)
    {
        if(num[i] > max) max = num[i];
    }
    if(max == 0) printf("Too simple\n");
    else{
        printf("%d", max);
        for(i = 1; i <= M; i++)
        {
            if(max == num[i])
                printf(" %d", i);
        }
    }
    return 0;
}
