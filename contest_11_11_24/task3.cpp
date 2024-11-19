#include <vector>
#include <algorithm>
#include <iostream> 
using namespace std;

int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<int> a(n);
        vector<int> subarray(10001);
        a.reserve(n*2), subarray.reserve(n*2);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
            subarray[a[j]]++;
        }
        int count = 0, without_pair = 0;
        for (int j = 0; j < 10001; j++) {
            if (subarray[j] %2 !=0) {
                count++;
            } else if (subarray[j] > 0) {
                count++;
                without_pair++;
            }
        }
        cout << count - without_pair%2 << endl;
    }
}
        
