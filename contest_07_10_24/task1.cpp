#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void counting_sort(vector<int>& vec, int n){
    int min = *min_element(begin(vec), end(vec)), max = *max_element(begin(vec), end(vec));
    int len = max - min + 1;
    vector<int> sub_vec(len);
    vector<int> result_vec(n+1);
    for (int elem: vec){
        sub_vec[elem-min]++;
    }

    for(int i=1; i < len; i++) 
        sub_vec[i] += sub_vec[i-1]; 
  

    for(int i=n-1; i >= 0; i--) 
    { 
        result_vec[sub_vec[vec[i]-min]-1] = vec[i]; 
        sub_vec[vec[i]-min]--; 
    } 
  
    for(int i=0; i < n; i++) 
        vec[i] = result_vec[i]; 
}

void experiment_sort(vector<int>& vec){
    int min = *min_element(begin(vec), end(vec)), max = *max_element(begin(vec), end(vec));
    vector<int> sub_vec(max-min+1);
    for (int i = 0; i < vec.size(); i++)
    {
        sub_vec[vec[i]-min] = vec[i];
    }
    int i = 0;
    for (int elem: sub_vec){
        if (elem!=0){
            vec[i] = elem;
            i++;
        }
    }
}



int main(){
int n, m, l, r, x;
int elem;
vector<int> vec;
cin>>n;cin>>m;
for (int i=0; i<n; i++){cin>>elem;vec.push_back(elem);}
for (int i=0; i<m; i++){
    cin>>l>>r>>x;
    if(x>r || x<l){cout<<"Yes\n";continue;}
    vector<int>vec_copy (vec.begin()+l-1, vec.begin()+r);
    counting_sort(vec_copy, vec_copy.size());
    if (vec[x-1]==vec_copy[x-l])
        {cout<<"Yes\n";}
    else
        {cout<<"No\n";} 
}

}