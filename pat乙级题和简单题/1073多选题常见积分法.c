#include <stdio.h>

struct answer
{
    int score;//ѡ������ȷ�÷�
    int opnum;//ѡ����ѡ�����
    int rnum;//ѡ������ȷѡ�����
    int asc[129];//��ascii����ֵ����¼ѡ������ȷ��
}a[101];

int main()
{
    int N, M, i, snum, j, k, flag, b[129], error[101][129] = {}, max = 0;
    double sum;
    char temp;

    scanf("%d %d", &N, &M);
    for(i = 1; i <= M; i++)//��ʼ��
        a[i].asc['a'] = a[i].asc['b'] = a[i].asc['c'] = a[i].asc['d'] = a[i].asc['e'] = 0;
    for(i = 1; i <= M; i++)//��M���𰸣�����a�ṹ����
    {
        scanf("%d %d %d", &a[i].score, &a[i].opnum, &a[i].rnum);
        for(j = 0; j < a[i].rnum; j++)
            {
                scanf(" %c", &temp);
                a[i].asc[(int)temp] = 1;
            }
    }
    for(i = 0; i < N; i++)
    {
        for(j = 1, sum = 0; j <= M; j++)
        {
            getchar();//�Ե��ո���߻س�
            scanf("(%d", &snum);
            b['a'] = b['b'] = b['c'] = b['d'] = b['e'] = 0;
            for(k = 0, flag = 0; k < snum; k++)
            {
                scanf(" %c", &temp);
                b[(int)temp] = 1;
                if(a[j].asc[(int)temp] == 0)
                {
                    flag = 1;
                    error[j][(int)temp]++;
                }
            }
            if(flag == 0 && snum == a[j].rnum)
                sum += a[j].score;
            else if(flag == 0)
                sum += (double)a[j].score / 2;
            if(a[j].asc['a'] == 1 && b['a'] == 0) error[j]['a']++;
            if(a[j].asc['b'] == 1 && b['b'] == 0) error[j]['b']++;
            if(a[j].asc['c'] == 1 && b['c'] == 0) error[j]['c']++;
            if(a[j].asc['d'] == 1 && b['d'] == 0) error[j]['d']++;
            if(a[j].asc['e'] == 1 && b['e'] == 0) error[j]['e']++;
            getchar();//�Ե���
        }
        printf("%.1lf\n", sum);
    }
    for(i = 1; i <= M; i++)
        for(j = 'a'; j <= 'e'; j++)
            if(error[i][j] > max) max = error[i][j];
    if(max == 0)
        printf("Too simple\n");
    else
    {
        for(i = 1; i <= M; i++)
            for(j = 'a'; j <= 'e'; j++)
            {
                if(error[i][j] == max)
                    printf("%d %d-%c\n", max, i, (char)j);

            }
    }
    return 0;
}
