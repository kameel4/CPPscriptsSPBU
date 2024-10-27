#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 1e5 + 5;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ps[n + 1] = {0};
        for (int i = 0; i < n; i++) {
            ps[i + 1] = ps[i] + a[i];
        }
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            if (mp.find(ps[i]) != mp.end()) {
                ans = max(ans, mp[ps[i]]);
            }
            mp[ps[i]] = max(mp[ps[i]], ans + 1);
        }
        cout << ans << endl;
    }
    return 0;
}