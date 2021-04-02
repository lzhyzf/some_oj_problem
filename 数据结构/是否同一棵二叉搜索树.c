#include <stdio.h>

#define MAXSIZE 10

typedef struct TreeNode *Tree;
struct TreeNode{
    int v;
    Tree Left, Right;
    int flag;
};

Tree MakeTree(int N);                  //建造搜索树
int Judge(Tree T,int N);               //判断是否相同
void FreeTree(Tree T);
Tree Insert(Tree T,int V);
Tree NewNode(int V);
int check(Tree T, int V);
void ResetT(Tree T);

int main(){
    int N, L, i;                       //N 结点数， L 判断序列个数
    Tree T;

    scanf("%d %d", &N, &L);
    while (N){
        T = MakeTree(N);
        for (i = 0; i < L ; i++){
           if (Judge(T, N))
             printf("Yes\n");
           else
             printf("No\n");
           ResetT(T);                  //清除树中标记
        }
        FreeTree(T);
        scanf("%d %d", &N, &L);
    }
    return 0;
}

Tree MakeTree(int N){
    Tree T;
    int i, V;

    scanf("%d", &V);
    T = NewNode(V);
    for (i = 1; i < N; i++){
        scanf("%d", &V);
        T = Insert(T, V);
    }
    return T;
}

Tree NewNode(int V){
    Tree T;

    T = (Tree)malloc(sizeof (struct TreeNode));
    T->v = V;
    T->Left = T->Right = NULL;
    T->flag = 0;
    return T;
}

Tree Insert(Tree T,int V){
    if(!T)
        T = NewNode(V);
    else{
        if (V > T->v)
            T->Right = Insert(T->Right, V);
        else
            T->Left = Insert(T->Left, V);
            }
    return T;
}

int Judge(Tree T,int N){
    int i, V, flag = 0;

    scanf("%d", &V);
    if (V != T->v)
        flag = 1;
    else
        T->flag = 1;
    for (i = 1; i < N; i++){
        scanf("%d", &V);
        if ((!flag) && (!check(T, V)))
            flag = 1;
    }
    if (flag)
        return 0;
    else
        return 1;
}

int check(Tree T,int V){
    if (T->flag){
        if (V > T->v)
            return check(T->Right, V);
        else if (V < T->v)
            return check(T->Left, V);
        else
            return 0;
    }
    else{
        if (V == T->v){
            T->flag = 1;
            return 1;
        }
        else return 0;
    }
}

void ResetT(Tree T){
    if (T->Left)
        ResetT(T->Left);
    if (T->Right)
        ResetT(T->Right);
    T->flag = 0;
}

void FreeTree(Tree T){
    if (T->Left)
        FreeTree(T->Left);
    if (T->Right)
        FreeTree(T->Right);
        free(T);
}
