#include <cmath>
#include <vector>
#include <random>
#include <ctime>
#include <iostream>
using namespace std;


int main(){
    int N, K, Q, l, r;
    N = 5;
    K = pow(10, 1);
    Q = 5;
    vector<int> arr(K);
    mt19937 mt(time(nullptr));
    for (int i = 0; i < N; i++)
    {
        int t = mt()%K;
        arr[t]++;
        cout<<t<<" ";
    }
    cout<<"\n";
    for (int i = 1; i < K; i++)
    {
        arr[i]+=arr[i-1];
    }
    for(int i:arr){cout<<i<<" ";}
    cout<<"\n";
    
    for (int i = 0; i < Q; i++)
    {
        cout<<"Введите начало и конец отрезка: \n";
        cin>>l>>r;
        int checkL=l-1;

        if(checkL<0){checkL=0;}
        if(checkL>K-2){cout<<"Чисел на отрезке: 0\n"; continue;}
        if(r<1){cout<<"Чисел на отрезке: 0\n"; continue;}
        if(r>K-1){r=K-1;}
        cout<<"Чисел на отрезке: \n"<<arr[r]-arr[checkL]<<"\n";

    }
}
