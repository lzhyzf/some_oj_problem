 #include <stdio.h>
 #include <stdlib.h>
    /* ͼ���ڽӾ����ʾ�� */

    #define MaxVertexNum 500    /* ��󶥵�����Ϊ100 */
    #define INFINITY 65535        /* ����Ϊ˫�ֽ��޷������������ֵ65535*/
    #define true 1
    #define ERROR -1
    #define false -1
    typedef int Vertex;         /* �ö����±��ʾ����,Ϊ���� */
    typedef int WeightType;        /* �ߵ�Ȩֵ��Ϊ���� */

    /* �ߵĶ��� */
    typedef struct ENode *PtrToENode;
    struct ENode{
        Vertex V1, V2;      /* �����<V1, V2> */
        WeightType Distance;  /* Ȩ�ؾ��� */
        WeightType Cost;  /* Ȩ��·�� */
    };
    typedef PtrToENode Edge;

    /* ͼ���Ķ��� */
    typedef struct GNode *PtrToGNode;
    struct GNode{
        int Nv;  /* ������ */
        int Ne;  /* ����   */
        WeightType D[MaxVertexNum][MaxVertexNum]; /* �ڽӾ��� */
        WeightType C[MaxVertexNum][MaxVertexNum]; /* �ڽӾ��� */
    };
    typedef PtrToGNode MGraph; /* ���ڽӾ���洢��ͼ���� */



    MGraph CreateGraph( int VertexNum )
    { /* ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */
        Vertex V, W;
        MGraph Graph;

        Graph = (MGraph)malloc(sizeof(struct GNode)); /* ����ͼ */
        Graph->Nv = VertexNum;
        Graph->Ne = 0;
        /* ��ʼ���ڽӾ��� */
        /* ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) */
        for (V=0; V<Graph->Nv; V++)
            for (W=0; W<Graph->Nv; W++){
                Graph->D[V][W] = INFINITY;
                Graph->C[V][W] = INFINITY;
            }
        return Graph;
    }

    void InsertEdge( MGraph Graph, Edge E )
    {
         /* ����� <V1, V2> */
         Graph->D[E->V1][E->V2] = E->Distance;
         Graph->C[E->V1][E->V2] = E->Cost;
         /* ��������ͼ����Ҫ�����<V2, V1> */
         Graph->D[E->V2][E->V1] = E->Distance;
         Graph->C[E->V2][E->V1] = E->Cost;
    }

    MGraph BuildGraph(MGraph Graph)
    {
        Edge E;
        Vertex V;
        int Nv, i;

        if ( Graph->Ne != 0 ) { /* ����б� */
            E = (Edge)malloc(sizeof(struct ENode)); /* �����߽�� */
            /* ����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ��� */
            for (i=0; i<Graph->Ne; i++) {
                scanf("%d %d %d %d", &E->V1, &E->V2, &E->Distance, &E->Cost);
                /* ע�⣺���Ȩ�ز������ͣ�Weight�Ķ����ʽҪ�� */
                InsertEdge( Graph, E );
            }
        }
        return Graph;
    }



Vertex FindMinDist( MGraph Graph, int dist[], int collected[] )
{ /* ����δ����¼������dist��С�� */
    Vertex MinV, V;
    int MinDist = INFINITY;

    for (V=0; V<Graph->Nv; V++) {
        if ( collected[V]==false && dist[V]<MinDist) {
            /* ��Vδ����¼����dist[V]��С */
            MinDist = dist[V]; /* ������С���� */
            MinV = V; /* ���¶�Ӧ���� */
        }
    }
    if (MinDist < INFINITY) /* ���ҵ���Сdist */
        return MinV; /* ���ض�Ӧ�Ķ����±� */
    else return ERROR;
}

void Dijkstra( MGraph Graph, int *dist, int *path, int *cost, Vertex S )
{
    int collected[MaxVertexNum];
    Vertex V, W;

    /* ��ʼ�����˴�Ĭ���ڽӾ����в����ڵı���INFINITY��ʾ */
    for ( V=0; V<Graph->Nv; V++ ) {
        dist[V] = Graph->D[S][V];
        if ( dist[V]<INFINITY )
            path[V] = S;
        else
            path[V] = -1;
        collected[V] = false;
    }
    /* �Ƚ�������뼯�� */
    dist[S] = 0;
    collected[S] = true;

    while (1) {
        /* V = δ����¼������dist��С�� */
        V = FindMinDist( Graph, dist, collected );
        if ( V==ERROR ) /* ��������V������ */
            break;      /* �㷨���� */
        collected[V] = true;  /* ��¼V */
        for( W=0; W<Graph->Nv; W++ ) /* ��ͼ�е�ÿ������W */
            /* ��W��V���ڽӵ㲢��δ����¼ */
            if ( collected[W]==false && Graph->D[V][W]<INFINITY ) {
                /* ����¼Vʹ��dist[W]��С */
                if ( dist[V]+Graph->D[V][W] < dist[W] ) {
                    dist[W] = dist[V]+Graph->D[V][W]; /* ����dist[W] */
                    path[W] = V; /* ����S��W��·�� */
                    cost[W] = cost[V] + Graph->C[V][W];
                }
                else if((dist[V]+Graph->D[V][W] == dist[W]) && (cost[V] + Graph->C[V][W] < cost[W])){
                    path[W] = V; /* ����S��W��·�� */
                    cost[W] = cost[V] + Graph->C[V][W];
                }
            }
    } /* while����*/
}

int main(){
    Vertex Nv, EdgeNum, Vb, Ve;
    MGraph Graph;
    Vertex path[MaxVertexNum];
    WeightType dist[MaxVertexNum];
    WeightType cost[MaxVertexNum];

    scanf("%d %d %d %d", &Nv, &EdgeNum, &Vb, &Ve);
    Graph = CreateGraph(Nv);
    Graph->Ne = EdgeNum;
    BuildGraph(Graph);
    Dijkstra(Graph, dist, path, cost, Vb);
    printf("%d %d", dist[Ve], cost[Ve]);
    return 0;
}
