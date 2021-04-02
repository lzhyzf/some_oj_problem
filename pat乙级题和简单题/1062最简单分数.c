#include <stdio.h>

// 求最大公约数的函数(辗转相除法)
int gys(int a, int b)
{
    return b == 0 ? a : gys(b, a % b);
}

//求最小公倍数
int gbs(int a, int b)
{
    return a * b / gys(a, b);
}

int main()
{
    int N1, N2, M1, M2, K, temp, cnt = 0, i, temp1;

    scanf("%d/%d %d/%d %d", &N1, &M1, &N2, &M2, &K);
    temp = gbs(M1, M2);
    temp = gbs(temp, K);
    N1 = (temp / M1) * N1;
    N2 = (temp / M2) * N2;
    if(N1  > N2)
    {
        temp1 = N1;
        N1 = N2;
        N2 = temp1;
    }
    for(i = N1 + 1; i < N2; i++)
    {
        if(gys(i, temp) == temp / K)
        {
            if(cnt == 0)
                {
                    printf("%d/%d", i/(temp/K), K);
                    cnt++;
                }
            else
                printf(" %d/%d", i/(temp/K), K);
        }
    }
    return 0;
}
