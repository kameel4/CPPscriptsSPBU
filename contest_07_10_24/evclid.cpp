#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int linear_present(int a, int b){
    vector<int> qVec(1);
    vector<int>k_j = {1};
    vector<int>k_jm1(1);

    int q;
    if (a<b){swap(a, b);}
    while (a%b!=0)
    {
        q = a%b;
        a = b;
        b = q;
        qVec.push_back(q);
    }
    
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
    linear_present(7038, 8568);

    

    }