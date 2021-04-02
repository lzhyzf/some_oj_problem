#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 500
#define Infinity 36660
#define ERROR -1
typedef int Vertex;
typedef int WeightType;
//�ߵĶ���
typedef struct ENode *PtrToENode;
struct ENode
{
    Vertex V1, V2;
    WeightType Distance, Charge;
};
typedef PtrToENode Edge;

//ͼ��㶨��
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Ne, Nv;
    WeightType D[MaxVertexNum][MaxVertexNum];
    WeightType C[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;

MGraph CreateGraph(int VertexNum)
{
    int i, j;
    MGraph Graph = (PtrToGNode)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    for(i = 0; i < VertexNum; i++)
        for(j = 0; j < VertexNum; j++)
        {
            Graph->D[i][j] = Infinity;
            Graph->C[i][j] = Infinity;
        }
    return Graph;
}

void Insert(MGraph Graph, Edge E)
{
    Graph->D[E->V1][E->V2] = E->Distance;
    Graph->C[E->V1][E->V2] = E->Charge;
    Graph->D[E->V2][E->V1] = E->Distance;
    Graph->C[E->V2][E->V1] = E->Charge;
}

MGraph BulidGraph(int Nv, int Ne)
{
    Edge E;
    MGraph Graph;
    Graph = CreateGraph(Nv);
    Graph->Ne = Ne;
    if(Ne){
        E = (PtrToENode)malloc(sizeof(struct ENode));
        for(int i = 0; i < Ne; i++){
            scanf("%d %d %d %d", &E->V1, &E->V2, &E->Distance, &E->Charge);
            Insert(Graph, E);
        }
    }
    return Graph;
}

Vertex Findmin(MGraph Graph, WeightType D[], WeightType C[], int Collected[])
{
    WeightType min = Infinity;
    Vertex minv, i;

    for(i = 0; i < Graph->Nv; i++)
        if(!Collected[i] && D[i] < min){
            min = D[i];
            minv = i;
        }
    if(min < Infinity) return minv;
    else return ERROR;
}

void myDijkstra(MGraph Graph, WeightType D[], WeightType C[], Vertex S , Vertex F)
{
    int Collected[MaxVertexNum] = {};
    Vertex V, i,j;

    for(i = 0; i < Graph->Nv; i++)
    {
        D[i] = Graph->D[S][i];
        C[i] = Graph->C[S][i];
    }
    D[S] = 0; C[S] = 0;
    Collected[S] = 1;
    while(1){
        V = Findmin(Graph, D, C, Collected);
        if(V == ERROR) break;
        else if(V == F) break;
        Collected[V] = 1;
        for(i = 0; i < Graph->Nv; i++){
            if(!Collected[i] && Graph->D[V][i] < Infinity)//���û���ռ�������V���ڽӵ�
            {
                if(D[V] + Graph->D[V][i] < D[i]){
                    D[i] = D[V] + Graph->D[V][i];
                    C[i] = C[V] + Graph->C[V][i];
                }
                else if(D[V] + Graph->D[V][i] == D[i] && C[V] + Graph->C[V][i] < C[i]){
                    C[i] = C[V] + Graph->C[V][i];
                }
            }
        }
    }
    printf("%d %d", D[F], C[F]);
}

int main()
{
    int Nv, Ne;
    Vertex S, F;
    WeightType D[MaxVertexNum], C[MaxVertexNum];
    MGraph Graph;

    scanf("%d %d %d %d", &Nv, &Ne, &S, &F);
    Graph = BulidGraph(Nv, Ne);//��ͼ��ͼ
    myDijkstra(Graph, D, C, S, F);//��Դ���·��Dijkstra�ı�
    return 0;
}


