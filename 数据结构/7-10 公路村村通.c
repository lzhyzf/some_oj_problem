#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 1001    /* 最大顶点数设为1001*/
#define INFINITY 65535        /* ∞设为双字节无符号整数的最大值65535*/
typedef int Vertex;         /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;        /* 边的权值设为整型 */

/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode
{
    Vertex V1, V2;      /* 有向边<V1, V2> */
    WeightType Weight;  /* 权重 */
};
typedef PtrToENode Edge;

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;  /* 顶点数 */
    int Ne;  /* 边数   */
    WeightType G[MaxVertexNum][MaxVertexNum]; /* 邻接矩阵 */
};
typedef PtrToGNode MGraph; /* 以邻接矩阵存储的图类型 */



MGraph CreateGraph( int VertexNum )
{
    /* 初始化一个有VertexNum个顶点但没有边的图 */
    Vertex V, W;
    MGraph Graph;

    Graph = (MGraph)malloc(sizeof(struct GNode)); /* 建立图 */
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    /* 初始化邻接矩阵 */
    /* 注意：这里默认顶点编号从1开始，到Graph->Nv*/
    for (V=1; V<=Graph->Nv; V++)
        for (W=1; W<=Graph->Nv; W++)
            Graph->G[V][W] = INFINITY;

    return Graph;
}

void InsertEdge( MGraph Graph, Edge E )
{
    /* 插入边 <V1, V2> */
    Graph->G[E->V1][E->V2] = E->Weight;
     /* 插入边 <V2, V1> */
    Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph()
{
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;

    scanf("%d", &Nv);   /* 读入顶点个数 */
    Graph = CreateGraph(Nv); /* 初始化有Nv个顶点但没有边的图 */

    scanf("%d", &(Graph->Ne));   /* 读入边数 */
    if ( Graph->Ne != 0 )   /* 如果有边 */
    {
        E = (Edge)malloc(sizeof(struct ENode)); /* 建立边结点 */
        /* 读入边，格式为"起点 终点 权重"，插入邻接矩阵 */
        for (i=0; i<Graph->Ne; i++)
        {
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            /* 注意：如果权重不是整型，Weight的读入格式要改 */
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
        if(D[i] && D[i] < mind)//顶点没有被访问过并且是最小距离
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
            /* 若W是V的邻接点并且未被收录 */
                if ( Graph->G[V][i] < D[i] ) {
                /* 若收录V使得dist[W]变小 */
                    D[i] = Graph->G[V][i]; /* 更新dist[W] */
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

