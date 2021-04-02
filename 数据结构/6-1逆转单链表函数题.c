#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read()
{
    int N, i;
    List L, temp, tail;

    scanf("%d", &N);
    L = tail = (List)malloc(sizeof (struct Node));
    scanf("%d", &L->Data);
    L->Next = NULL;
    for(i = 1; i < N; i++)
    {
        temp = (List)malloc(sizeof (struct Node));
        scanf("%d", &temp->Data);
        temp->Next = NULL;
        tail->Next = temp;
        tail = temp;
    }
    return L;
}
void Print( List L )
{
    List p;

    p = L;
    while(p != NULL)
    {
        printf("%d", p->Data);
        p = p->Next;
    }
    printf("\n");
}

List Reverse(List L)
{
    List front, real, temp;

    front = L;
    if(!L || L->Next == NULL)
        return L;
    else
    {
        real = L->Next;
        temp = real->Next;
        while(1)
        {
            if(temp == NULL)
            {
                real->Next = front;
                break;
            }
            else
            {
                real->Next = front;
                front = real;
                real = temp;
                temp = temp->Next;
            }
        }
        L->Next = NULL;
    }
    return real;
}

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

