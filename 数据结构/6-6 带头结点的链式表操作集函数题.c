#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef enum {false, true} bool;
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

List MakeEmpty();
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;
    bool flag;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        flag = Insert(L, X, L->Next);
        if ( flag==false ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            flag = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( flag==false )
                printf("Wrong Answer.\n");
        }
    }
    flag = Insert(L, X, NULL);
    if ( flag==false ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    flag = Insert(L, X, P);
    if ( flag==true ) printf("Wrong Answer\n");
    flag = Delete(L, P);
    if ( flag==true ) printf("Wrong Answer\n");
    for ( P=L->Next; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}

List MakeEmpty()
{
    List L = (List)malloc(sizeof(struct LNode));
    L->Next = NULL;
    return L;
}
Position Find( List L, ElementType X )
{
    Position p = L;
    while(p)
    {
        if(p->Data == X) return p;
        p = p->Next;
    }
    return ERROR;
}

bool Insert( List L, ElementType X, Position P )
{
    List temp, pre;
    for(pre = L; pre && pre->Next != P; pre = pre->Next);
    if(!pre)
    {
        printf("Wrong Position for Insertion\n");
        return false;
    }
    else
    {
        temp = (PtrToLNode)malloc(sizeof(struct LNode));
        temp->Data = X;
        pre->Next = temp;
        temp->Next = P;
        return true;
    }
}

bool Delete( List L, Position P )
{
    List temp, pre;
    if(!P)
    {
        printf("Wrong Position for Deletion\n");
        return false;
    }
    for(pre = L; pre && pre->Next != P; pre = pre->Next);
    if(!pre)
    {
        printf("Wrong Position for Deletion\n");
        return false;
    }
    else
    {
        pre-> Next = P->Next;
        free(P);
        return true;
    }
}
