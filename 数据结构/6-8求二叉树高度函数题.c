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

BinTree CreatBinTree(); /* ÊµÏÖÏ¸½ÚºöÂÔ */
int GetHeight( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}

int GetHeight( BinTree BT )
{
    if(BT == NULL) return 0;
    return GetHeight(BT->Left) >= GetHeight(BT->Right) ? GetHeight(BT->Left) + 1 : GetHeight(Right) + 1;
}
