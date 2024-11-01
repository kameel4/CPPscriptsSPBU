#include "sort_methods.hpp"


void sortings::mergeSort(std::vector<int>& A, int p, int r){
    if (p<r){
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q+1, r);
        merge(A, p, q, r);
    }
}

void sortings::merge(std::vector<int>& A, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    std::vector<int> sub_array1(begin(A)+p, begin(A)+p+n1);
    std::vector<int> sub_array2(begin(A)+p+n1, begin(A)+p+n1+n2);
    // cout<<"sub_array1(left): ";
    // for (int elem: sub_array1){cout<<elem<<' ';}
    // cout<<"\nsub_array2(right): ";
    // for (int elem: sub_array2){cout<<elem<<" ";}
    // cout<<"\n";
    sub_array1.push_back(pow(10, 9));
    sub_array2.push_back(pow(10, 9));
    int i = 0, j = 0;
    for (int k = p; k<r+1; k++){
        if (sub_array1[i] < sub_array2[j]){
            A[k] = sub_array1[i++];
        }
        else{
            A[k] = sub_array2[j++];
        }
    }
}

void sortings::insertionSort(std::vector<int> &array_to_sort, int begin, int end){
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

void sortings::merge_sort_insertionMOD(std::vector<int>& A, int p, int r, int m){
    if (p<r && r-p > m){
        int q = (p + r) / 2;
        merge_sort_insertionMOD(A, p, q, m);
        merge_sort_insertionMOD(A, q+1, r, m);
        merge(A, p, q, r);
    }else{
        // Если рекурсия дошла до подмассива длины <= m, то сортируем его по вставке
        insertionSort(A, p, r);
    }
}