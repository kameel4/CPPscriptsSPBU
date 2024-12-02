#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <chrono>
using namespace std;
using namespace chrono;

vector <int> random_vector(int N);
double compare_time(vector<int> unsorted,int m);
void Insert_sort(std::vector<int> &array_to_sort, int begin, int end);
void merge(vector<int>& A, int p, int q, int r);
void merge_sort(vector<int>& A, int p, int r, int m);

void check_sort();

int main(){
    double min = 100.0;
    int last_m = 0;
    check_sort();
    for (int n = 1e3; n<10e7; n*=10){    
        vector<int> vector_to_sort_10_n = random_vector(n);       
        
        for (int m = 384; m>48; m-=16){
            double dif = compare_time(vector_to_sort_10_n, m);
            if (dif<min){min = dif; last_m = m;}
        }
        cout<<"minimal time is "<<min<<" with m = "<<last_m<< "  and n = 10e"<<log10(n)<<"\n";
        min = 100;
    }
}

void Insert_sort(std::vector<int> &array_to_sort, int begin, int end){
    for (int i = begin+1; i <= end; i++){
        int j = i;
        int temp = array_to_sort[i];
        while (j > begin && temp < array_to_sort[j-1]){
            array_to_sort[j] = array_to_sort[j-1];
            j--;
        }
        array_to_sort[j] = temp;
    }
}

vector <int> random_vector(int N){
    mt19937 mt(time(nullptr));
    vector <int> listick;
    for (int i =0; i<N; i++){listick.push_back(mt()%1000);}
    return listick;
 }



 double compare_time(vector<int> unsorted,int m){
    //Замер времени модифицированной сортировки
    vector<int> rVector1 = unsorted;
    rVector1.reserve(rVector1.size()*2);
    int N = unsorted.size();

    auto start = steady_clock :: now ();
    merge_sort(rVector1, 0, N-1, m);
    auto end = steady_clock :: now ();

    duration <double > elapsed_seconds = end - start ;
    // cout << " m = "<<m<<"\n";
    // cout << " elapsed time for insertion-modified sort with "<< N <<" elements: "<< elapsed_seconds.count () << "s\n\n";
    return elapsed_seconds.count();
 }



void merge(vector<int>& A, int p, int q, int r){
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
    // merging the vectors
    int i =0, j=0;
    for (int k = p; k<r+1; k++){
        if (L[i]< R[j]){
            A[k] = L[i++];
        }else{
            A[k] = R[j++];
            }
        }
    }



void merge_sort(vector<int>& A, int p, int r, int m){
    if (p<r && r-p > m){
        int q = (p + r) / 2;
        merge_sort(A, p, q, m);
        merge_sort(A, q+1, r, m);
        merge(A, p, q, r);
    }else{
        // Если рекурсия дошла до подмассива длины <= m, то сортируем его по вставке
        Insert_sort(A, p, r);
    }
}

void check_sort(){
    vector<int> v = random_vector(10000);
    vector<int> v1 = v;
    merge_sort(v1, 0, v1.size()-1, 128);
    sort(v.begin(), v.end());
    if (v == v1)
        {cout<<"sort is ok\n";}
    else 
        {cout<<"sort is not ok\n";};
}
