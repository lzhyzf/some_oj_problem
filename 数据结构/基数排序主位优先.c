#include <stdio.h>
#include <stdlib.h>
/* ����Ԫ�������MaxDigit���ؼ��֣�����ȫ��ͬ����Radix */

#define MaxDigit 4
#define Radix 10
typedef int ElementType;
/* ͰԪ�ؽ�� */
typedef struct Node *PtrToNode;
struct Node
{
    int key;
    PtrToNode next;
};

/* Ͱͷ��� */
struct HeadNode
{
    PtrToNode head, tail;
};
typedef struct HeadNode Bucket[Radix];

int GetDigit ( int X, int D )
{
    /* Ĭ�ϴ�λD=1, ��λD<=MaxDigit */
    int d, i;

    for (i=1; i<=D; i++)
    {
        d = X%Radix;
        X /= Radix;
    }
    return d;
}

void MSD( ElementType A[], int L, int R, int D )
{
    /* ���ĵݹ麯��: ��A[L]...A[R]�ĵ�Dλ���������� */
    int Di, i, j;
    Bucket B;
    PtrToNode tmp, p, List = NULL;

    if(D == 0) return; /* �ݹ���ֹ���� */

    for(i = 0; i < Radix; i++)/* ��ʼ��ÿ��ͰΪ������ */
        B[i].head = B[i].tail = NULL;
    for(i = L; i <= R; i++)
    {/* ��ԭʼ������������ʼ����List */
        tmp = (PtrToNode)malloc(sizeof(struct Node));
        tmp->key = A[i];
        tmp->next = List;
        List = tmp;
    }
    /* �����Ƿ���Ĺ��� */
    p = List;
    while(p)
    {
        Di = GetDigit(p->key, D);/* ��õ�ǰԪ�صĵ�ǰλ���� */
        /* ��List��ժ�� */
        tmp = p;
        p = p->next;
        tmp->next = NULL;
        /* ����B[Di]��Ͱ */
        if(B[Di].head == NULL)
            B[Di].head = B[Di].tail = tmp;
        else
        {
            B[Di].tail->next = tmp;
            B[Di].tail = tmp;
        }
    }
    /* �������ռ��Ĺ��� */
    i = j = L;/* i, j��¼��ǰҪ�����A[]�����Ҷ��±� */
    for(Di = 0; Di < Radix; Di++)/* ����ÿ��Ͱ */
    {
        if(B[Di].head)
        {/* ���ǿյ�Ͱ��Ͱ����A[], �ݹ����� */
            p = B[Di].head;
            while(p)
            {
                tmp = p;
                p = p->next;
                A[j++] = tmp->key;
                free(tmp);
            }
            /* �ݹ�Ը�Ͱ��������, λ����1 */
            MSD( A, i, j - 1, D - 1);
        }
        i = j;/* Ϊ��һ��Ͱ��Ӧ��A[]��� */
    }

}

void MSDRadixSort( ElementType A[], int N )
{
    /* ͳһ�ӿ� */
    MSD(A, 0, N-1, MaxDigit);
}

int main()
{
    int a[10] = {7, 8, 1, 4, 9, 5, 2, 6, 3, 0}, i;
    MSDRadixSort(a, 10);
    for(i = 0; i < 10; i++)
        printf("%d", a[i]);
    return 0;
}
