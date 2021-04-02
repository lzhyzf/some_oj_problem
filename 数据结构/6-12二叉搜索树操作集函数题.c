#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT );
void InorderTraversal( BinTree BT );

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
void InorderTraversal( BinTree BST )
{
    if(BST)
    {
        InorderTraversal(BST->Left);
        printf(" %c", BST->Data);
        InorderTraversal(BST->Right);
    }
}

void PreorderTraversal( BinTree BST )
{
    if(BST)
    {
        printf(" %c", BST->Data);
        PreorderTraversal(BST->Left);
        PreorderTraversal(BST->Right);
    }
}

BinTree Insert( BinTree BST, ElementType X )
{
    if(!BST)
    {
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else
    {
        if(BST->Data > X)
            BST->Left = Insert(BST->Left, X);
        else if(BST->Data < X)
            BST->Right = Insert(BST->Right, X);
    }
    return BST;
}

BinTree Delete( BinTree BST, ElementType X )
{
    Position p;
    if(!BST)
        printf("Not Found\n");
    else
    {
        if(BST->Data > X)
            BST->Left = Delete(BST->Left, X);
        else if(BST->Data < X)
            BST->Right = Delete(BST->Right, X);
        else
        {
            if(BST->Left && BST->Right)
            {
                p = FindMin(BST->Right);
                BST->Data = p->Data;
                Delete(BST->Right, p->Data);
            }
            else
            {
                if(!BST->Left)
                {
                    p = BST;
                    BST = BST->Right;
                    free(p);
                }
                else
                {
                    p = BST;
                    BST = BST->Left;
                    free(p);
                }
            }
        }
    }
    return BST;
}

Position Find( BinTree BST, ElementType X )
{
    if(!BST)
        return NULL;
    if(BST->Data == X)
        return BST;
    else if(BST->Data < X)
        return Find(BST->Right, X);
    else if(BST->Data > X)
        return Find(BST->Left, X);
}

Position FindMin( BinTree BST )
{
    BinTree p = BST;
    if(!p)
        return NULL;
    while(p->Left)
        p = p->Left;
    return p;
}

Position FindMax( BinTree BST )
{
    BinTree p = BST;
    if(!p)
        return NULL;
    while(p->Right)
        p = p->Right;
    return p;
}
