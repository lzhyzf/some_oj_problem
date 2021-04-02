#include <stdio.h>

#define Null -1
#define false 0
#define true 1
typedef struct Node *PtrToNode;
typedef PtrToNode BT;
struct Node
{
    char Data;
    int Left, Right;
} Tree1[11], Tree2[11];

int CreateBT(BT Tree)//建树并返回根节点
{
    int i, visited[11], N, root = Null;
    char left, right;
    scanf("%d", &N);
    if(N)
    {
        for(i = 0; i < N; i++)
            visited[i] = 0;
        for(i = 0; i < N; i++)
        {
            getchar();
            scanf("%c %c %c", &Tree[i].Data, &left, &right);
            if(left != '-'){
                Tree[i].Left = left - '0';
                visited[left - '0'] = 1;
            }
            else
                Tree[i].Left = Null;
            if(right != '-'){
                Tree[i].Right = right - '0';
                visited[right - '0'] = 1;
            }
            else
                Tree[i].Right = Null;
        }
        for(i = 0; i < N; i++)
        {
            if(visited[i] == 0)
                root = i;
        }
    }
    return root;
}

int Issame(int t1, int t2)
{
    if(t1 == Null && t2 == Null) return true;//两树都为空则树同构
    if((t1 == Null && t2 != Null) || (t2 == Null && t1 != Null)) return false;//其中一个树为空另一个树不空则树不同构
    if(t1 != Null && t2 != Null)
    {
        if(Tree1[t1].Data != Tree2[t2].Data) return false;//两树都不空但是根元素不同则不同构
        else return ((Issame(Tree1[t1].Left, Tree2[t2].Left) && Issame(Tree1[t1].Right, Tree2[t2].Right)) || (Issame(Tree1[t1].Left, Tree2[t2].Right) && Issame(Tree1[t1].Right, Tree2[t2].Left)));
    }
}

int main()
{
    int N, t1, t2;
    //建树
    t1 = CreateBT(Tree1);
    t2 = CreateBT(Tree2);
    //判断是否同构
    if(Issame(t1, t2))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
