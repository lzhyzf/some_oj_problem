#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 10001
#define TRUE 1
#define FALSE 0
typedef int Vertex; //�����±�Ϊ����
typedef int WeightType; //��ȨֵΪ����
int visited[MaxVertexNum];//ͼ����ʱ�ж��Ƿ���ʹ�������

/*ͼ�ߵĶ���*/
typedef struct ENode *PtrToENode;
struct ENode
{
    Vertex V1, V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

/*�ڽӵ㶨��*/
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode
{
    Vertex AdjV;
    PtrToAdjVNode Next;
} ;

/*������㶨��*/
typedef struct VNode
{
    PtrToAdjVNode FirstEdge;
}AdjList[MaxVertexNum];

/*ͼ������*/
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;
    int Ne;
    AdjList G;
} ;
typedef PtrToGNode LGraph;//���ڽӱ���ͼ

/*��������*/
LGraph CreateGraph(int VertexNum);
void InsertEdge(LGraph Graph, Edge E);
LGraph BuildGraph();
int BFS(Vertex V, LGraph Graph);

int main(){
    double count;
    int i, m;
    LGraph Graph;

    Graph = BuildGraph();
    for(i = 1; i <= Graph->Nv; i++)            //�˴�iҲ��ͼ�����±�
    {
        for(m = 0; m < MaxVertexNum; m++){
            visited[m] = FALSE;
        }                                      //��ʼ��visited����
        count = BFS(i, Graph);
        printf("%d: %.2f%%\n", i, count/(Graph->Nv)*100);
    }
    return 0;
}

LGraph CreateGraph(int VertexNum)
{//��������ʼ��ͼ
    LGraph Graph;
    int i;

    Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    for(i = 1; i <= VertexNum; i++){
        Graph->G[i].FirstEdge = NULL;
    }
    return Graph;
}

void InsertEdge(LGraph Graph, Edge E)
{//�����
    PtrToAdjVNode NewNode;

    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V2;
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;

    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V1;
    NewNode->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph()
{//����������ͼ
    LGraph Graph;
    int i, Nv;
    Edge E;

    scanf("%d", &Nv);
    Graph = CreateGraph(Nv);
    scanf("%d", &(Graph->Ne));
    E = (Edge)malloc(sizeof( struct ENode));
    for(i = 1; i <= Graph->Ne; i++){
        scanf("%d %d", &(E->V1), &(E->V2));
        InsertEdge(Graph, E);
    }
    return Graph;
}

int BFS(Vertex V, LGraph Graph)
{
    int count = 1, real = 0, head = 0;
    int Queue[10001];
    int level = 0, last = V, tail;
    PtrToAdjVNode W;
    visited[V] = TRUE;
    Queue[head] = V;
    head++;
    while(real != head){
        V = Queue[real];
        real++;
        for(W = Graph->G[V].FirstEdge; W; W = W->Next){
            if (!visited[W->AdjV]){
                visited[W->AdjV] = TRUE;
                Queue[head] = W->AdjV;
                head++;
                count++;
                tail = W->AdjV;
            }
        }
        if (V == last){
            level++;
            last = tail;
        }
        if (level == 6) break;
    }
    return count;
}



