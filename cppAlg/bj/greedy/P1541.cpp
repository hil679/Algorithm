#include <iostream>
#include <stack>
using namespace std;
int main() {
    string exp;
    cin >> exp;
    stack<int> numops;
    int num = 0;
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '+') {
             numops.push(num);
             num = 0;
             numops.push(-1);
        }
        else if (exp[i] == '-') {
             numops.push(num);
             num = 0;
             numops.push(-2);
        }
        else {
            num = num * 10 + (exp[i] - '0');
        }
    }
    numops.push(num);
    num = 0;

    while (!numops.empty()) {
        int elem = numops.top();
        numops.pop();
        if (elem == -1) {
            cur += num;
        } else if (elem == -2) {
            cur += num;
            ans -= cur;
            cur = 0;
        } else {
            num = elem;
        }
    }
    cur += num;
    ans += cur;

    cout << ans;
}