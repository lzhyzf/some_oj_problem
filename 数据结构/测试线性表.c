#include<stdio.h>

#define MAXSIZE 20

typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SqList;

#define OK 1
#define ERROR 0
typedef int Status;
Status GetElem(SqList L,int i,ElemType *e)
{
    if(L.length==0||i<1||i>L.length)
        return ERROR;
    *e=L.data[i-1];
    return OK;
}

Status ListInsert(SqList *L,int i,ElemType e)
{
    int k;
    if(L->length==MAXSIZE||i<1||i>L->length+1)
        return ERROR;
    if(i<=L->length)
    {
        for(k=L->length-1;k>=i-1;k--)
            L->data[k+1]=L->data[k];
    }
    L->data[i-1]=e;
    L->length++;
    return OK;
}

Status ListDelete(SqList *L,int i,ElemType *e)
{
    int k;
    if(L->length==0||i<1||i>L->length)
        return ERROR;
    *e=L->data[i-1];
    if(i<L->length)
    {
        for(k=i;k<L->length;k++)
            L->data[k-1]=L->data[k];
    }
    L->length--;
    return OK;
}
int main()
{
    SqList sq;
    sq.data[0]=5;
    sq.data[1]=4;
    sq.data[2]=3;
    sq.data[3]=2;
    sq.data[4]=1;
    sq.length=5;

    int a=0;
    for(a=0;a<sq.length;a++)
    {
            printf("%d\n",sq.data[a]);
    }

    int sqd1;
    printf("%d\n",GetElem(sq,2,&sqd1));
    printf("%d\n",sqd1);

    int sqd2=6;
    printf("%d\n",ListInsert(&sq,4,sqd2));
    printf("%d\n",sq.data[3]);

    printf("%d\n",ListDelete(&sq,4,&sqd2));
    printf("%d\n",sqd2);

    return 0;
}
