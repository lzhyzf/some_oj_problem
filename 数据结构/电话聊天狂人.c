#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define KEYLENGTH 11/* 关键词字符串的最大长度 */
#define MAXTABLESIZE 100000/* 散列表的最大长度 */
#define MAXD 5/* 电话取最后五位为关键字 */
typedef enum{false, true} bool;
typedef char ElementType[KEYLENGTH + 1];/* 关键词类型用字符串 */
typedef int Index;/* 散列地址类型 */
/******** 以下是单链表的定义 ********/
typedef struct LNode *PtrToLNode;
struct LNode
{
    ElementType Data;
    PtrToLNode Next;
    int Count;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
/******** 以上是单链表的定义 ********/

typedef struct TblNode *HashTable;/* 散列表类型 */
struct TblNode
{/* 散列表结点定义 */
    int TableSize;/* 表的最大长度 */
    List Heads;/* 指向链表头结点的数组 */
};

int NextPrime(int N)
{/* 返回大于N且不超过MAXTABLESIZE的最小素数 */
    int i;
    N = (N % 2) ? N + 2 : N + 1;/*从大于N的下一个奇数开始 */

    while(N <= MAXTABLESIZE)
    {
        for(i = 3; i < (int)sqrt(N) + 1; i++)
            if(N % i == 0) break;
        if(i == sqrt(N) + 1) break;
        else N += 2;
    }
    return N;
}

HashTable CreateTable(int TableSize)
{
    int i;
    HashTable H;

    H = (HashTable)malloc(sizeof(struct TblNode));
    H->TableSize = NextPrime(TableSize);
    H->Heads = (PtrToLNode)malloc(sizeof(struct LNode) * H->TableSize);
    for(i = 0; i < TableSize; i++)
    {
        H->Heads[i].Data[0] = '\0';
        H->Heads[i].Next = NULL;
        H->Heads[i].Count = 0;
    }
    return H;
}

int Hash(int Key, int p)
{//除留取余发哈希散列函数
    return Key % p;
}

Position Find(HashTable H, ElementType Key)
{
    Index pos;
    Position P;

    pos = Hash(atoi(Key + KEYLENGTH - MAXD), H->TableSize);/* 初始散列位置 */
    P = H->Heads[pos].Next;/* 从该链表的第1个结点开始 */
    while(P && strcmp(Key, P->Data))/* 当未到表尾，并且Key未找到时 */
        P = P->Next;
    return P;/* 此时P或者指向找到的结点，或者为NULL */
}

bool Insert(HashTable H, ElementType Key)
{
    Position P, NewCell;
    Index pos;

    P = Find(H, Key);
    if(!P)
    {
        NewCell = (Position)malloc(sizeof(struct LNode));
        strcpy(NewCell->Data, Key);
        pos = Hash(atoi(Key + KEYLENGTH - MAXD), H->TableSize);/* 初始散列位置 */
        /* 将NewCell插入为H->Heads[Pos]链表的第1个结点 */
        NewCell->Next = H->Heads[pos].Next;
        H->Heads[pos].Next = NewCell;
        NewCell->Count = 1;
        return true;
    }
    else{
        P->Count++;
        return false;
    }
}

void DestroyTable(HashTable H)
{
    int i;
    Position p, tmp;

    for(i = 0; i < H->TableSize; i++)
    {
        p = H->Heads[i].Next;
        while(p)
        {
            tmp = p->Next;
            free(p);
            p = tmp;
        }
    }
    free(H->Heads);
    free(H);
}

void ScanAndOutput(HashTable H)
{
    int i, max = 0, pcnt = 0;
    ElementType minphone;
    List Ptr;

    minphone[0] = '\0';
    for(i = 0; i < H->TableSize; i++)//扫描链表
    {
        Ptr = H->Heads[i].Next;
        while(Ptr)
        {
            if(Ptr->Count > max)
            {
                max = Ptr->Count;
                strcpy(minphone, Ptr->Data);
                pcnt = 1;
            }
            else if(Ptr->Count > max)
            {
                pcnt++;
                if(strcmp(minphone, Ptr->Data) > 0)
                    strcpy(minphone, Ptr->Data);
            }
            Ptr = Ptr->Next;
        }

    }
    printf("%s %d", minphone, max);
    if(pcnt > 1) printf(" %d", pcnt);
}

int main()
{
    int N, i;
    ElementType Key;
    HashTable H;

    scanf("%d", &N);
    H = CreateTable(N * 2);
    for(i = 0; i < N; i++)
    {
        scanf("%s", Key); Insert(H, Key);
        scanf("%s", Key); Insert(H, Key);
    }
    ScanAndOutput(H);
    DestroyTable(H);
    return 0;
}
