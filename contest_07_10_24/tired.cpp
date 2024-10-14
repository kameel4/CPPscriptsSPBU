#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

vector<int> fromLinearToMatrixIndex(int lIndex, vector<int> prefixSvec){
    vector<int> matrixIndex;
    for (int i =1; i<prefixSvec.size(); i++){
        if(lIndex+1<=prefixSvec[i]){
            matrixIndex.push_back(i-1);
            matrixIndex.push_back(lIndex-prefixSvec[i-1]);
            return matrixIndex;
        }
    }
}

int main(){
    int n, string_lenght, cell, linear_index;
    cin>>n;
    vector<int> strings_lenght(1), linear_vec, temp, prefixSlenght(n+1), matrix_index1, matrix_index2;
    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++)
    {   
        cin>>string_lenght;
        strings_lenght.push_back(string_lenght);
        prefixSlenght[i+1] = prefixSlenght[i] + string_lenght;
    }
    vector<vector<int>> changes;
    for(int i=1; i<strings_lenght.size(); i++){
        for (int j=0; j<strings_lenght[i]; j++){
            cin>>cell;
            temp.push_back(cell);linear_vec.push_back(cell);
        }
        matrix.push_back(temp);
        temp.clear();
    }
    for (int i = 0; i < accumulate(begin(strings_lenght), end(strings_lenght), 0); i++){
        linear_index = find(begin(linear_vec), end(linear_vec), i+1)-linear_vec.begin();
        if (linear_index!=i){
        matrix_index1 = fromLinearToMatrixIndex(linear_index, prefixSlenght);
        matrix_index2 = fromLinearToMatrixIndex(i, prefixSlenght);
        matrix_index1.insert(end(matrix_index1), begin(matrix_index2), end(matrix_index2));
        changes.push_back(matrix_index1);
        swap(linear_vec[linear_index], linear_vec[i]);}
        }
    
cout<<changes.size()<<'\n';

    for (int i = 0; i < changes.size(); i++)
    {
        cout<<++changes[i][0]<<' '<<++changes[i][1]<<' '<<++changes[i][2]<<' '<<++changes[i][3];
        cout<<"\n";
    }
    
    
    
    
}