#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* ʵ��ϸ�ں��� */
void PreorderPrintLeaves( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("Leaf nodes are:");
    PreorderPrintLeaves(BT);
    printf("\n");

    return 0;
}

void PreorderPrintLeaves( BinTree BT )
{
    if(!BT->Left && !BT->Right)
        printf(" %c", BT->Data);
    if(BT->Left) PreorderPrintLeaves(BT->Left);
    if(BT->Right)  PreorderPrintLeaves(BT->Right);
}
