#include <iostream>
using namespace std;

int main(){
    long long n, m, a;
    cin>>n>>m>>a;
    if (n%a != 0){
        n+= a-(n%a);
    }
    if (m%a != 0){
        m+= a-(m%a);
    }
    long long ans = (n/a)*(m/a);
    cout<<ans;
}