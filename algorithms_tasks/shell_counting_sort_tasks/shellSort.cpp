#include <random>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void shell_sort (vector <int >& a, vector<int> intervals) {
    int n = a.size();
    for (int h: intervals) {
        for( int i = h; i < n; ++i) {
            int temp = a[i];
            int j = i;
            for (; j >= h && a[j - h] > temp ; j -= h)
                a[j] = a[j - h];
            a[j] = temp ;
        }
    }
 }
 vector<int> calculate_3smooth_intervals(int N){
    vector <int> three_smooth_intervals;
    for (int p = 1; p < N/3; p*=2){
        for (int q = p; q < N/3; q*=3){
            three_smooth_intervals.push_back(q);
        }
    }
    // Разворот массива интервалов 3-гладкой послед-ей, чтобы интервал изменялся от возможно большого до 1
    sort(three_smooth_intervals.rbegin(), three_smooth_intervals.rend());
    return three_smooth_intervals;
 }

 vector <int> random_vector(int N){
    mt19937 mt(time(nullptr));
    vector <int> listick;
    for (int i =0; i<N; i++){listick.push_back(mt()%1000);}
    return listick;
 }

 void compare_time(int N){
    //Замер времени сортировки Шелла на гладкой п.
    vector <int> intervals1 = calculate_3smooth_intervals(N);
    vector<int> rVector1 = random_vector(N);
    vector<int> rVector2 = rVector1;
    auto start = steady_clock :: now ();
    shell_sort(rVector1, intervals1);
    auto end = steady_clock :: now ();
    duration <double > elapsed_seconds = end - start ;
    cout << " elapsed time for shell sort with "<< N <<" elements: "<< elapsed_seconds.count () << "s\n";
    

    //Замер времени стандартной сортировки
    auto start2 = steady_clock :: now ();
    sort(rVector2.begin(), rVector2.end());
    auto end2 = steady_clock :: now ();
    duration <double > elapsed_seconds2 = end2 - start2;
    cout << " elapsed time for quick sort with "<< N <<" elements: "<< elapsed_seconds2.count () << "s\n\n";
 }


int main(){

    compare_time(pow(10, 3));
    compare_time(pow(10, 4));
    compare_time(pow(10, 5));
    compare_time(pow(10, 6));
}