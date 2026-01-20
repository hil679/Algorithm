#include <iostream>
#include <vector>
using namespace std;

int n,m,k;
struct SegTree {
    int n;
    vector<long long> tree; // 구간합

    SegTree(int n): n(n), tree(4*n, 0) {}

    void build(const long long * arr, int node, int l, int r) {
        if (l == r) { tree[node] = arr[l]; return; }
        int mid = (l + r) / 2;
        /*
        *2, *2+1
        1층: 1
        2층: 2, 3
        3층: 4, 5, 6, 7
        4층: 8, 9, 10, 11, 12, 13, 14, 15 …

        2의 자식은 4,5 → 2*2, 2*2+1
        */
        build(arr, node*2, l, mid);
        build(arr, node*2+1, mid+1, r);
        tree[node] = tree[node*2] + tree[node*2+1];
    }

    /*
    update(node, l, r, idx, val)
    = “a[idx]를 val로 바꿨으니, 관련된 구간합들을 갱신해라

    (1) leaf까지 내려감
    l==r이면 그 leaf는 idx 그 자체임
    tree[node] = val

    (2) 돌아오면서 부모 갱신
    재귀에서 돌아오면
    tree[node] = tree[left] + tree[right]

    왜 O(log n)이냐?
    idx는 딱 한 경로로만 내려감 (루트→leaf)
    트리 높이가 log n
    */
    /*
        *2, *2+1
        1층: 1
        2층: 2, 3
        3층: 4, 5, 6, 7
        4층: 8, 9, 10, 11, 12, 13, 14, 15 …

        2의 자식은 4,5 → 2*2, 2*2+1
        */
    void update(int node, int l, int r, int idx, long long val) {
        if (l == r) { tree[node] = val; return; } // a[idx]=val (set)
        int mid = (l + r) / 2;
        if (idx <= mid) update(node*2, l, mid, idx, val);
        else update(node*2+1, mid+1, r, idx, val);
        tree[node] = tree[node*2] + tree[node*2+1];
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;          // 합의 항등원
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return query(node*2, l, mid, ql, qr) + query(node*2+1, mid+1, r, ql, qr);
    }
};

int main() {
    cin >> n >> m >> k;
    SegTree st(n);
    long long arr[1000001];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    st.build(arr, 1, 1, n);

    for (int i = 0; i < m+k; i++) {
        long long opt, first, second;
        cin >> opt >> first >> second;
        if (opt == 1) {
            arr[first] = second;
            st.update(1,1,n,first,second);
        } else {
            cout << st.query(1, 1, n, first, second) << "\n";

        }
    }
    return 0;
}