#include <iostream>
#include <deque>
using namespace std;

int main() {
    string n;
    cin >> n;

    deque<char> q;
    q.push_back(n[0]);

    for (int i = 1; i < n.size(); i++) {
        if (n[i] < q.front()) {
            q.push_front(n[i]);
        } else {
            q.push_back(n[i]);
        }
    }
    for (int i = 0; i < n.size();i++ ) {
        cout << q[i];
    }

}