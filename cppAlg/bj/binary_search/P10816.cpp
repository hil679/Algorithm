#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    int arr[20000001]={};
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr[a+10000000]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        cout << arr[a+10000000] << " ";
    }
    return 0;
}