#include <iostream>
#include <queue>
using namespace std;

int bfs();

int a, b, n, m;
int visited[100001]={};
int direct[6];
int main() {
    cin >> a >> b >> n >> m;
    direct[0] = a;
    direct[1] = b;
    direct[2] = 1;
    visited[n] = 1;

    if (n == m) cout << 0;
    else cout << bfs();
}

struct Node {
    int pos;
    int ans;
};

int bfs() {
    queue<Node> q;
    q.push({n, 0});
    while (!q.empty()) {
        Node cur = q.front();
        q.pop();
        for (int i = 0; i < 3; i++) {
            int newPos1 = cur.pos + direct[i];
            int newPos2 = cur.pos - direct[i];
            int newPos3 = cur.pos * direct[i];
            int ans = cur.ans + 1;
            if (0 <= newPos1 && newPos1 <= 100000 && visited[newPos1] == 0) {
                visited[newPos1] = 1;
                if (m == newPos1) return ans;
                else q.push({newPos1, ans});

            }
            if (0 <= newPos2 && newPos2 <= 100000 && visited[newPos2] == 0) {
                visited[newPos2] = 1;
                if (m == newPos2) return ans;
                else q.push({newPos2, ans});
            }
            if (0 <= newPos3 && newPos3 <= 100000 && visited[newPos3] == 0) {
                visited[newPos3] = 1;
                if (m == newPos3) return ans;
                else q.push({newPos3, ans});
            }
        }

    }
}
