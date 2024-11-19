#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;   

int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        sort(a.begin(), a.end());
        int res = (a[n - 1] - a[0]) + (a[n - 2] - a[1]);
        cout << res << endl;
    }
    return 0;
}