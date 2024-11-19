#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
// SET используется только для генерации вектора уникальных элементов!!!!!!!!!!!!!!
#include <set>
// SET используется только для генерации вектора уникальных элементов!!!!!!!!!!!!!!

using namespace std;

void merge_sort(vector<int>& A, int p, int r, int S, int& pairs);
void merge(vector<int>& A, int p, int q, int r, int S, int& pairs);

vector<int> generate_vector(int N, int min, int max);



int main(){
    int S = 7777, pairs = 0;
    vector<int> vec = generate_vector(10000, -20000, 20000);
    for (int i = 0; i<vec.size()-1; i++){
        for(int j = i+1; j<vec.size(); j++){
            if (vec[i] + vec[j] == S){
                // cout<<vec[i]<<"   "<<vec[j]<<'\n';
                pairs++;
            }
        }
    }
    cout<<"dumb pairs  "<<pairs<<"\n\n";
    pairs = 0;
    merge_sort(vec, 0, vec.size()-1, S, pairs);
    // for (int elem: vec){
    //     cout<<elem<<" ";
    // }
    cout<<"Количество подходящих пар: "<<pairs<<endl;

    for (int elem: generate_vector(10, -5, 0)){
        cout<<elem<<' ';
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

void merge(vector<int>& A, int p, int q, int r, int S, int& pairs){
    int n1 = q - p +1;
    int n2 = r - q;
    vector<int> L(n1), R(n2);
    // filling the L and R vectors
    for (int i =0; i< n1; i++){
            L[i] = A[p+i];
    }
    for (int j =0; j< n2; j++){
            R[j] = A[q+j+1];
    }
    // printing the vectors
    // cout<<"sub_array1(left): ";
    // for (int elem: L){cout<<elem<<' ';}
    // cout<<"\nsub_array2(right): ";
    // for (int elem: R){cout<<elem<<" ";}
    // cout<<"\n\n";
    // signal elements
    L.push_back(pow(10, 9));
    R.push_back(pow(10, 9));
    // counting pairs that sum to S
    int i = 0, j = n2 - 1;
    while (i < n1 && j >= 0) {
        if (L[i] + R[j] == S) {
            // cout<<"Пара!  "<<L[i]<<" "<<R[j]<<"\n";
            pairs++;
            i++;
            j--;
        } else if (L[i] + R[j] < S) {
            i++;
        } else {
            j--;
        }
    }
    // слияние
    i =0; j=0;
    for (int k = p; k<r+1; k++){
        if (L[i]< R[j]){
            A[k] = L[i++];
        }else{
            A[k] = R[j++];
            }
        }
    }


vector<int> generate_vector(int N, int min, int max){
    vector<int> result;
    if (N == 0 || min >= max || max-min < N) return result;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(min, max);
    set<int> s;
    while (s.size() < N) {
        int num = dis(gen);
        s.insert(num);
    }
    for (int num: s) result.push_back(num);
    return result;
}

