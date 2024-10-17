#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
    int n, l;
    long double light;
    cin>>n>>l;
    vector<long double> lights;
    for(int i =0; i<n; i++){
        cin>>light;
        lights.push_back(light);
    }
    sort(begin(lights), end(lights));
    long double max_dif=-1.0;
    for (int i = 1; i<lights.size(); i++){
        if(lights[i]-lights[i-1] > max_dif){max_dif = lights[i]-lights[i-1];};
    }   
    long double distance = max_dif/2.0;
    vector<long double> res = {distance, lights[0]-0, l-lights[lights.size()-1]};
    long double ans = *max_element(begin(res), end(res));
    cout<<fixed<<setprecision(7)<<ans;
}




