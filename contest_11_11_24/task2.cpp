#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int count_zeros(vector<int>& a, int index) {
    int zeros = 0;
    for (int i = index+1; i < a.size()-1; i++) {
        if (a[i] == 0) zeros++;
        else break;
    }
    return zeros;
}

int main() {
    int n, t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
    }
    int sum = 0;
    for (int m = 0; m < n-1; m++) {
        sum += a[m];
        if (a[m] !=0) sum+= count_zeros(a, m);
    }
    cout<<sum<<"\n";
}
}



