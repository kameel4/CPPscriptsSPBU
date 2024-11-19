#include <iostream>

using namespace std;

int main() {
    int n, k;
    double time_rest;
    cin >> n >> k;
    time_rest = 240 - k;
    double required_time;
    int result = -1;
    for (int i = 1; i < n+1; i++) {
        required_time = (i*i) + i;
        if (required_time > (time_rest * 0.4)) {
            result = i-1;
            break;
        }else if (required_time == (time_rest * 0.4)) {
            result = i;
            break;
        }
    }
    if (result == 0) {
        cout << 0 << endl;
    }else if (result == -1){
        cout << n << endl;}
    else {
        cout << result << endl;
    }
}
