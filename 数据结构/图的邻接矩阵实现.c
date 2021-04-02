#include <stdio.h>

#define MaxVertexNum 100    // 最大顶点数设为100
#define INFINITY 65535

typedef int Vertex;//用顶点下标表示顶点，为整型
typedef int WeightType;//边权值为整型
typedef char DataType;//顶点存储数据为字符型

/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1, V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

/* 图结点定义 */
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;//定点数
    int Ne;//边数
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Data[MaxVertexNum];
};
typedef PtrToGNode MGraph;//以邻接矩阵存储的图类型

MGraph CreateGraph(int VertexNum)
{/* 初始化一个有VertexNum个顶点但没有边的图 */
    Vertex V, W;
    MGraph Graph;

    Graph = (MGraph)malloc(sizeof(struct GNode));// 建立图
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    /* 初始化邻接矩阵 */
    /* 注意：这里默认顶点编号从0开始，到(Graph->Nv - 1) */
    for(V = 0; V < Graph->Nv - 1; V++){
        for(W = 0; W < Graph->Nv - 1; W++){
            Graph->G[V][W] = INFINITY;
        }
    }
    return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
    /* 插入边 <V1, V2> */
    Graph->G[E->V1][E->V2] = E->Weight;
    /* 若是无向图，还要插入边<V2, V1> */
    Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BulidGraph()
{
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;

    scanf("%d", &V);//读入顶点数
    Graph = CreateGraph(V);
    scanf("%d", &(Graph->Ne));//读入边数
    if ( Graph->Ne != 0 ){
        E = (Edge)malloc(sizeof(struct ENode));
        for (i = 0; i < Graph->Ne; i++){
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            InsertEdge(Graph, E);
    }
    }
    /* 如果顶点有数据的话，读入数据 */
    for (V=0; V<Graph->Nv; V++)
        scanf(" %c", &(Graph->Data[V]));

    return Graph;
}

int main(){
    return 0;
}
