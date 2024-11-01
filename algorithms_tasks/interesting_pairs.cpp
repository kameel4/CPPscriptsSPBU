#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

void merge(vector<int>& A, int p, int q, int r, int& int_p_vec){
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<int> sub_array1(begin(A)+p, begin(A)+p+n1);
    vector<int> sub_array2(begin(A)+p+n1, begin(A)+p+n1+n2);
    // cout<<"sub_array1(left): ";
    // for (int elem: sub_array1){cout<<elem<<' ';}
    // cout<<"\nsub_array2(right): ";
    // for (int elem: sub_array2){cout<<elem<<" ";}
    // cout<<"\n";
    sub_array1.push_back(pow(10, 9));
    sub_array2.push_back(pow(10, 9));
    int i = 0, j = 0;
    for (int k = p; k<r+1; k++){
        if (sub_array1[i] < sub_array2[j]){
            A[k] = sub_array1[i++];
        }
        else{
            A[k] = sub_array2[j++];
            if (i != sub_array1.size()-1){int_p_vec+=(sub_array1.size()-i-1);}
        }
    }
}

void merge_sort(vector<int>& A, int p, int r, int& count_interesting_pairs){
    if (p<r){
        int q = (p + r) / 2;
        merge_sort(A, p, q, count_interesting_pairs);
        merge_sort(A, q+1, r, count_interesting_pairs);
        merge(A, p, q, r, count_interesting_pairs);
    }
}

int main(){
    vector<int> test = {9, 8, 7, 6, 1};
    int pairs_count = 0;
    merge_sort(test, 0, test.size()-1, pairs_count);
    // for(int elem: test){cout<<elem<<' ';}
    // cout<<"\n";
    cout<<pairs_count;
}