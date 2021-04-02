#include<stdio.h>
#define MaxTree 10
#define Null -1     //将Null定义为-1而不能是0，因为数组下标为0的地方仍保存有节点

typedef int Tree;
struct TreeNode{    //定义二叉树节点
    Tree Left;
    Tree Right;
}T1[MaxTree];
int N,check[MaxTree];   //check数组用于寻找树的根节点

Tree BuildTree(struct TreeNode T[]){
    int Root=Null,i;    //刚开始将节点置为空，若为空树的时候可返回Null
    char cl,cr;
    if(N){              //如果不为空树的话
        for(i=0;i<N;i++) check[i]=0;    //将check数组置为0
        for(i=0;i<N;i++){
            scanf("\n%c %c", &cl, &cr); //把换行符放在前面吃掉前面scanf后的回车，而最后一个scanf不能有回车，一举两得
            if(cl!='-'){
                T[i].Left=cl-'0';
                check[T[i].Left]=1;
            }
            else
                T[i].Left=Null;

            if(cr!='-'){
                T[i].Right=cr-'0';
                check[T[i].Right]=1;
            }
            else
                T[i].Right=Null;

        }
        for(i=0;i<N;i++)
            if(!check[i])   break;
        Root=i;
    }
    return Root;
}


int main(){
    Tree R1;     //首先建立树，R1为树的根节点
    int head = 0, rear = 0;
    int queue[MaxTree];
    int leaves = 0;

    scanf("%d",&N);
    R1=BuildTree(T1);

    queue[rear++] = R1;   //根节点入队
    while (rear - head) {
        int node = queue[head++];       //队首节点出队
        if ((T1[node].Left == Null) && (T1[node].Right == Null)) {    //输出叶节点
            if (leaves)
                printf(" ");
            printf("%d", node);
            ++leaves;
        }
        if (T1[node].Left != Null) {       //如果存在，左儿子入队
            queue[rear++] = T1[node].Left;
        }
        if (T1[node].Right != Null) {      //如果存在，右儿子入队
            queue[rear++] = T1[node].Right;
        }
    }
    return 0;
}
