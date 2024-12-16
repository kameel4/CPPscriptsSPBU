#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

pair<int, int> divided(int a){
    if (a % 4 == 0){
        return {a / 2, a / 2};
    }
    else if (a % 2 == 0){
        return {a / 2 + 1, a / 2-1};
    }else{
        return {a / 2 + 2, a / 2-1};
    }
}

void insertion_sort_reverse(vector<int>& nums, int begin, int end);

class Solution {
public:
    int minimumSize(vector<int>& nums, int& maxOperations) {
        sort(rbegin(nums), rend(nums));
        while(maxOperations > 0){
            pair<int, int> result = divided(nums[0]);
            nums[0] = result.second;
            nums.insert(begin(nums), result.first);
            insertion_sort_reverse(nums, 0, nums.size());
            maxOperations--;
        }
        return nums[0];
    }
};

int main(){
    vector<int> test = {431,922,158,60,192,14,788,146,788,775,772,792,68,143,376,375,877,516,595,82,56,704,160,403,713,504,67,332,26};
    Solution sol;
    int maxOperations = 80;
    cout<<sol.minimumSize(test, maxOperations);
}

void insertion_sort_reverse(vector<int>& nums, int begin, int end){
    for (int i = begin + 1; i < end; i++){
        int j = i;
        while (j > begin && nums[j - 1] < nums[j]){
            swap(nums[j], nums[j - 1]);
            j--;
        }
    }
}
