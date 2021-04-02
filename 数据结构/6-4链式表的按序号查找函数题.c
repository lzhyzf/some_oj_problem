#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
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

ElementType FindKth( List L, int K )
{
    int i;

    if(L == NULL) return ERROR;
    while(--K)
    {
        if(L->Next == NULL) return ERROR;
        L = L->Next;
    }
    return L->Data;
}

int main()
{
    int N, K;
    ElementType X;
    List L = Read();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if ( X!= ERROR )
            printf("%d ", X);
        else
            printf("NA ");
    }
    return 0;
}
