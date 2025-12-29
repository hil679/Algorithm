#include <iostream>
#include <queue>
using namespace std;

void dfs(int x, int y);

int visited[1001][1001];
vector<int> graph[1001];
int main() {
    int v, e;
    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        visited[a][b] = 1;
        visited[b][a] = 1;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= v; i++) {
        visited[i][i] = 1;
        graph[i].push_back(i);
    }
    int ans = 0;
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= i; j++) {
            if (visited[i][j] == 1) {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans;
}

void dfs(int x, int y) {
    queue<int> q;
    q.push(x);
    q.push(y);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for(int g : graph[node]) {
            if (visited[node][g] == 1) {
                q.push(g);
                visited[node][g] = 0;
                visited[g][node] = 0;
            }
        }
    }
}