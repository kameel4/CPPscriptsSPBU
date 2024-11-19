#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> subarray(n+1);
        bool flag = false;
        for (int j = 0; j < n; j++) {
            cin >> a[j];
            subarray[a[j]]++;
        }
        for (int j = 0; j < n; j++) {
            if (subarray[a[j]] >2) {
                cout << a[j] << endl;
                flag = true;
                break;
            }
    }
    if ( not flag) {
        cout << -1 << endl;
        flag = false;
    }
    }
}