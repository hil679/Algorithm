#include <iostream>

using namespace std;

int main() {
    int num, window;
    cin >> num >> window;
    int res[100001];
    int datum[100001];

    int data;
    res[0] = 0;
    datum[0] = 0;
    int max = -10000001;
    for (int i =1; i <= num; i++) {
        cin >> data;
        datum[i] = data;
        if (i < window) {
            res[i] = data+res[i-1];
        } else {
            res[i] = data+res[i-1] - datum[i-window];
            if (max < res[i])
                max = res[i];
        }
        // cout << res[i] << endl;

    }
    cout << max;
}