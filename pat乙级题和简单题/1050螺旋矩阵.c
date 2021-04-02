#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;     //��������
}

int scale(int N)                //�������ݸ���N���ά�������й�ģ
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
    a = (int*)malloc(sizeof (int) * N);          //Ϊ��������ռ䲢�Ҷ�������
    for(i = 0; i < N; i++)
        scanf("%d", &a[i]);
    qsort(a, N, sizeof(int), cmp);             //����
    row = scale(N);                            //�����ά�����ģ�����д�С��
    col = N / row;
    b = (int**)malloc(sizeof(int*)*row + 1);           //�����ά����ռ䲢��ʼ��
    for(i = 0; i < row + 1; i++)
    {
        b[i] = (int*)malloc(sizeof(int) * col + 1);
        for(j = 0; j < col + 1; j++)
            b[i][j] = 0;
    }
    int direct[] = {1, 2, 3, 4}, d = 1;                 //1->���ң�2->���£�3->����4->����, d��ʼ������
    int x = 0, y = 0, position = 0;
    while(1)                                            //�������
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
    for(i = 0; i < row; i++)               //��ӡ��ά����
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
