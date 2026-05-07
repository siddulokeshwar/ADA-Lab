#include <stdio.h>
int graph[20][20];

int main() {
    int n;
    printf("Enter no.of vertex: ");
    scanf("%d", &n);
    int visited[n], in[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        in[i] = 0;
    }
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j]) in[j]++;
        }
    }

    int completed = 0;
    printf("Topological Order:\n");
    while (completed < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0 && visited[i] == 0) {
                visited[i] = 1;
                printf("%d ", i);
                for (int j = 0; j < n; j++) {
                    if (graph[i][j]) in[j]--;
                }
                completed++;
                found = 1;
            }
        }

        if (!found) {
            printf("\nCycle detected! Topological sort not possible.\n");
            break;
        }
    }

    return 0;
}
