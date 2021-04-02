#include <stdio.h>                        //pat中有4个段错误~无法发现在哪，答案是对的
#include <stdlib.h>

typedef struct LNode *PtrToLNode;
struct LNode
{
    int Add, Data, NextAdd;
    PtrToLNode Next;
};

void ReVerseList(PtrToLNode NewL, int K)
{
    PtrToLNode New, Old, Temp;
    int cnt = 1;

    New = NewL->Next;
    Old = New->Next;
    while(cnt < K){
        Temp = Old->Next;
        Old->Next = New;
        Old->NextAdd = New->Add;
        New = Old;
        Old = Temp;
        cnt++;
    }
    NewL->Next->Next = Temp;
    NewL->Next->NextAdd = Temp->Add;
    NewL->Next = New;
    NewL->NextAdd = New->Add;
}

int main(){
    int N, K, i, j, firstadd, tempadd;
    int Data[100001], NextAdd[100001];
    PtrToLNode tempnode, tail, L, NewL;

    scanf("%d %d %d", &firstadd, &N, &K);      //首地址，链表结点个数，每K个逆序
    for(i = 0; i < N; i++)                     //输入数据和下一个数据地址,以地址为索引，保存在数组中
    {
        scanf("%d", &tempadd);
        scanf("%d %d", &Data[tempadd], &NextAdd[tempadd]);
    }
    L = (PtrToLNode)malloc(sizeof(struct LNode));                  //L成为头结点
    L->NextAdd = firstadd;
    L->Next = NULL;
    tail = L;
    for(i = 0; i < N; i++)
    {
        tempnode = (PtrToLNode)malloc(sizeof (struct LNode));                //装填新结点,采用尾插法
        tempnode->Add = tail->NextAdd;
        tempnode->Data = Data[tempnode->Add];
        tempnode->NextAdd = NextAdd[tempnode->Add];
        tail->Next = tempnode;
        tempnode->Next = NULL;
        tail = tempnode;
    }
    NewL = L;
    for(i = 0; i < N / K; i++){
        ReVerseList(NewL, K);
        for(j = 0; j < K; j++) NewL = NewL->Next;
    }
    L = L->Next;
    for(; L != NULL; L = L->Next)
    {
        if(L->NextAdd != -1)
            printf("%05d %d %05d\n", L->Add, L->Data, L->NextAdd);
        else
            printf("%05d %d %d\n", L->Add, L->Data, L->NextAdd);
    }
    return 0;



}

