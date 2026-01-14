#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1000001][2]; //얼리어답터 개수
vector<int> g[1000001];
/*
1 0 -> 1
1 1 -> 0

2 0 -> 1
2 1 -> 0

5 0 -> 1
5 1 -> 0
*/
void dfs(int u, int p) {
    dp[u][0] = 1; // 얼리어답터
    dp[u][1] = 0; // 얼리어답터 X

    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u);

        dp[u][1] += dp[v][0]; // 부모가 얼리어답터 아니라면, 자식은 얼리어답터
        dp[u][0] += min(dp[v][0], dp[v][1]); // 부모가 얼리어답터라면, 자식은 기든 아니든 상관 없음
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++) { // 트리는 간선 n-1개
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    //무방향 그래프 -> 루트 임의로
    dfs(1, 0);
    cout << min(dp[1][0], dp[1][1]);
}