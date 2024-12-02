#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <random>

using namespace std;
using namespace chrono;

vector<string> random_vector(int N);
string random_string(int length);
void check_sort();
void compare_time(vector<string> unsorted);
int longest(const vector<string>& strings);

void msdSort(vector<string>& a);



int main(){
    check_sort();   
    for(int n = 1000; n<int(pow(10, 6)); n*=10){  
        vector<string> arr = random_vector(n);
        compare_time(arr);
    }
}



void msdSort(vector<string>& a) {
    int n = a.size();
    vector<vector<string>> buckets(26);

    for (int d = longest(a) - 1; d >= 0; d--) {
        for (int i = 0; i < n; i++) {
            if (d < a[i].length()) {
                buckets[a[i][d] - 'a'].push_back(a[i]);
            } else {
                buckets[0].push_back(a[i]);
            }
        }

        int index = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < buckets[i].size(); j++) {
                a[index++] = buckets[i][j];
            }
            buckets[i].clear();
        }
    }
}



string random_string(int length){
    string str = "abcdefghijklmnopqrstuvwxyz";
    random_device rd;
    mt19937 gen(rd());
    shuffle(str.begin(), str.end(), gen);
    return string(str.begin(), str.begin() + length);
}

vector<string> random_vector(int N){
    vector<string> listick(N);
    mt19937 mt(time(nullptr));
    for (int i = 0; i < N; i++){
        listick[i] = random_string(mt()%20+1);
    }

    return listick;
}

 void check_sort(){
    vector<string> v = random_vector(100);
    vector<string> v1 = v;
    msdSort(v);
    sort(v1.begin(), v1.end());
    if (v == v1)
        {cout<<"sort is ok  ˙ᵕ˙\n";}
    else 
        {cout<<"sort is not ok   • ᴖ • \n";};
}

void compare_time(vector<string> unsorted){
   //Замер времени модифицированной сортировки
   vector<string> rVector1 = unsorted;
   vector<string> rVector2 = unsorted;
   int N = log10(unsorted.size());

   // rVector1.reserve(rVector1.size()*2);

   auto start1 = steady_clock :: now ();
   msdSort(rVector1);
   auto end1 = steady_clock :: now ();
   duration <double> elapsed_seconds1 = end1 - start1;



   auto start2 = steady_clock :: now ();
   sort(begin(rVector2), end(rVector2));
   auto end2 = steady_clock :: now ();
   duration <double> elapsed_seconds2 = end2 - start2;

   cout<<"Elapsed time for MSD radix Sort with 10e"<<N<<" elements: "<<elapsed_seconds1.count()<<endl;
   cout<<"Elapsed time for standart Sort with 10e"<<N<<" elements: "<<elapsed_seconds2.count()<<endl<<endl;
}

int longest(const vector<string>& strings) {
    int maxLength = 0;
    for (const auto& str : strings) {
        maxLength = max(maxLength, static_cast<int>(str.length()));
    }
    return maxLength;
}
