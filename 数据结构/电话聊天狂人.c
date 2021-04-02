#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define KEYLENGTH 11/* �ؼ����ַ�������󳤶� */
#define MAXTABLESIZE 100000/* ɢ�б����󳤶� */
#define MAXD 5/* �绰ȡ�����λΪ�ؼ��� */
typedef enum{false, true} bool;
typedef char ElementType[KEYLENGTH + 1];/* �ؼ����������ַ��� */
typedef int Index;/* ɢ�е�ַ���� */
/******** �����ǵ�����Ķ��� ********/
typedef struct LNode *PtrToLNode;
struct LNode
{
    ElementType Data;
    PtrToLNode Next;
    int Count;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
/******** �����ǵ�����Ķ��� ********/

typedef struct TblNode *HashTable;/* ɢ�б����� */
struct TblNode
{/* ɢ�б��㶨�� */
    int TableSize;/* �����󳤶� */
    List Heads;/* ָ������ͷ�������� */
};

int NextPrime(int N)
{/* ���ش���N�Ҳ�����MAXTABLESIZE����С���� */
    int i;
    N = (N % 2) ? N + 2 : N + 1;/*�Ӵ���N����һ��������ʼ */

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
{//����ȡ�෢��ϣɢ�к���
    return Key % p;
}

Position Find(HashTable H, ElementType Key)
{
    Index pos;
    Position P;

    pos = Hash(atoi(Key + KEYLENGTH - MAXD), H->TableSize);/* ��ʼɢ��λ�� */
    P = H->Heads[pos].Next;/* �Ӹ�����ĵ�1����㿪ʼ */
    while(P && strcmp(Key, P->Data))/* ��δ����β������Keyδ�ҵ�ʱ */
        P = P->Next;
    return P;/* ��ʱP����ָ���ҵ��Ľ�㣬����ΪNULL */
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
        pos = Hash(atoi(Key + KEYLENGTH - MAXD), H->TableSize);/* ��ʼɢ��λ�� */
        /* ��NewCell����ΪH->Heads[Pos]����ĵ�1����� */
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
    for(i = 0; i < H->TableSize; i++)//ɨ������
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
