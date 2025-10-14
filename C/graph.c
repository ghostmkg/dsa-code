#include <stdio.h>
#include <stdlib.h>

#define MAX_V 10

struct Graph 
{
    int adj[MAX_V][MAX_V];
    int nV;
};

void init(struct Graph* g, int V) 
{
    if (V > MAX_V) 
	{
        printf("Error: Max vertices exceeded.\n");
        exit(1);
    }
    g->nV = V;

    for (int i = 0; i < V; i++) 
	{
        for (int j = 0; j < V; j++) 
		{
            g->adj[i][j] = 0;
        }
    }
}

void add(struct Graph* g, int u, int v) 
{
    if (u >= 0 && u < g->nV && v >= 0 && v < g->nV) 
	{
        g->adj[u][v] = 1;
        g->adj[v][u] = 1;
    } 
	else 
	{
        printf("Error: Invalid vertex index.\n");
    }
}

void print(struct Graph* g) 
{
    printf("\nAdjacency Matrix:\n");

    printf("  ");
    for (int i = 0; i < g->nV; i++) 
	{
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < g->nV; i++) 
	{
        printf("%d ", i);
        for (int j = 0; j < g->nV; j++) 
		{
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

int main()
 {
    int V = 5;
    struct Graph g;
    init(&g, V);

    add(&g, 0, 1);
    add(&g, 0, 4);
    add(&g, 1, 2);
    add(&g, 1, 3);
    add(&g, 1, 4);
    add(&g, 2, 3);
    add(&g, 3, 4);

    print(&g);

    return 0;
}