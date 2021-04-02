#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxVertex 101
#define Infinity 36600
typedef int Vertex;
typedef int WeightType;

//边的定义
typedef struct ENode *PtrToENode;
struct ENode
{
    Vertex V1, V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

//图结点定义
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv, Ne;
    WeightType G[MaxVertex][MaxVertex];
};
typedef PtrToGNode MGraph;

MGraph CreateGraph(int VertexNum)
{
    MGraph Graph = (PtrToGNode)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    for(int i = 1; i <= VertexNum; i++)
        for(int j = 1; j <= VertexNum; j++)
            Graph->G[i][j] = Infinity;
    return Graph;
}

void Insert(MGraph Graph, Edge E)
{
    Graph->G[E->V1][E->V2] = E->Weight;
    Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BulidGraph()
{
    int VertexNum;
    MGraph Graph;
    Edge E;

    scanf("%d", &VertexNum);
    Graph = CreateGraph(VertexNum);
    scanf("%d", &Graph->Ne);
    if(Graph->Ne){
        E = (PtrToENode)malloc(sizeof(struct ENode));
        for(int i = 0; i < Graph->Ne; i++){
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            Insert(Graph, E);
        }
    }
    return Graph;
}

void Floyd(MGraph Graph, int D[][MaxVertex], Vertex P[][MaxVertex])
{
    Vertex i, j, k;

    for(i = 1; i <= Graph->Nv; i++)
        for(j = 1; j <= Graph->Nv; j++){
            D[i][j] = Graph->G[i][j];
            P[i][j] = -1;
        }
    for(k = 1; k <= Graph->Nv; k++)
        for(i = 1; i <= Graph->Nv; i++)
            for(j = 1; j <= Graph->Nv; j++){
                if(D[i][k] + D[k][j] < D[i][j]){
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k;
                }
            }
}

int main()
{
    int i, j, D[MaxVertex][MaxVertex], P[MaxVertex][MaxVertex], max[MaxVertex] = {}, min = Infinity;
    Vertex V;
    MGraph Graph;

    Graph = BulidGraph();
    Floyd(Graph, D, P);
    for(i = 1; i <= Graph->Nv; i++){
        for(j = 1; j <= Graph->Nv; j++){
            if( i != j && D[i][j] > max[i]){
                if(D[i][j] == Infinity){
                    printf("0\n");
                    return 0;
                }
                max[i] = D[i][j];}
        }
    }


    for(i = 1; i <= Graph->Nv; i++){
        if(min > max[i]){
            min = max[i];
            V = i;
        }
    }
    printf("%d %d", V, max[V]);
    return 0;
}



