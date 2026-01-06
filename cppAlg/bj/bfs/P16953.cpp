#include <iostream>
#include <queue>
using namespace std;
int a, b;
int bfs();
int main() {
    cin >> a >> b;

    cout << bfs();
}

struct Node {
    int num;
    int depth;
};
int bfs() {
    if (a == b) return 0;
    queue<Node> q;
    q.push({a, 0});
    while (!q.empty()) {
        Node cur = q.top();
        int curnum = cur.num;
        int nextDepth = cur.depth+1;
        q.pop();

        if (curNum*2 == b) return nextDepth;
        else {
            if (curNum * 2 < b) q.push({curNum*2, nextDepth});
        }
        if (curNum*10 + 1 == b) return nextDepth;
        else {
            if (curNum*10+1 < b) q.push({curNum*10+1, nextDepth});
        }
    }
    return -1;
}