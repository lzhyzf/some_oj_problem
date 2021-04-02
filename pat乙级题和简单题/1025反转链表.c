#include <stdio.h>                        //pat����4���δ���~�޷��������ģ����ǶԵ�
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

    scanf("%d %d %d", &firstadd, &N, &K);      //�׵�ַ�������������ÿK������
    for(i = 0; i < N; i++)                     //�������ݺ���һ�����ݵ�ַ,�Ե�ַΪ������������������
    {
        scanf("%d", &tempadd);
        scanf("%d %d", &Data[tempadd], &NextAdd[tempadd]);
    }
    L = (PtrToLNode)malloc(sizeof(struct LNode));                  //L��Ϊͷ���
    L->NextAdd = firstadd;
    L->Next = NULL;
    tail = L;
    for(i = 0; i < N; i++)
    {
        tempnode = (PtrToLNode)malloc(sizeof (struct LNode));                //װ���½��,����β�巨
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

