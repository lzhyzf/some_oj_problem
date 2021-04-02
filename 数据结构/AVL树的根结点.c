#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *AVLTree;
struct TreeNode{
    int Data;
    AVLTree Left, Right;
    int Height;
};

AVLTree Insert(AVLTree T, int x);
int GetHeight(AVLTree T);
int Max(int a, int b);
AVLTree SingleRightRotation(AVLTree T);
AVLTree SingleLeftRotation(AVLTree T);
AVLTree LeftRightRotation(AVLTree T);
AVLTree RightLeftRotation(AVLTree T);

int main()
{
    int N,i;
    int x;
    scanf("%d",&N);
    AVLTree T = NULL;
    for(i=0;i<N;i++)
    {
        scanf("%d",&x);
        T = Insert(T,x);
    }
    if(T)
    {
        printf("%d",T->Data);
    }
    return 0;
}

AVLTree Insert(AVLTree T, int x){
    if (!T){
        T = (AVLTree)malloc(sizeof(struct TreeNode));
        T->Data = x;
        T->Left = T->Right = NULL;
        T->Height = 0;
    }
    else if(x < T->Data){
        T->Left = Insert(T->Left, x);
        if(GetHeight(T->Left) - GetHeight(T->Right) == 2){
            if(x < T->Left->Data)
                T = SingleRightRotation(T);
            else
                T= LeftRightRotation(T);
        }
    }
    else if(x > T->Data){
        T->Right = Insert(T->Right, x);
        if(GetHeight(T->Right) - GetHeight(T->Left) == 2){
            if(x > T->Right->Data)
                T = SingleLeftRotation(T);
            else
                T= RightLeftRotation(T);

        }
    }
    T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
    return T;
}

int GetHeight(AVLTree T)
{
    if (!T)
        return 0;
    else
        return T->Height;
}

int Max(int a, int b){
    return a > b ? a : b;
}

AVLTree SingleRightRotation(AVLTree T){
    AVLTree A = T->Left;

    T->Left = A->Right;
    A->Right = T;
    T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
    A->Height = Max(GetHeight(A->Left), T->Height) + 1;
    return A;
}

AVLTree SingleLeftRotation(AVLTree T){
    AVLTree A = T->Right;

    T->Right = A->Left;
    A->Left = T;
    T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
    A->Height = Max(GetHeight(A->Right), T->Height) + 1;
    return A;
}

AVLTree LeftRightRotation(AVLTree T){
    T->Left = SingleLeftRotation(T->Left);
    return SingleRightRotation(T);
}

AVLTree RightLeftRotation(AVLTree T){
    T->Right = SingleRightRotation(T->Right);
    return SingleLeftRotation(T);
}



