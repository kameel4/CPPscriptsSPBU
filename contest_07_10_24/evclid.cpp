#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void linear_present(int a, int b){
    vector<int> qVec(1);
    int q;
    int q1;
    if (a<b){swap(a, b);}
    while (a%b!=0)
    {
        q = a/b;
        q1 = a%b;
        a = b;
        b = q1;
        qVec.push_back(q);
    }
    vector<int>k_j(qVec.size()+1);k_j[0]=1; k_j[1] = qVec[1];
    vector<int>k_jm1(qVec.size()+1);k_jm1[0] = 0;k_jm1[1]= 1;k_jm1[2]= qVec[2];
    for (int j =2; j<qVec.size()+1; j++){
        k_j[j] = qVec[j]*k_j[j-1]+k_j[j-2];
        if (j>2){
            k_jm1[j] = qVec[j]*k_jm1[j-1]+k_jm1[j-2];
        }
    }
    cout<<"qVec: ";
    for(int i = 0; i<qVec.size(); i++){cout<<qVec[i]<<' ';}
    cout<<"\n";

    cout<<"k_j: ";
    for(int i = 0; i<k_j.size(); i++){cout<<k_j[i]<<' ';}
    cout<<"\n";

    cout<<"k_j-1: ";
    for(int i = 0; i<k_jm1.size(); i++){cout<<k_jm1[i]<<' ';}
    cout<<"\n";
}

int nod(int a, int b){
    int q;
    if (a<b){swap(a, b);}
    while (a%b!=0)
    {
        q = a%b;
        a = b;
        b = q;
    }
    return b;
    
}

int nodVec(vector<int>& nums){
    vector<int> nods;
    vector<int> copy = nums;
    while (copy.size()!=1)
    {
        for (int i=1; i<copy.size(); i++){
            nods.push_back(nod(copy[0], copy[i]));
        }
        copy = nods;
        nods.clear();
    }
    return copy[0];
    
}


int main(){
    linear_present(7497, 4473);

    

    }