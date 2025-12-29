#include <iostream>
#include <vector>
using namespace std;

void dfs(int node);

vector<int> graph[100001];
int visited[100001] = {};
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

    visited[1] = 1;
    dfs(1);

    for (int i = 2; i <= n; i++) {
    //endl -> \n
    //endl의 특징: 단순히 줄을 바꾸는 것뿐만 아니라, 출력 버퍼를 비우는 flush() 작업을 강제로 수행합니다.
    //"\n"을 사용하면 버퍼가 꽉 찼을 때만 출력하므로 훨씬 빠릅니다.
        cout << res[i] << "\n";
    }

    return 0;
}

void dfs(int node) {
    for (int g : graph[node]) {
        if (visited[g] == 0) {
            visited[g] = 1;
            res[g] = node;
            dfs(g);
        }
    }
}