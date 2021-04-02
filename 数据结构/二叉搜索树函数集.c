#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal(BinTree BT);
void InorderTraversal(BinTree BT);
void PostorderTraversal(BinTree BT);
BinTree Insert(BinTree BST, ElementType X);
BinTree Delete(BinTree BST, ElementType X);
Position Find(BinTree BST, ElementType X);
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for (i = 0; i<N; i++) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Postorder:");
    PostorderTraversal(BST);
    printf("\n");
    printf("Preorder:");
    PreorderTraversal(BST);
    printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for (i = 0; i<N; i++) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp == MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp == MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for (i = 0; i<N; i++) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:");
    InorderTraversal(BST);
    printf("\n");

    return 0;
}

void PreorderTraversal(BinTree BT) {
    if (!BT) return;
    printf(" %d", BT->Data);
    PreorderTraversal(BT->Left);
    PreorderTraversal(BT->Right);
}

void InorderTraversal(BinTree BT) {
    if (!BT) return;
    PreorderTraversal(BT->Left);
    printf(" %d", BT->Data);
    PreorderTraversal(BT->Right);
}

void PostorderTraversal(BinTree BT) {
    if (BT) {
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        printf(" %d", BT->Data);
    }
}

BinTree Insert(BinTree BST, ElementType X){
    if(!BST){
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Right = NULL;
        BST->Left = NULL;
    }
    else if(X > BST->Data)
        BST->Right = Insert(BST->Right, X);
    else if (X < BST->Data)
        BST->Left = Insert(BST->Left, X);
        return BST;
}
BinTree Delete (BinTree BST, ElementType X){
    Position Tmp;

    if (!BST)
        printf("Not Found\n");
    else if (X = BST->Data){
        if(BST->Left && BST->Right){
            Tmp = FindMax(BST->Left);
            BST->Data = Tmp->Data;
            BST->Left= Delete(BST->Left, Tmp->Data);
        }
        else{
            Tmp = BST;
            if (BST->Left)
            BST = BST->Right;
            if (BST->Right)
            BST = BST->Left;
            free (Tmp);
        }
    }
    else if (X < BST->Data)
        BST->Left = Delete(BST->Left, X);
    else if (X > BST->Data)
        BST->Right = Delete(BST->Right, X);
        return BST;

}
Position Find(BinTree BST, ElementType X) {
    while (BST && (X != BST->Data)) {
        if (X < BST->Data)
            BST = BST->Left;
        else
            BST = BST->Right;
    }
    return BST;
}

Position FindMin(BinTree BST) {
    if (BST) {
        while (BST->Left)
            BST = BST->Left;
    }
    return BST;
}

Position FindMax(BinTree BST) {
    if (BST) {
        while (BST->Right)
            BST = BST->Right;
    }
    return BST;
}
