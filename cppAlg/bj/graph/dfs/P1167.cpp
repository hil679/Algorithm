#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct node {
    int dist;
    int otherNode;
    node(int otherNode, int dist) : otherNode(otherNode), dist(dist) {}
};

vector<node> graph[100001];
int maxNode = 0, maxDist = 0;

int visited[100001];
void dfs(int node, int dist) {
    if(visited[node] == 1) return;
    visited[node] = 1;

    for (int i=0; i < graph[node].size(); i++) {
        dfs(graph[node][i].otherNode, dist + graph[node][i].dist);
        visited[graph[node][i].otherNode] = 1;
    }
    if (maxDist < dist) {
        maxDist = dist;
        maxNode = node;
    }

}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i<n; i++) {
        int node;
        cin >> node;
        int a, b;
        cin >> a;
        while(a != -1) {
            cin >> b;
            graph[node].push_back({a, b});
            cin >> a;
        }
    }

    dfs(1, 0);
    // cout << ma xDist;

    memset(visited, 0, sizeof(visited));
    maxDist = 0;
    dfs(maxNode, 0);

    cout << maxDist;
    return 0;
}