#include <random>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void shell_sort (vector <int >& a) {
    int n = a.size();
    vector <int> three_smooth_intervals;
    for (int p = 1; p < n/3; p*=2){
        for (int q = p; q < n/3; q*=3){
            three_smooth_intervals.push_back(q);
        }
    }
    // Разворот массива интервалов 3-гладкой послед-ей, чтобы интервал изменялся от возможно большого до 1
    reverse(three_smooth_intervals.begin(), three_smooth_intervals.end());
    for (int h: three_smooth_intervals) {
        for( int i = h; i < n; ++i) {
            int temp = a[i];
            int j = i;
            for (; j >= h && a[j - h] > temp ; j -= h)
                a[j] = a[j - h];
            a[j] = temp ;
        }
    }
 }



int main(){
    int N = pow(10, 6);
    mt19937 mt(time(nullptr));
    vector <int> listick;

    for (int i =0; i<N; i++){listick.push_back(mt()%1000);}
    vector <int>listick_compare = listick;

    //Замер времени сортировки Шелла на гладкой п.
    auto start = steady_clock :: now ();
    shell_sort(listick);
    auto end = steady_clock :: now ();
    duration <double > elapsed_seconds = end - start ;
    cout << " elapsed time for shell sort: " << elapsed_seconds . count () << "s\n";

    //Замер времени стандартной сортировки
    auto start2 = steady_clock :: now ();
    sort(listick_compare.begin(), listick_compare.end());
    auto end2 = steady_clock :: now ();
    duration <double > elapsed_seconds2 = end2 - start2;
    cout << " elapsed time for quick sort: " << elapsed_seconds2.count () << "s\n";
}