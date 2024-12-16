#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result = {0, 0};
        vector<int> copy_to_work = nums;
        sort(copy_to_work.begin(), copy_to_work.end());
        int left = 0, right = nums.size() - 1;
        while(left<right){
            int a = copy_to_work[left], b = copy_to_work[right];
            if (a + b == target){
                size_t it1;
                size_t it2;
                it1 = find(begin(nums), end(nums), a) - nums.begin();
                nums.erase(nums.begin() + it1);
                it2 = find(begin(nums), end(nums), b) - nums.begin();
                if (it1 < it2){it2++;}
                result = {(int)it1, (int)it2};
                break;
            }else if (a + b < target){
                left++;
            }else{
                right--;
            }
        }
        return result;
    }
};
