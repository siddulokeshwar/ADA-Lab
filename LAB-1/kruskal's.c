#include <stdio.h>
#define MAX 50
#define INF 999

int parent[MAX];
int find(int i)
{
    while(parent[i] != i)
        i = parent[i];
    return i;
}

int union_set(int i, int j)
{
    if(i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main()
{
    int n, i, j;
    int cost[MAX][MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    for(i = 0; i < n; i++)parent[i] = i;

    int edges = 0, mincost = 0;
    printf("\nEdges in MST:\n");
    while(edges < n - 1){
        int min = INF, u = -1, v = -1;
        for(i = 0; i < n; i++{
            for(j = 0; j < n; j++){
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        int x = find(u);
        int y = find(v);

        if(union_set(x, y))
        {
            printf("%d -> %d : %d\n", u, v, min);
            mincost += min;
            edges++;
        }
        cost[u][v] = cost[v][u] = INF;
    }

    printf("Minimum Cost = %d\n", mincost);

    return 0;
}
