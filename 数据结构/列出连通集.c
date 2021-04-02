#include <stdio.h>
#include <stdlib.h>

#define Infinity 30000
#define MAXVERTAXNUM 100
typedef int Vertex;
int visited[MAXVERTAXNUM] = {};//visited���飬��������ͼʱ��¼���ʹ��Ľ��

/*ͼ�ı߶���*/
typedef struct ENode *PtrToENode;
struct ENode
{
    Vertex V1, V2;
};
typedef PtrToENode Edge;

/*ͼ�Ľ�㶨��*/
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Ne, Nv;
    int G[MAXVERTAXNUM][MAXVERTAXNUM];
};
typedef PtrToGNode MGraph;

void InsertE(MGraph Graph, Edge E)
{
    Graph->G[E->V1][E->V2] = 1;
    Graph->G[E->V2][E->V1] = 1;
}

MGraph CreateGraph(int VertexNum)
{//������ͼ����ʼ��
    int i, j;
    MGraph Graph = (PtrToGNode)malloc(sizeof (struct GNode));

    Graph->Ne = 0;
    Graph->Nv = VertexNum;
    for(i = 0; i < Graph->Nv; i++)
        for(j = 0; j < Graph->Nv; j++)
            Graph->G[i][j] = Infinity;
    return Graph;
}

MGraph BulidGraph()
{//��ͼ�����붥��ͱ�����
    MGraph Graph;
    int VertexN, EdgeN, i;
    Edge E = (PtrToENode)malloc(sizeof(struct ENode));

    scanf("%d %d", &VertexN, &EdgeN);
    Graph = CreateGraph(VertexN);
    if(EdgeN)
    {
        Graph->Ne = EdgeN;
        for(i = 0; i < EdgeN; i++)
        {//�����
            scanf("%d %d", &E->V1, &E->V2);
            InsertE(Graph, E);
        }
    }
    return Graph;
}

void DFSot(MGraph Graph, Vertex V)
{
    Vertex W;

    printf(" %d", V);
    visited[V] = 1;

    for(W = 0; W < Graph->Nv; W++)
    {
        if(!visited[W] && Graph->G[V][W] == 1)
            DFSot(Graph, W);
    }
}

void BFSot(MGraph Graph, Vertex V)
{
    int head, tail, queue[MAXVERTAXNUM + 1];
    Vertex W, temp;

    head = tail = 0;
    queue[head++] = V;
    printf(" %d", V);
    visited[V] = 1;
    while(head - tail)
    {
        temp = queue[tail++];
        for(W = 0; W < Graph->Nv; W++)
        {
            if(!visited[W] && Graph->G[temp][W] == 1)
            {
                printf(" %d", W);
                visited[W] = 1;
                queue[head++] = W;
            }
        }
    }
}

int main()
{
    int i, j;
    MGraph Graph;

    Graph = BulidGraph();
    for(i = 0; i < Graph->Nv; i++){//DFSͼ
        if(!visited[i]) {
            printf("{");
            DFSot(Graph, i);
            printf(" }\n");
        }
    }
    for(i = 0; i < Graph->Nv; i++)//����visited����
        visited[i] = 0;
    for(i = 0; i < Graph->Nv; i++){//BFSͼ
        if(!visited[i]) {
            printf("{");
            BFSot(Graph, i);
            printf(" }\n");
        }
    }
    return 0;
}
