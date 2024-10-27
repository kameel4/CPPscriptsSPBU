#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <chrono>
using namespace std;
using namespace chrono;

void insertion_sort(vector<int>& A){
    for(int i = 1; i < A.size(); i++){
        int key = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}


vector <int> random_vector(int N){
    mt19937 mt(time(nullptr));
    vector <int> listick;
    for (int i =0; i<N; i++){listick.push_back(mt()%1000);}
    return listick;
 }

vector<int> merge_two_vecs(vector<int> sub_array1, vector<int> sub_array2){
    vector<int> A(sub_array1.size() + sub_array2.size());
    sub_array1.push_back(pow(10, 9));
    sub_array2.push_back(pow(10, 9));
    int i = 0, j = 0;
    for (int k = 0; k < (sub_array1.size()+sub_array2.size())-2; k++)
    {
        if (sub_array1[i] < sub_array2[j]){
            A[k] = sub_array1[i];
            i++;
        }
        else{
            A[k] = sub_array2[j];
            j++;
        }
    }
    return A;
}

vector<int> multiple_merge(vector<vector<int>>& vecs){
    int k = vecs.size();
    int n = vecs[0].size();
    while (k>1){
        int index = 0;
        for (int i =0; i<k; i+=2){
            vector<int> left = vecs[i];
            vector<int> right = i + 1 < k ? vecs[i + 1] : vector<int>(0);
            vecs[index++] = merge_two_vecs(left, right);
        }
        k = (k + 1) / 2;
    }
    return vecs[0];
}

void merge_insertion_sort(vector<int>& A, int m){
    int n = A.size();
    vector<vector<int>> m_sized_vecs;
    for (int i = 0; i<(n/m); i++){
        vector<int> m_vec(begin(A)+i*m, begin(A)+(i+1)*m);
        insertion_sort(m_vec);
        m_sized_vecs.push_back(m_vec);
    }
    if(n%m != 0){
        vector<int> last_vec(begin(A)+(n/m) *m, end(A));
        insertion_sort(last_vec);
        m_sized_vecs.push_back(last_vec);
    }
    A = multiple_merge(m_sized_vecs);
}

// void merge(vector<int>& A, int p, int q, int r){
//     int n1 = q - p + 1;
//     int n2 = r - q;
//     vector<int> sub_array1(begin(A)+p, begin(A)+p+n1);
//     vector<int> sub_array2(begin(A)+p+n1, begin(A)+p+n1+n2);
//     sub_array1.push_back(pow(10, 9));
//     sub_array2.push_back(pow(10, 9));
//     int i = 0, j = 0;
//     for (int k = p; k<r+1; k++){
//         if (sub_array1[i] < sub_array2[j]){
//             A[k] = sub_array1[i++];
//         }
//         else{
//             A[k] = sub_array2[j++];
//         }
//     }
// }

// void merge_sort(vector<int>& A, int p, int r){
//     if (p<r){
//         int q = (p + r) / 2;
//         merge_sort(A, p, q);
//         merge_sort(A, q+1, r);
//         merge(A, p, q, r);
//     }
// }

 double compare_time(vector<int> unsorted,int m){
    //Замер времени модифицированной сортировки
    vector<int> rVector1 = unsorted;
    vector<int> rVector2 = unsorted;
    int N = unsorted.size();
    auto start = steady_clock :: now ();
    merge_insertion_sort(rVector1, m);
    auto end = steady_clock :: now ();
    duration <double > elapsed_seconds = end - start ;
    cout << " m = "<<m<<"\n";
    cout << " elapsed time for insertion-modified sort with "<< N <<" elements: "<< elapsed_seconds.count () << "s\n";
    return elapsed_seconds.count();

    // //Замер времени стандартной сортировки
    // auto start2 = steady_clock :: now ();
    // merge_sort(rVector2, 0, rVector2.size()-1);
    // auto end2 = steady_clock :: now ();
    // duration <double > elapsed_seconds2 = end2 - start2;
    // cout << " elapsed time for standart merge sort with "<< N <<" elements: "<< elapsed_seconds2.count () << "s\n";
    // cout << " time differnce is "<<elapsed_seconds2.count() - elapsed_seconds.count()<<"s\n\n";
    // return fabs(elapsed_seconds2.count() - elapsed_seconds.count());
 }

int main(){
    double min = 100.0;
    int last_m = 0;
    vector<int> vector_to_sort_10_3 = random_vector(pow(10, 3));
    vector<int> vector_to_sort_10_4 = random_vector(pow(10, 4));
    vector<int> vector_to_sort_10_5 = random_vector(pow(10, 5));
    vector<int> vector_to_sort_10_6 = random_vector(pow(10, 6));
    vector<int> vector_to_sort_10_7 = random_vector(pow(10, 7));
    for (int m = 90; m<400; m++){
        double dif = compare_time(vector_to_sort_10_5, m);
        if (dif<min){min = dif; last_m = m;}
    }
    cout<<"minimal time is "<<min<<" with m = "<<last_m;
}






