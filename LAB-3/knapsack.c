#include <stdio.h>

int w[20], p[20], n, Used[20] = {0}, cap, u;
float r[20], totalProfit = 0;

int main() {
    printf("Enter no.of Objects: ");
    scanf("%d", &n);
    printf("Enter bag capacity: ");
    scanf("%d", &cap);

    for (int i = 0; i < n; i++) {
        printf("\nWeight and Price of obj(%d): ", i + 1);
        scanf("%d %d", &w[i], &p[i]);
        r[i] = (float)p[i] / w[i];
    }
    int count = 0;

    while (count < n && cap > 0) {
        float max = 0;
        for (int i = 0; i < n; i++) {
            if (r[i] > max && Used[i] == 0) {
                max = r[i];
                u = i;
            }
        }
        if (cap >= w[u]) {
            cap -= w[u];
            totalProfit += p[u];
            Used[u] = 1;
            count++;
        } else {
            totalProfit += r[u] * cap;
            cap = 0;
        }
    }

    printf("\nTotal profit is %.2f", totalProfit);
    return 0;
}
