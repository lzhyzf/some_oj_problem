#include<stdio.h>
#define MaxTree 10
#define Null -1     //��Null����Ϊ-1��������0����Ϊ�����±�Ϊ0�ĵط��Ա����нڵ�

typedef int Tree;
struct TreeNode{    //����������ڵ�
    Tree Left;
    Tree Right;
}T1[MaxTree];
int N,check[MaxTree];   //check��������Ѱ�����ĸ��ڵ�

Tree BuildTree(struct TreeNode T[]){
    int Root=Null,i;    //�տ�ʼ���ڵ���Ϊ�գ���Ϊ������ʱ��ɷ���Null
    char cl,cr;
    if(N){              //�����Ϊ�����Ļ�
        for(i=0;i<N;i++) check[i]=0;    //��check������Ϊ0
        for(i=0;i<N;i++){
            scanf("\n%c %c", &cl, &cr); //�ѻ��з�����ǰ��Ե�ǰ��scanf��Ļس��������һ��scanf�����лس���һ������
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
    Tree R1;     //���Ƚ�������R1Ϊ���ĸ��ڵ�
    int head = 0, rear = 0;
    int queue[MaxTree];
    int leaves = 0;

    scanf("%d",&N);
    R1=BuildTree(T1);

    queue[rear++] = R1;   //���ڵ����
    while (rear - head) {
        int node = queue[head++];       //���׽ڵ����
        if ((T1[node].Left == Null) && (T1[node].Right == Null)) {    //���Ҷ�ڵ�
            if (leaves)
                printf(" ");
            printf("%d", node);
            ++leaves;
        }
        if (T1[node].Left != Null) {       //������ڣ���������
            queue[rear++] = T1[node].Left;
        }
        if (T1[node].Right != Null) {      //������ڣ��Ҷ������
            queue[rear++] = T1[node].Right;
        }
    }
    return 0;
}
