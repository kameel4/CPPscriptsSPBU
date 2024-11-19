#ifndef SORT_METHODS_HPP
#define SORT_METHODS_HPP

#include <vector>
#include <cmath>


namespace sortings{
    void merge_sort(std::vector<int>& array_to_sort, int begin, int end);
    void merge(std::vector<int>& array_to_sort, int begin, int middle, int end);

    void insertion_sort(std::vector<int>& array_to_sort, int begin, int end);
    void merge_sort_insertionMOD(std::vector<int>& array_to_sort, int begin, int end, int m);

    void bubble_sort(int* const arr, const int size);
}

#endif