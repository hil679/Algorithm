#include <stdio.h>
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int arr[n+1][m+1] = {};
    int c = 1, row = 1, col = 1, dir = 0;
    while (c <= n*m) {
        arr[row][col] = c++;

        row += dx[dir];
        col += dy[dir];
        if (arr[row][col] != 0 || row > n || row <=0 || col > m || col <= 0) {
            row -= dx[dir];
            col -= dy[dir];
            dir = (dir+1)%4;
            row += dx[dir];
            col += dy[dir];
        }
        //  printf("%d %d\n", row, col);
    }
    
    for (int i = 1; i <=n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
