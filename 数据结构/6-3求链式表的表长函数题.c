#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read()
{
    int N, i;
    List L, temp, tail;

    L = NULL;
    while(1)
    {
        temp = (List)malloc(sizeof (struct LNode));
        scanf("%d", &temp->Data);
        temp->Next = NULL;
        if(L == NULL)
        {
            L = temp;
            tail = temp;
        }
        else
        {
            tail->Next = temp;
            tail = temp;
        }
        if(tail->Data == -1) break;
    }
    return L;
}

int Length( List L )
{
    int cnt = 0;
    List p;
    p = L;
    while(p && p->Data != -1)
    {
        cnt++;
        p = p->Next;
    }
    return cnt;
}

int main()
{
    List L = Read();
    printf("%d\n", Length(L));
    return 0;
}


