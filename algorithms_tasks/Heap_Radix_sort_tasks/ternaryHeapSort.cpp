#include <algorithm>
#include <chrono>
#include <cmath>
#include <vector>
#include <random>
#include <iostream>
using namespace std;
using namespace chrono;


void ternary_heapify(vector<int>& arr, int n, int node_index);
void ternary_heapSort(vector<int>& arr);

void compare_time(vector<int> unsorted);
vector <int> random_vector(int N);
void check_sort();



int main(){
   check_sort();

   for (int n = 10e2; n<10e7; n*=10){
      vector<int> compraison_array = random_vector(n);

      compare_time(compraison_array);
   }
}

void ternary_heapify(vector<int>& arr, int n, int node_index){
   int largest = node_index;

   int left_child = 3 * node_index + 1;
   int mid_child = 3  * node_index + 2;
   int right_child = 3 * node_index + 3;

   if (left_child < n && arr[left_child] > arr[largest])
      largest = left_child;

   if (mid_child < n && arr[mid_child] > arr[largest])
      largest = mid_child;
   
   if (right_child < n && arr[right_child] > arr[largest])
      largest = right_child;
   
   if (largest != node_index) {
      swap(arr[node_index], arr[largest]);
      ternary_heapify(arr, n, largest);
   }
}

void ternary_heapSort(vector<int>& arr){
   int n = arr.size();

   for (int i = n / 3 - 1; i >= 0; i--)
      ternary_heapify(arr, n, i);

   for (int i = n - 1; i > 0; i--) {
      swap(arr[0], arr[i]);
      ternary_heapify(arr, i, 0);
   }
}



void compare_time(vector<int> unsorted){
   //Замер времени модифицированной сортировки
   vector<int> rVector1 = unsorted;
   vector<int> rVector2 = unsorted;
   int N = log10(unsorted.size());
   // rVector1.reserve(rVector1.size()*2);

   auto start1 = steady_clock :: now ();
   ternary_heapSort(rVector1);
   auto end1 = steady_clock :: now ();
   duration <double> elapsed_seconds1 = end1 - start1;



   auto start2 = steady_clock :: now ();
   sort(begin(rVector2), end(rVector2));
   auto end2 = steady_clock :: now ();
   duration <double> elapsed_seconds2 = end2 - start2;

   cout<<"Elapsed time for Ternary Heap Sort with 10e"<<N<<" elements: "<<elapsed_seconds1.count()<<endl;
   cout<<"Elapsed time for standart Sort with 10e"<<N<<" elements: "<<elapsed_seconds2.count()<<endl<<endl;
}

vector <int> random_vector(int N){
   mt19937 mt(time(nullptr));
   vector <int> listick;
   for (int i =0; i<N; i++){listick.push_back(mt());}
   return listick;
 }

 void check_sort(){
    vector<int> v = random_vector(10000);
    vector<int> v1 = v;
    ternary_heapSort(v);
    sort(v1.begin(), v1.end());
    if (v == v1)
        {cout<<"sort is ok  ˙ᵕ˙\n";}
    else 
        {cout<<"sort is not ok   • ᴖ • \n";};
}