#include <stdio.h>
int src, dest[100], cost[10][10], n, vis[20] = {0};
void Dijkstras();

void main() {
    printf("Enter no.of vertices: ");
    scanf("%d", &n);
    printf("Enter cost adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    printf("Enter source vertex: ");
    scanf("%d", &src);
    Dijkstras();
    for (int i = 1; i <= n; i++) {
        printf("\n%d -> %d = %d", src, i, dest[i]);
    }
    getch();
}

void Dijkstras() {
    int u, i, min, count;
    for (i = 1; i <= n; i++) {
        dest[i] = cost[src][i];
    }
    vis[src] = 1;
    count = 1;
    while (count < n) {
        min = 999;
        for (i = 1; i <= n; i++) {
            if (dest[i] < min && vis[i] == 0) {
                min = dest[i];
                u = i;
            }
        }
        vis[u] = 1;
        for (i = 1; i <= n; i++) {
            if ((dest[u] + cost[u][i] < dest[i]) && vis[i] == 0) {
                dest[i] = dest[u] + cost[u][i];
            }
        }
        count++;
    }
}
