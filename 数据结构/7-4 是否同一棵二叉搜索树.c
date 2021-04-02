#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef struct TNode *Tree;
struct TNode
{
    int Data;
    Tree Left, Right;
    int flag;
};

Tree Insert(Tree BST, int X)
{
    if(!BST)
    {
        BST = (Tree)malloc(sizeof (struct TNode));
        BST->Data = X;
        BST->flag = 0;
        BST->Left = BST->Right = NULL;
    }
    else{
        if(X < BST->Data)
            BST->Left = Insert(BST->Left, X);
        else if(X > BST->Data)
            BST->Right = Insert(BST->Right, X);
    }
    return BST;
}

Tree CreateBST(int N)
{
    Tree BST;
    int X, i;

    BST = (Tree)malloc(sizeof (struct TNode));
    BST->Left = BST->Right = NULL;
    scanf("%d", &BST->Data);
    BST->flag = 0;
    for(i = 1; i < N; i++){
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    return BST;
}

int myfind(Tree BST, int X)
{
    Tree p = BST;
    while(p->Data != X && p)
    {
        if(p->flag == 0) return FALSE;
        if(X < p->Data)
            p = p->Left;
        else
            p = p->Right;
    }
    if(!p) return FALSE;
    else
    {
        p->flag = 1;
        return TRUE;
    }
}

/*int myfind(Tree BST, int V)
{
    if(BST->flag)
    {
        if(V < BST->Data) return myfind(BST->Left, V);
        else if(V > BST->Data) return myfind(BST->Right, V);
        else return 0;
    }
    else
    {
        if(V == BST->Data)
        {
            BST->flag = 1;
            return 1;
        }
        else return 0;
    }
}*/

int Issame(Tree BST, int N)
{
    int temp, flag = 0, i;

    scanf("%d", &temp);
    if(BST->Data != temp) flag = 1;
    else BST->flag = 1;
    for(i = 1; i < N; i++)
    {
        scanf("%d", &temp);
        if(!flag && !myfind(BST, temp)) flag = 1;
    }
    if(flag) return FALSE;
    else return TRUE;
}

int main()
{
    int N, L, i;

    while(1)
    {
        scanf("%d", &N);
        if(!N) break;
        scanf("%d", &L);
        Tree BST = CreateBST(N);
        for(i = 0; i < L; i++){
            if(Issame(BST, N)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
