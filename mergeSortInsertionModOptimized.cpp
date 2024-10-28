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

void multiple_merge(vector<int>& vec, int m);
void Insert_sort(std::vector<int> &array_to_sort, int m);
void merge_two_vecs(vector<int>& Vec, vector<int> sub_array1, vector<int> sub_array2, int left_b);

int main(){
    double min = 100.0;
    int last_m = 0;
    for (int n = 1e3; n<10e7; n*=10){    
        vector<int> vector_to_sort_10_n = random_vector(n);       
        
        for (int m = 128; m>48; m-=8){
            double dif = compare_time(vector_to_sort_10_n, m);
            if (dif<min){min = dif; last_m = m;}
        }
        cout<<"minimal time is "<<min<<" with m = "<<last_m<< "  and n = 10e"<<log10(n)<<"\n";
        min = 100;
    }
}

void Insert_sort(std::vector<int> &array_to_sort, int m){
    int temp;
    for (int i = 1; i < int(array_to_sort.size()); i+=m){
        for (int j = i; j < i - 1 + m; ++j){
            temp = array_to_sort[j];
            int l;
            for (l = j; l > i - 1 && array_to_sort[l-1] > temp; --l){
                array_to_sort[l] = array_to_sort[l-1];
            }
        array_to_sort[l] = temp;
        }

    }
}

vector <int> random_vector(int N){
    mt19937 mt(time(nullptr));
    vector <int> listick;
    for (int i =0; i<N; i++){listick.push_back(mt()%1000);}
    return listick;
 }

void merge_two_vecs(vector<int>& Vec, vector<int> sub_array1, vector<int> sub_array2, int left_b){
    sub_array1.push_back(pow(10, 9));
    sub_array2.push_back(pow(10, 9));
    int i = 0, j = 0;
    for (int k = left_b; k < left_b + (sub_array1.size()+sub_array2.size())-2; k++)
    {
        if (sub_array1[i] < sub_array2[j]){
            Vec[k] = sub_array1[i];
            i++;
        }
        else{
            Vec[k] = sub_array2[j];
            j++;
        }
    }
}

void multiple_merge(vector<int>& vec, int m){
    int k = vec.size()%m == 0 ? vec.size()/m : vec.size()/m + 1;
    while (k>1){
        int index = 0;
        for (int i =0; i<k; i+=2){
            auto it = begin(vec);
            vector<int> left(it+i*m, it+(i+1)*m);
            vector<int> right;
            if (i + 1 < k){
                int right_b = ((i+2)*m <= vec.size()) ? (i+2)*m : (i+1)*m + (vec.size() - (i+1)*m)%m; 
                vector<int>right(it+(i+1)*m, it + right_b);
                merge_two_vecs(vec,left, right, i*m);
            }
            else {
                vector<int> right(0);
                merge_two_vecs(vec,left, right, i*m);
            }
            // vector<int> right = i + 1 < k ? vecs[i + 1] : vector<int>(0);
        }
        k = (k + 1) / 2;
        m *=2;
    }
}

 double compare_time(vector<int> unsorted,int m){
    //Замер времени модифицированной сортировки
    vector<int> rVector1 = unsorted;
    rVector1.reserve(rVector1.size()*2);
    int N = unsorted.size();

    auto start = steady_clock :: now ();
    Insert_sort(rVector1, m);
    multiple_merge(rVector1, m);
    auto end = steady_clock :: now ();

    duration <double > elapsed_seconds = end - start ;
    //cout << " m = "<<m<<"\n";
    //cout << " elapsed time for insertion-modified sort with "<< N <<" elements: "<< elapsed_seconds.count () << "s\n\n";
    return elapsed_seconds.count();
 }
