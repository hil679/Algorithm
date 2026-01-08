#include <iostream>
#include <vector>
using namespace std;

int rm, answer = 0;
vector<int> tree[50];
void dfs(int root, int num) {
    if (root == rm) {
        if (num == 1) answer++;
        return;
    }
    int idx = 0;
    for (int node : tree[root]) {
        dfs(node, tree[root].size());
        idx++;
    }

    if (tree[root].empty()) {
        answer++;
        return;
    }
}
int main() {
    int n;
    cin >> n;
    int root;
    for (int i = 0; i < n; i++) {
        int parent;
        cin >> parent;
        if (parent == -1) root = i;
        else tree[parent].push_back(i);
    }
    cin >> rm;
    tree[rm].clear();
    dfs(root, 0);
    if (rm == root) cout << 0;
    else cout << answer;
}