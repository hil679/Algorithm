#include <iostream>
using namespace std;

struct Info {
    int left;
    int right;
    int parent;
    int col;
    int level;
    Info() : parent(-1), left(-1), right(-1) {}
};

Info node[10001];
int c = 1;
int ans[10001][2];
void inorder(int root, int level) {
    if (root == -1) return;
    inorder(node[root].left, level+1);
    
    ans[level][0] = min(ans[level][0], c);
    ans[level][1] = max(ans[level][1], c);
    node[root].col = c++;
    node[root].level = level;
    
    inorder(node[root].right, level+1);
}

int main() {
    int n;
    cin >> n;
    for (int i= 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        node[a].left = b;
        node[a].right = c;
        if (b != -1)
            node[b].parent = a;
        if (c != -1)
            node[c].parent = a;
    }

    int root = 1;
    while(true) {
        if (node[root].parent == -1) break;
        root = node[root].parent;
    }

    for(int i= 1; i <= 15; i++) {
        ans[i][0] = n;
    } 
    inorder(root, 1);
    int lev, a = -1;
    for (int i = 1; i <= 15; i++) {
        if (a < ans[i][1] - ans[i][0]) {
            a = ans[i][1] - ans[i][0];
            lev = i;
        }
    }
    cout <<lev << " "<< a+1;
}
