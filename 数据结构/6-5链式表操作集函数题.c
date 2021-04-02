#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode
{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while ( N-- )
    {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if ( L==ERROR )
            printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- )
    {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else
        {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( L==ERROR )
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if ( L==ERROR )
        printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if ( tmp!=ERROR )
        printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if ( tmp!=ERROR )
        printf("Wrong Answer\n");
    for ( P=L; P; P = P->Next )
        printf("%d ", P->Data);
    return 0;
}

Position Find( List L, ElementType X )
{
    Position p;
    p = L;
    while(p)
    {
        if(p->Data == X)
            return p;
        p = p->Next;
    }
    return ERROR;
}

List Insert( List L, ElementType X, Position P )
{
    Position a = L, temp;

    if(P == L)
    {
        temp = (PtrToLNode)malloc(sizeof(struct LNode));
        temp->Data = X;
        temp->Next = L;
        return temp;
    }
    else
    {

        for(; a && a->Next != P; a = a->Next);
        if(!a)
        {
            printf("Wrong Position for Insertion\n");
            return ERROR;
        }
        else
        {
            temp = (PtrToLNode)malloc(sizeof(struct LNode));
            temp->Data = X;
            a->Next = temp;
            temp->Next = P;
            return L;
        }
    }
}

List Delete( List L, Position P )
{
    Position a = L, temp;

    if(P == L)
    {
        L = L->Next;
        free(P);
        return L;
    }
    else
    {
        for(; a && a->Next != P; a = a->Next);
        if(!a)
        {
            printf("Wrong Position for Deletion\n");
            return ERROR;
        }
        else
        {
            temp = P;
            P = P->Next;
            a->Next = P;
            free(temp);
            return L;
        }
    }
}
