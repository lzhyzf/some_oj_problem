#include <stdio.h>
#include<malloc.h>
#define LIST_INIT_SIZE 100  //线性表存储空间初始分配量
#define LISTINCREAMENT 10   //线性表空间分配增量
typedef int ElemType;
typedef struct{
    ElemType *elem;         //存储空间基地址
    int length;             //当前线性表长度
    int listsize;           //当前分配存储容量
}SqList;

int InitList(SqList *L)
{//建立顺序表
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));   //开辟一个存储空间，并分配基地址给elem
    if(!L->elem)
    {
        printf("地址分配失败/n");
        return -1;
    }

    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return 0;
}

int ListInsert(SqList *L, int i; ElemType x)
{//在位置i插入值为x的元素
    if(i<1 || i > L->length)                 //判断插入元素是否合法
        return -1;
    if(L->length == L.listsize)              //判断表是否已满
        ElemType *newbase = (ElemType *)malloc((L->listsize + LISTINCREAMENT)*sizeof(ElemType)) ;
    if (!newbase) return -1;    //存储空间分配失败
    L->elem = newbase;
    L->listsize += LISTINCREAMENT;

    ElemType *p, *q;
    q = (L->elem[i-1]);        //q为插入位置(注意形参i是序号，序号是从从1开始的，而下标是从0开始的，因此这里转成下标后是i-1)
    for (p = &(L.elem[L.length - 1]); p >= q; --p) //   从ai到an-1依次后移，注意后移操作要从后往前进行
    {
        *(p + 1) = *p;
        *q = x;
        ++L.length;                        //表长加1
        return 0;
    }

int LocateElem(SqList *L, ElemType x)
{//按值查找

    int k;
    for(int i = 0; i < L->length; i++)
    {
        if(L->elem[i] == x)
            return i;
    }
}



int *ListDelete(SqList *L, int i, ElemType *e)
{//判断删除位置的合法性
    if (i<1 || i>L.length) return -1;
    ElemType *q, *p;
    p = &(L.elem[i - 1]);//p为被删除元素的位置(注意形参i是序号，序号是从从1开始的，而下标是从0开始的，因此这里转成下标后是i-1)
    *e = *p;
    q = L.elem + L.length - 1;//q指向表尾最后一个元素(q是最后一个元素的地址)
    for (++p; p <= q; ++p) //从p的下一个元素开始依次前移
    {
        *(p - 1) = *p;
    }

    --L.length;            //表长减1
    return e;
}
}
int main()
{
    SqList list;
    InitList(list);

    int n = 10;

    //添加10个数字给线性表list
    for (int i = 0; i < 10; i++)
    {
        ListInsert(list, i+1, i+1);
    }
    //删除第5个
    ElemType e;
    ListDelete(list, 5, e);
    printf("删除的元素是：%d\n", e);

    //在第2个位置插入一个元素-1
    ListInsert(list, 2, -1);

    //输出线性表
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", list.elem[i]);
    }
    //输出结果是：1 -1 2 3 4 6 7 8 9 10

    system("pause");
}
