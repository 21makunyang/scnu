#include <stdio.h>
#include <stdlib.h>

#define MaxVertices 10 /* maximum number of vertices */
typedef int Vertex;    /* vertices are numbered from 0 to MaxVertices-1 */
typedef struct VNode *PtrToVNode;
struct VNode
{
    Vertex Vert;
    PtrToVNode Next;
};
typedef struct GNode *Graph;
struct GNode
{
    int NumOfVertices;
    int NumOfEdges;
    PtrToVNode *Array;
};

Graph ReadG(); /* details omitted */

void PrintV(Vertex V)
{
    printf("%d ", V);
}

void StronglyConnectedComponents(Graph G, void (*visit)(Vertex V));

int main()
{
    Graph G = ReadG();
    StronglyConnectedComponents(G, PrintV);
    return 0;
}

/* Your function will be put here */
Graph ReadG()
{
    int n, m;
    Graph g = (Graph)malloc(sizeof(struct GNode));
    scanf("%d %d", &n, &m);
    g->NumOfVertices = n;
    g->NumOfEdges = m;
    g->Array = (PtrToVNode *)malloc(n * sizeof(PtrToVNode));
    PtrToVNode p;
    Vertex be, en;
    for (int i = 0; i < n; i++)
    {
        g->Array[i] = (PtrToVNode)malloc(sizeof(struct VNode));
        g->Array[i]->Vert = i;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &be, &en);
        p = (PtrToVNode)malloc(sizeof(struct VNode));
        // p = g->Array[be];
        p->Next = g->Array[be]->Next;
        p->Vert = en;
        g->Array[be]->Next = p;
    }
    return g;
}
int visited[MaxVertices];
int predfn[MaxVertices], postdfn[MaxVertices];
int prefn, posfn;
int getMaxIndex(int n)
{
    int maxIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (maxIndex == -1 || postdfn[maxIndex] < postdfn[i]))
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}
void dfs(int v, Graph G, int t, void (*visit)(Vertex V))
{
    visited[v] = 1;
    prefn++;
    predfn[v] = prefn;
    PtrToVNode p = G->Array[v]->Next;
    while (p != NULL)
    {
        if (!visited[p->Vert])
            dfs(p->Vert, G, t, visit);
        p = p->Next;
    }
    posfn++;
    postdfn[v] = posfn;
    if (t == 2)
    {
        visit(v);
    }
    return;
}

void StronglyConnectedComponents(Graph G, void (*visit)(Vertex V))
{
    int n = G->NumOfVertices;
    if(G->NumOfVertices==1){
        visit(0);
        printf("\n");
        return;
    }
    prefn = 0, posfn = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i, G, 1, visit);
    }
    Graph g_ = (Graph)malloc(sizeof(struct GNode));
    g_->Array = (PtrToVNode *)malloc(n * sizeof(PtrToVNode));
    for (int i = 0; i < n; i++)
    {
        g_->Array[i] = (PtrToVNode)malloc(sizeof(struct VNode));
        g_->Array[i]->Vert = i;
        visited[i] = 0;
    }
    PtrToVNode p, tem;
    for (int i = 0; i < n; i++)
    {
        p = G->Array[i]->Next;
        while (p != NULL)
        {
            tem = (PtrToVNode)malloc(sizeof(struct VNode));
            tem->Vert = i;
            tem->Next = g_->Array[p->Vert]->Next;
            g_->Array[p->Vert]->Next = tem;

            p = p->Next;
        }
    }
    int maxIdx;
    for (int i = 0; i < n; i++)
    {
        maxIdx = getMaxIndex(n);
        if (maxIdx == -1)
            break;
        printf("t%d\n",i);
        dfs(maxIdx, g_, 2, visit);
        printf("\n");
    }

    return;
}