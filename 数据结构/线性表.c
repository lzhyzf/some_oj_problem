#include <stdio.h>
#include<malloc.h>
#define LIST_INIT_SIZE 100  //���Ա�洢�ռ��ʼ������
#define LISTINCREAMENT 10   //���Ա�ռ��������
typedef int ElemType;
typedef struct{
    ElemType *elem;         //�洢�ռ����ַ
    int length;             //��ǰ���Ա���
    int listsize;           //��ǰ����洢����
}SqList;

int InitList(SqList *L)
{//����˳���
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));   //����һ���洢�ռ䣬���������ַ��elem
    if(!L->elem)
    {
        printf("��ַ����ʧ��/n");
        return -1;
    }

    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return 0;
}

int ListInsert(SqList *L, int i; ElemType x)
{//��λ��i����ֵΪx��Ԫ��
    if(i<1 || i > L->length)                 //�жϲ���Ԫ���Ƿ�Ϸ�
        return -1;
    if(L->length == L.listsize)              //�жϱ��Ƿ�����
        ElemType *newbase = (ElemType *)malloc((L->listsize + LISTINCREAMENT)*sizeof(ElemType)) ;
    if (!newbase) return -1;    //�洢�ռ����ʧ��
    L->elem = newbase;
    L->listsize += LISTINCREAMENT;

    ElemType *p, *q;
    q = (L->elem[i-1]);        //qΪ����λ��(ע���β�i����ţ�����ǴӴ�1��ʼ�ģ����±��Ǵ�0��ʼ�ģ��������ת���±����i-1)
    for (p = &(L.elem[L.length - 1]); p >= q; --p) //   ��ai��an-1���κ��ƣ�ע����Ʋ���Ҫ�Ӻ���ǰ����
    {
        *(p + 1) = *p;
        *q = x;
        ++L.length;                        //����1
        return 0;
    }

int LocateElem(SqList *L, ElemType x)
{//��ֵ����

    int k;
    for(int i = 0; i < L->length; i++)
    {
        if(L->elem[i] == x)
            return i;
    }
}



int *ListDelete(SqList *L, int i, ElemType *e)
{//�ж�ɾ��λ�õĺϷ���
    if (i<1 || i>L.length) return -1;
    ElemType *q, *p;
    p = &(L.elem[i - 1]);//pΪ��ɾ��Ԫ�ص�λ��(ע���β�i����ţ�����ǴӴ�1��ʼ�ģ����±��Ǵ�0��ʼ�ģ��������ת���±����i-1)
    *e = *p;
    q = L.elem + L.length - 1;//qָ���β���һ��Ԫ��(q�����һ��Ԫ�صĵ�ַ)
    for (++p; p <= q; ++p) //��p����һ��Ԫ�ؿ�ʼ����ǰ��
    {
        *(p - 1) = *p;
    }

    --L.length;            //����1
    return e;
}
}
int main()
{
    SqList list;
    InitList(list);

    int n = 10;

    //���10�����ָ����Ա�list
    for (int i = 0; i < 10; i++)
    {
        ListInsert(list, i+1, i+1);
    }
    //ɾ����5��
    ElemType e;
    ListDelete(list, 5, e);
    printf("ɾ����Ԫ���ǣ�%d\n", e);

    //�ڵ�2��λ�ò���һ��Ԫ��-1
    ListInsert(list, 2, -1);

    //������Ա�
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", list.elem[i]);
    }
    //�������ǣ�1 -1 2 3 4 6 7 8 9 10

    system("pause");
}
