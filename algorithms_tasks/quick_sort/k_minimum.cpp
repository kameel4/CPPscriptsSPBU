#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

using namespace std;

int quick_select(vector<int>& arr, int k, int left, int right);
int partition(vector<int>& arr, int left, int right);


vector <int> random_vector(int N){
   mt19937 mt(time(nullptr));
   vector <int> listick;
   for (int i =0; i<N; i++){listick.push_back(mt());}
   return listick;
 }


int main(){
    int k = 10;

    vector<int> arr = random_vector(10e3);

    cout<< quick_select(arr, k, 0, arr.size() - 1) << endl;

    sort(begin(arr), end(arr));

    cout<< arr[k-1];

}


int quick_select(vector<int>& arr, int k, int left, int right) {
    if (left == right) {
        return arr[left];
    }

    int pivot_index = partition(arr, left, right);
    if (k == pivot_index + 1) {
        return arr[pivot_index];
    } else if (k < pivot_index + 1) {
        return quick_select(arr, k, left, pivot_index - 1);
    } else {
        return quick_select(arr, k, pivot_index + 1, right);
    }
}

int partition(vector<int>& arr, int left, int right) {


    int mid = (right+left) / 2;
    swap(arr[mid], arr[right]);
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[right]);
    return i + 1;
}