#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int shortest = 200;
        string prefix = "";
        for (string str: strs){
            if (str.size()< shortest){shortest = str.size();}
        }
        for (int i = 0; i<shortest; i++){
            prefix += strs[0][i];
            for (int j = 1; j<strs.size(); j++){
                if (strs[j][i] != prefix[i]){
                    prefix.pop_back();
                    return prefix;
                }
            }
        }
        return prefix;
    }
};