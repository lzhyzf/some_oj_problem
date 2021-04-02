#include <stdio.h>
#include <stdlib.h>
/* 图的邻接矩阵表示法 */

#define MaxVertexNum 100    /* 最大顶点数设为100 */
#define INFINITY 65535        /* ∞设为双字节无符号整数的最大值65535*/
typedef int Vertex;         /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;        /* 边的权值设为整型 */

/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1, V2;      /* 有向边<V1, V2> */
    WeightType Weight;  /* 权重 */
};
typedef PtrToENode Edge;

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;  /* 顶点数 */
    int Ne;  /* 边数   */
    WeightType G[MaxVertexNum][MaxVertexNum]; /* 邻接矩阵 */
};
typedef PtrToGNode MGraph; /* 以邻接矩阵存储的图类型 */

MGraph CreateGraph( int VertexNum )
{ /* 初始化一个有VertexNum个顶点但没有边的图 */
    Vertex V, W;
    MGraph Graph;

    Graph = (MGraph)malloc(sizeof(struct GNode)); /* 建立图 */
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    /* 初始化邻接矩阵 */
    /* 注意：这里默认顶点编号从0开始，到(Graph->Nv - 1) */
    for (V=0; V<Graph->Nv; V++)
        for (W=0; W<Graph->Nv; W++)
            Graph->G[V][W] = INFINITY;
    return Graph;
}

void InsertEdge( MGraph Graph, Edge E )
{
    /* 插入边 <V1, V2> */
    Graph->G[E->V1][E->V2] = E->Weight;
    /* 若是无向图，还要插入边<V2, V1> */
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
    if ( Graph->Ne != 0 ) { /* 如果有边 */
        E = (Edge)malloc(sizeof(struct ENode)); /* 建立边结点 */
        /* 读入边，格式为"起点 终点 权重"，插入邻接矩阵 */
        for (i=0; i<Graph->Ne; i++) {
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            E->V1--;
            E->V2--;   /*因为动物下标从1开始，所以插入边时顶点要减去1*/
            /* 注意：如果权重不是整型，Weight的读入格式要改 */
            InsertEdge( Graph, E );
        }
    }
    return Graph;
}

void Floyd(MGraph Graph,WeightType D[][MaxVertexNum])
{
    Vertex i, j, k;
    /*初始化*/
    for(i = 0; i < Graph->Nv; i++){
        for(j = 0; j < Graph->Nv; j++){
            D[i][j] = Graph->G[i][j];
        }
    }
        for(k = 0; k < Graph->Nv; k++){
            for(i = 0; i < Graph->Nv; i++){
                for(j = 0; j < Graph->Nv; j++){
                    if(D[i][k] + D[k][j] < D[i][j]){
                        D[i][j] = D[i][k] + D[k][j];
                        if(i == j && D[i][j] < 0)   /*发现负值圈*/
                        return;
                    }
                }
            }
        }

}

WeightType FindMaxDist(WeightType D[][MaxVertexNum],  Vertex i, int N)
{
    WeightType MaxDist = 0;
    Vertex j;
    for(j = 0; j < N; j++){
        if(i != j && D[i][j] > MaxDist) MaxDist = D[i][j];
    }
    return MaxDist;
}

void FindAnimal(MGraph Graph)
{/*将传入的图进行floyd算法，得到各个顶点最短距离的邻接矩阵，
    然后找到每个顶点最难变成的动物（一行中的最大值），然后
    在这些最大值里面找最小值（变成最难变的动物的咒语最短）*/
    WeightType D[MaxVertexNum][MaxVertexNum], MaxDist, MinDist;
    Vertex Animal, i;

    Floyd(Graph, D);

    MinDist = INFINITY;
    for(i = 0; i < Graph->Nv; i++){
        MaxDist = FindMaxDist(D, i, Graph->Nv);
        if(MaxDist == INFINITY){
            printf("0\n");               /*说明图不连通，带一只动物不能变成所有动物*/
            return;
        }
        if(MaxDist < MinDist){
            MinDist = MaxDist;
            Animal = i + 1;
        }
    }
    printf("%d %d", Animal, MinDist);
}

int main(){
    MGraph Graph;

    Graph = BuildGraph();
    FindAnimal(Graph);
    return 0;
}
