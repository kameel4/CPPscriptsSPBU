#include <chrono>
#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <iostream>

using namespace std;
using namespace chrono;

void quick_sort(vector<int>& A, int p, int r);
// int partition(vector<int>& A, int p, int r);
void check_sort();
vector<int> random_vector(int N);
void compare_time(vector<int> unsorted);


int main(){
    check_sort();

    for (int n = 10000000; n<100000000; n+=10000000){
        compare_time( random_vector(n) );
    }
}


void quick_sort(vector<int>& A, int p, int r) {
    // cout<<"Partition!\n";
    if (p < r) {
        srand(time(0));
        int i = p + rand() % (r - p + 1);
        swap(A[i], A[r]);
        int x = A[r];
        int lower = p; 
        int greater = r; 
        int eq = p; 

        while (eq <= greater) {
            if (A[eq] < x) {
                swap(A[lower], A[eq]);
                lower++;
                eq++;
            } else if (A[eq] > x) {
                swap(A[eq], A[greater]);
                greater--;
            } else {
                eq++;
            }
        }

        // Check if subarray's numbers are equal to each other
        bool all_equal = true;
        for (int i = p; i <= lower - 1; i++) {
            if (A[i] != A[p]) {
                all_equal = false;
                break;
            }
        }
        if (!all_equal) {
            quick_sort(A, p, lower - 1);
        }

        all_equal = true;
        for (int i = greater + 1; i <= r; i++) {
            if (A[i] != A[greater + 1]) {
                all_equal = false;
                break;
            }
        }
        if (!all_equal) {
            quick_sort(A, greater + 1, r);
        }
    }
}


void check_sort(){
    vector<int> v = random_vector(1000000);
    vector<int> v1 = v;
    quick_sort(v, 0, v.size()-1);
    sort(v1.begin(), v1.end());
    if (v == v1)
        {cout<<"sort is ok  ˙ᵕ˙\n";}
    else 
        {cout<<"sort is not ok   • ᴖ • \n";};
}


vector <int> random_vector(int N){
   mt19937 mt(time(nullptr));
   vector <int> listick;
   for (int i =0; i<N; i++){listick.push_back(mt()%1000000);}
   return listick;
 }


void compare_time(vector<int> unsorted){
   //Замер времени модифицированной сортировки
   vector<int> rVector1 = unsorted;
   vector<int> rVector2 = unsorted;
   int N = unsorted.size();
   // rVector1.reserve(rVector1.size()*2);

   auto start1 = steady_clock :: now ();
   quick_sort(rVector1, 0, rVector1.size()-1);
   auto end1 = steady_clock :: now ();
   duration <double> elapsed_seconds1 = end1 - start1;



   auto start2 = steady_clock :: now ();
   sort(begin(rVector2), end(rVector2));
   auto end2 = steady_clock :: now ();
   duration <double> elapsed_seconds2 = end2 - start2;

   cout<<"Elapsed time for quick Sort with "<<N/1000000.0<<" млн elements: "<<elapsed_seconds1.count()<<endl;
   cout<<"Elapsed time for standart Sort with "<<N/1000000.0<<" млн elements: "<<elapsed_seconds2.count()<<endl<<endl;
}

// int partition(vector<int>& A, int p, int r){
//     cout<<"partition!\n";
//     int x = A[r];
//     int i = p - 1;
//     for (int j = p; j < r; j++)
//         if (A[j] <= x)
//             swap(A[++i], A[j]);
//     swap(A[i+1], A[r]);
//     return i+1;
// }
