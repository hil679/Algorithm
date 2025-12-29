#include <iostream>
#include <queue>
using namespace std;

void dfs(int x);

int visited[1001];
vector<int> graph[1001];
int main() {
    int v, e;
    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ans = 0;
    for (int i = 1; i <= v; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            dfs(i);
            ans++;
        }
    }
    cout << ans;
}

void dfs(int x) {
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for(int g : graph[node]) {
            if (visited[g] == 0) {
                q.push(g);
                visited[g] = 1;
            }
        }
    }
}