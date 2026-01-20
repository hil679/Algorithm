#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[100001];

struct minSegTree {
    vector<int> tree;
    int n;
    minSegTree(int n) : n(n), tree(4*n) {}
    void build(int node, int l, int r) {
        if (r == l) {
            tree[node] = arr[r];
            return;
        }
        int mid = (r+l) / 2;
        build(node*2, l, mid);
        build(node*2+1, mid+1, r);

        tree[node] = min(tree[node*2], tree[node*2+1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 1<<31 - 1;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l+r)/2;
        return min(query(node*2, l, mid, ql, qr), query(node*2+1, mid+1, r, ql, qr));
    }
};

struct maxSegTree {
    vector<int> tree;
    int n;
    maxSegTree(int n) : n(n), tree(4*n) {}
    void build(int node, int l, int r) {
        if (r == l) {
            tree[node] = arr[r];
            return;
        }
        int mid = (r+l) / 2;
        build(node*2, l, mid);
        build(node*2+1, mid+1, r);

        tree[node] = max(tree[node*2], tree[node*2+1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return -1<<31;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l+r)/2;
        return max(query(node*2, l, mid, ql, qr), query(node*2+1, mid+1, r, ql, qr));
    }
};



int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    minSegTree minSt(n);
    minSt.build(1, 1, n);
//    for (int i : minSt.tree) {
//        cout << i << " ";
//    }
//    cout << endl;

    maxSegTree maxSt(n);
    maxSt.build(1, 1, n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << minSt.query(1, 1, n, a, b) << " ";
        cout << maxSt.query(1, 1, n, a, b) << "\n";
    }

}