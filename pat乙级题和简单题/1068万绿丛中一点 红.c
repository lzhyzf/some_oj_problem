#include <stdio.h>

int mymins(int a, int b, int TOL)
{
    if((a - b) <= TOL && (a - b) >= -TOL) return 1;
    else return 0;
}

int main()
{
    int i, j, M, N, cnt = 0, flag, row, col, n, m, flag1;
    static int b[1002][1002] = {};
    static int a[1002][1002] = {};
    int TOL;

    scanf("%d %d %d", &M, &N, &TOL);
    for(i = 1; i <= N; i++)
    {
        for(j = 1; j <= M; j++)
            scanf("%d", &a[i][j]);
    }
    for(i = 1; i <= N; i++)
    {
        for(j = 1; j <= M; j++)
        {
            flag = 0;
            if(b[i][j] == 0)
            {
                if(mymins(a[i][j], a[i-1][j-1], TOL)) {b[i][j] = b[i-1][j-1] = 1; flag = 1;}
                if(mymins(a[i][j], a[i-1][j], TOL)) {b[i][j] = b[i-1][j] = 1;flag = 1;}
                if(mymins(a[i][j], a[i-1][j+1], TOL)) {b[i][j] = b[i-1][j+1] = 1;flag = 1;}
                if(mymins(a[i][j], a[i][j-1], TOL)) {b[i][j] = b[i][j-1] = 1;flag = 1;}
                if(mymins(a[i][j], a[i][j+1], TOL)) {b[i][j] = b[i][j+1] = 1;flag = 1;}
                if(mymins(a[i][j], a[i+1][j-1], TOL)) {b[i][j] = b[i+1][j-1] = 1;flag = 1;}
                if(mymins(a[i][j], a[i+1][j], TOL)) {b[i][j] = b[i+1][j] = 1;flag = 1;}
                if(mymins(a[i][j], a[i+1][j+1], TOL)) {b[i][j] = b[i+1][j+1] = 1;flag = 1;}
                if(flag == 0){
                    flag1 = 0;
                    for(n = 1; n <= N; n++)
                    {
                        for(m = 1; m <= M; m++)
                        {
                            if(a[n][m] == a[i][j] && (!(n == i && m == j)))
                            {
                                flag1 = 1;
                                break;
                            }
                        }
                        if(flag1 == 1) break;
                    }
                    if(n == N + 1 && m == M + 1){
                        cnt++;
                        row = i;
                        col = j;
                    }
                }
                if(cnt == 2)
                {
                    printf("Not Unique\n");
                    return 0;
                }
            }
        }
    }
    if(cnt == 0)
        printf("Not Exist\n");
    else if(cnt == 1)
        printf("(%d, %d): %d", col, row, a[row][col]);
    return 0;
}
