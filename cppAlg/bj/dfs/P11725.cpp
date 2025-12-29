#include <iostream>
#include <queue>
using namespace std;

void dfs(int node);

vector<int> graph[100000];
int visited[100000] = {};
int res[100001];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    for (int i = 2; i <= n; i++) {
        cout << res[i] << endl;
    }

    return 0;
}

void dfs(int node) {
    for (int g : graph[node]) {
        if (visited[g] == 0) {
            visited[g] = 1;
            res[g] = node;
            dfs(g);
            visited[g] = 0;
        }
    }
}