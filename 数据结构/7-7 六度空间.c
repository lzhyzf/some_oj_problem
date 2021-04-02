#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxVertexNum 10005
typedef int Vertex;
int visited[MaxVertexNum];

/*边的定义*/
typedef struct ENode *PtrToENode;
struct ENode
{
    Vertex V1, V2;
};
typedef PtrToENode Edge;

/*邻接点定义*/
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode
{
    Vertex V;
    PtrToAdjVNode Next;
};

/*邻接头结点定义*/
typedef struct VNode
{
    PtrToAdjVNode FirstAdjV;
} AdjVList[MaxVertexNum];

/*图结点定义*/
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Ne, Nv;
    AdjVList G;
};
typedef PtrToGNode LGraph;

void InsertEdge(LGraph Graph, Edge E)
{
    PtrToAdjVNode temp;
    temp = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    temp->V = E->V2;
    temp->Next = Graph->G[E->V1].FirstAdjV;
    Graph->G[E->V1].FirstAdjV = temp;
    //无向图还得再插入反向的边
    temp = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    temp->V = E->V1;
    temp->Next = Graph->G[E->V2].FirstAdjV;
    Graph->G[E->V2].FirstAdjV = temp;
}

LGraph CreateGraph(int VertexNum)
{
    LGraph Graph = (LGraph)malloc(sizeof (struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    for(int i = 1; i <= VertexNum; i++)//图顶点下标从1开始
        Graph->G[i].FirstAdjV = NULL;
    return Graph;
}

LGraph BulidGraph(int VertexNum)
{
    int EdgeNum;

    scanf("%d", &EdgeNum);
    LGraph Graph = CreateGraph(VertexNum);
    Graph->Ne = EdgeNum;
    if(EdgeNum)
    {
        Edge E = (PtrToENode)malloc(sizeof(struct ENode));
        for(int i = 0; i <EdgeNum; i++)
        {
            scanf("%d %d", &E->V1, &E->V2);
            InsertEdge(Graph, E);
        }
    }
    return Graph;
}

void InitVisited()
{
    for(int i = 0; i < MaxVertexNum; i++)
        visited[i] = 0;
}

int main()
{
    int i, VertexNum, q[MaxVertexNum], head, tail, level, cnt;
    Vertex w, last, first;
    LGraph Graph;
    PtrToAdjVNode W;

    scanf("%d", &VertexNum);
    Graph = BulidGraph(VertexNum);//建图读图
    for(i = 1; i <= VertexNum; i++)
    {
        InitVisited();//初始化visited数组
        level = tail = head = 0; cnt = 1;
        q[head++] = i;
        visited[i] = 1;
        first = i;
        while(head - tail){
            w = q[tail++];
            for(W = Graph->G[w].FirstAdjV; W; W = W->Next)
            {
                if(!visited[W->V]){
                    q[head++] = W->V;
                    visited[W->V] = 1;
                    cnt++;
                    last = W->V;
                }
            }
            if(w == first){
                level++;
                first = last;
            }
            if(level == 6)
                break;
        }
        printf("%d: %.2lf%%\n", i, 100 * (double)cnt / VertexNum);
    }
    return 0;
}







