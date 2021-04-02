#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;     //降序排序
}

int scale(int N)                //根据数据个数N求二维矩阵行列规模
{
    if (N == 1) return 1;
    int row = N, col, rem, last = N;
    while(1)
    {
        row--;
        rem = N % row;
        col = N / row;
        if(rem == 0)
        {
            if(row < col)
                break;
            else
                last = row;
        }
    }
    return last;
}

int main()
{
    int N, i, j, *a, **b, row, col;


    scanf("%d", &N);
    a = (int*)malloc(sizeof (int) * N);          //为数组申请空间并且读入数据
    for(i = 0; i < N; i++)
        scanf("%d", &a[i]);
    qsort(a, N, sizeof(int), cmp);             //排序
    row = scale(N);                            //求出二维数组规模（行列大小）
    col = N / row;
    b = (int**)malloc(sizeof(int*)*row + 1);           //申请二维数组空间并初始化
    for(i = 0; i < row + 1; i++)
    {
        b[i] = (int*)malloc(sizeof(int) * col + 1);
        for(j = 0; j < col + 1; j++)
            b[i][j] = 0;
    }
    int direct[] = {1, 2, 3, 4}, d = 1;                 //1->向右，2->向下，3->向左，4->向上, d初始化向右
    int x = 0, y = 0, position = 0;
    while(1)                                            //螺旋填充
    {
        if(b[x][y] != 0 || (x == row || x < 0) || (y < 0 || y == col))
        {
            switch(d)
            {
                case 1: y--; x++; d = 2;break;
                case 2: y--; x--; d = 3;break;
                case 3: y++; x--; d = 4;break;
                case 4: x++; y++; d = 1;break;
            }
        }
        b[x][y] = a[position];
        position++;
        if(position == N)
            break;
        switch(d)
        {
            case 1: y++;break;
            case 2: x++;break;
            case 3: y--;break;
            case 4: x--;break;
        }
    }
    for(i = 0; i < row; i++)               //打印二维数组
    {
        for(j = 0 ; j < col; j++)
        {
            if(j == 0) printf("%d", b[i][j]);
            else printf("% d", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}
