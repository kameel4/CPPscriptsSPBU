#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void merge(vector<int>& A, int p, int q, int r, int S, int& pairs){
    int n1 = q - p +1;
    int n2 = r - q;
    vector<int> L(n1), R(n2);
    // filling the L and R vectors
    for (int i =0; i< n1; i++){
        if(A[p+i] < S && !(S%2==0 && A[p+i]==S/2))
            L[i] = A[p+i];
    }
    for (int j =0; j< n2; j++){
        if(A[q+j+1] < S && !(S%2==0 && A[q+j+1]==S/2))
        R[j] = A[q+j+1];
    }
    // printing the vectors
    cout<<"sub_array1(left): ";
    for (int elem: L){cout<<elem<<' ';}
    cout<<"\nsub_array2(right): ";
    for (int elem: R){cout<<elem<<" ";}
    cout<<"\n\n";
    // signal elements
    L.push_back(pow(10, 9));
    R.push_back(pow(10, 9));
    // counting pairs that sum to S
    int i = 0, j = n2 - 1;
    while (i < n1 && j >= 0) {
        if (L[i] + R[j] == S) {
            cout<<"Пара!  "<<L[i]<<" "<<R[j]<<"\n";
            pairs++;
            i++;
            j--;
        } else if (L[i] + R[j] < S) {
            i++;
        } else {
            j--;
        }
    }
    // merging the vectors
    i =0; j=0;
    for (int k = p; k<r+1; k++){
        if (L[i]< R[j]){
            A[k] = L[i++];
        }else{
            A[k] = R[j++];
            }
        }
    }

    

void merge_sort(vector<int>& A, int p, int r, int S, int& pairs){
    if (p<r){
        int q = (p + r) / 2;
        merge_sort(A, p, q, S, pairs);
        merge_sort(A, q+1, r, S, pairs);
        merge(A, p, q, r, S, pairs);
    }
}

int main(){
    int S = 17, pairs = 0;
    vector<int> vec = {1, 40, 3, 2, 7, 9, 10, 20, 11, 12, 6, 8};
    merge_sort(vec, 0, vec.size()-1, S, pairs);
    for (int elem: vec){
        cout<<elem<<" ";
    }
    cout<<"\n\nКоличество подходящих пар: "<<pairs;
}