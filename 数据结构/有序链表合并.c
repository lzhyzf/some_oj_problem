#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read();
void Print( List L );

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Read()
{
    int n;
    scanf("%d",&n);
    List L=(List)malloc(sizeof(PtrToNode));   ///申请一个头结点
    L->Next = NULL;        ///头指针为空
    if(n)    ///当n不是0时
    {
        List r=L;     ///r是一个中间变量的节点
        for(int i=0;i<n;i++)
        {
            List p=(List)malloc(sizeof(struct Node));
            scanf("%d",&(p->Data));    ///尾插法
            r->Next = p;
            r = p;
        }
        r->Next = NULL;
    }
    return L;
}

void Print( List L )
{
   List p=L->Next;
   if(p)
   {
       List r;
       r = L;
       while(r->Next)
       {
           r = r->Next;
           printf("%d ",r->Data);
       }
   }
   else
   {
       printf("NULL");
   }
   printf("\n");
}

List Merge( List L1, List L2 )   ///合并函数  重点要写的函数！
{
    List pa,pb,pc,L;
    pc = (List)malloc(sizeof(PtrToNode));
    L = pc;
    pa = L1->Next;
    pb = L2->Next;

    while(pa && pb)
    {
        if(pb->Data > pa->Data)
        {
            pc->Next = pa;
            pa = pa->Next;
            pc = pc->Next;
        }
        else
        {
            pc->Next = pb;
            pb = pb->Next;
            pc = pc->Next;
        }
    }
    while(pa)
    {
        pc->Next = pa;
        pa = pa->Next;
        pc = pc->Next;
    }
    while(pb)
    {
        pc->Next = pb;
        pb = pb->Next;
        pc = pc->Next;
    }
    L1->Next = NULL;
    L2->Next = NULL;
    return L;
}
