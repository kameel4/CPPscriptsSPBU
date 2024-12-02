#include <vector>
#include <iostream>
using namespace std;

void heapify(vector<int>& arr, int n, int node_index){
    int largest = node_index;

    int left_child = 2 * node_index + 1;
    int right_child = 2 * node_index + 2;

    if (left_child < n && arr[left_child] > arr[largest])
        largest = left_child;

    if (right_child < n && arr[right_child] > arr[largest])
        largest = right_child;

    if (largest != node_index) {
        swap(arr[node_index], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr){
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}