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

//BinTree CreatBinTree(); /* ÊµÏÖÏ¸½ÚºöÂÔ */
void InorderTraversal( BinTree BT );
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal( BinTree BT );

int main()
{
    BinTree BT /*= CreatBinTree()*/;
    printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
    return 0;
}

void InorderTraversal( BinTree BT )
{
    if(BT)
    {
        InorderTraversal(BT->Left);
        printf(" %c", BT->Data);
        InorderTraversal(BT->Right);
    }
}
void PreorderTraversal( BinTree BT )
{
    if(BT)
    {
        printf(" %c", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}
void PostorderTraversal( BinTree BT )
{
    if(BT)
    {
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        printf(" %c", BT->Data);
    }
}

void LevelorderTraversal( BinTree BT )
{
    int head, tail;
    BinTree q[100], temp;
    if(BT)
    {
        head = tail = -1;
        q[++head] = BT;
        while(head - tail)
        {
            temp = q[++tail];
            printf(" %c", temp->Data);
            if(temp->Left)
                q[++head] = temp->Left;
            if(temp->Right)
                q[++head] = temp->Right;
        }
    }
}








