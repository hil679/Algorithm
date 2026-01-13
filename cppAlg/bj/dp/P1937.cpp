#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int dfs(int x, int y);
int n;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int arr[501][501] = {};
int dp[501][501] = {};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans = max(ans, dfs(i, j));
        }
    }

//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            cout << dp[i][j] << " ";
//            ans = max(ans, dp[i][j]);
//        }
//        cout << "\n";
//    }
    cout << ans + 1;
}

/*
2500 * 4 * 4 * 4
10000
*/
int dfs(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
        if (arr[x][y] >= arr[nx][ny]) continue;
        ret = max(ret, dfs(nx, ny) + 1);
        //dp[x][y] = max(dp[x][y], step - depth);
    }
    return ret;
}