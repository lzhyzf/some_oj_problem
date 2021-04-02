#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 1001    /* ��󶥵�����Ϊ1001*/
#define INFINITY 65535        /* ����Ϊ˫�ֽ��޷������������ֵ65535*/
typedef int Vertex;         /* �ö����±��ʾ����,Ϊ���� */
typedef int WeightType;        /* �ߵ�Ȩֵ��Ϊ���� */

/* �ߵĶ��� */
typedef struct ENode *PtrToENode;
struct ENode
{
    Vertex V1, V2;      /* �����<V1, V2> */
    WeightType Weight;  /* Ȩ�� */
};
typedef PtrToENode Edge;

/* ͼ���Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;  /* ������ */
    int Ne;  /* ����   */
    WeightType G[MaxVertexNum][MaxVertexNum]; /* �ڽӾ��� */
};
typedef PtrToGNode MGraph; /* ���ڽӾ���洢��ͼ���� */



MGraph CreateGraph( int VertexNum )
{
    /* ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */
    Vertex V, W;
    MGraph Graph;

    Graph = (MGraph)malloc(sizeof(struct GNode)); /* ����ͼ */
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    /* ��ʼ���ڽӾ��� */
    /* ע�⣺����Ĭ�϶����Ŵ�1��ʼ����Graph->Nv*/
    for (V=1; V<=Graph->Nv; V++)
        for (W=1; W<=Graph->Nv; W++)
            Graph->G[V][W] = INFINITY;

    return Graph;
}

void InsertEdge( MGraph Graph, Edge E )
{
    /* ����� <V1, V2> */
    Graph->G[E->V1][E->V2] = E->Weight;
     /* ����� <V2, V1> */
    Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph()
{
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;

    scanf("%d", &Nv);   /* ���붥����� */
    Graph = CreateGraph(Nv); /* ��ʼ����Nv�����㵫û�бߵ�ͼ */

    scanf("%d", &(Graph->Ne));   /* ������� */
    if ( Graph->Ne != 0 )   /* ����б� */
    {
        E = (Edge)malloc(sizeof(struct ENode)); /* �����߽�� */
        /* ����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ��� */
        for (i=0; i<Graph->Ne; i++)
        {
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            /* ע�⣺���Ȩ�ز������ͣ�Weight�Ķ����ʽҪ�� */
            InsertEdge( Graph, E );
        }
    }
    return Graph;
}

Vertex Findmin(MGraph Graph, int D[])
{
    int mind = INFINITY;
    Vertex i, minv;
    for(i = 1; i <= Graph->Nv; i++){
        if(D[i] && D[i] < mind)//����û�б����ʹ���������С����
        {
            mind = D[i];
            minv = i;
        }
    }
    if(mind < INFINITY) return minv;
    else return -1;
}

int myPrim(MGraph Graph, Vertex S)
{
    int D[MaxVertexNum], cnt = 0, tolprice = 0;
    Vertex i, V;

    for(i = 1; i <= Graph->Nv; i++)
        D[i] = Graph->G[S][i];
    D[S] = 0;
    cnt++;
    while(1){
        V = Findmin(Graph, D);
        if(V == -1) break;
        cnt++;
        tolprice += D[V];
        D[V] = 0;
        for(i = 1; i <= Graph->Nv; i++){
            if ( D[i]!=0 && Graph->G[V][i]<INFINITY ) {
            /* ��W��V���ڽӵ㲢��δ����¼ */
                if ( Graph->G[V][i] < D[i] ) {
                /* ����¼Vʹ��dist[W]��С */
                    D[i] = Graph->G[V][i]; /* ����dist[W] */
                }
            }
        }
    }
    if(cnt < Graph->Nv) return -1;
    return tolprice;
}

int main()
{
    int price;
    MGraph Graph = BuildGraph();
    printf("%d", myPrim(Graph, 1));
    return 0;
}

