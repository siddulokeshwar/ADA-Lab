#include<stdio.h>

int main(){
    int n, m;
    printf("Enter no of objects: ");
    scanf("%d", &n);
    printf("Enter bag capacity: ");
    scanf("%d", &m);
    int w[n], p[n];
    printf("Enter weight and profit:\n");
    for(int i = 0; i < n; i++) {
        printf("obj %d: ", i+1);
        scanf("%d %d", &w[i], &p[i]);
    }
    int c[n+1][m+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0){
                c[i][j] = 0;
            }
            else if(w[i-1] <= j){
                if(c[i-1][j] > c[i-1][j - w[i-1]] + p[i-1]){
                    c[i][j] = c[i-1][j];
                } else {
                    c[i][j] = c[i-1][j - w[i-1]] + p[i-1];
                }
            }
            else{
                c[i][j] = c[i-1][j];
            }
        }
    }

    printf("\nDP Table:\n");
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++){
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    printf("\nMaximum Profit = %d\n", c[n][m]);
    int x[n];
    for(int i = 0; i < n; i++) x[i] = 0;

    int j = m;

    for(int i = n; i > 0; i--) {
        if(c[i][j] != c[i-1][j]) {
            x[i-1] = 1;
            j -= w[i-1];
        }
    }
    printf("\nObjects selected:");
    for(int i=0;i<n;i++){
        if(x[i]==1){
            printf("%d\t",i+1);
        }
    }
    return 0;
}
