#include <stdio.h>
#include <stdlib.h>

/* �������� - ��λ���� */

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


int GetDigit(int X, int D)
{
    int i, d;
    for(i = 0; i < D; i++)
    {
        d = X % Radix;
        X /= Radix;
    }
    return d;
}

void LSDRadixSort( ElementType A[], int N )
{
    /* �������� - ��λ���� */
    int i, Di, D;
    Bucket B;
    PtrToNode List = NULL, tmp, p;

    for(i = 0; i < Radix; i++) /* ��ʼ��ÿ��ͰΪ������ */
        B[i].head = B[i].tail = NULL;
    for(i = 0; i < N; i++)
    {/* ��ԭʼ������������ʼ����List */
        tmp = (PtrToNode)malloc(sizeof(struct Node));
        tmp->key = A[i];
        tmp->next = List;
        List = tmp;
    }
    /* ���濪ʼ���� */
    for(D = 1; D <= MaxDigit; D++)/* �����ݵ�ÿһλѭ������ */
    {/* �����Ƿ���Ĺ��� */
        p = List;
        while(p)
        {
            Di = GetDigit(p->key, D);/* ��õ�ǰԪ�صĵ�ǰλ���� */
            /* ��List��ժ�� */
            tmp = p;
            p = p->next;
            tmp->next = NULL;
            /* ����B[Di]��Ͱβ */
            if(B[Di].head == NULL)
                B[Di].head = B[Di].tail = tmp;
            else
            {
                B[Di].tail->next = tmp;
                B[Di].tail = tmp;
            }
        }
        /* �������ռ��Ĺ��� */
        List = NULL;
        for(Di = Radix - 1; Di >= 0; Di--)/* ��ÿ��Ͱ��Ԫ��˳���ռ���List */
        {
            if(B[Di].head) /* ���Ͱ��Ϊ�� */
            {/* ��Ͱ����List��ͷ */
                B[Di].tail->next = List;
                List = B[Di].head;
                B[Di].head = B[Di].tail = NULL;/* ���Ͱ */
            }
        }
    }
    /* ��List����A[]���ͷſռ� */
    for(i = 0; i < N; i++)
    {
        tmp = List;
        List = List->next;
        A[i] = tmp->key;
        free(tmp);
    }

}

int main()
{
    int a[10] = {7, 8, 1, 4, 9, 5, 2, 6, 3, 0}, i;
    LSDRadixSort(a, 10);
    for(i = 0; i < 10; i++) printf("%d", a[i]);
    return 0;
}
