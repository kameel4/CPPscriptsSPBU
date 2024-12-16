#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int round = 0;
        int square = 0;
        int curly = 0;
        string to_close_stack;
        for (char c: s){
            int i = to_close_stack.size();
            if (min({round, square, curly}) <0){
                return false;
            }
            if (c == '('){round++; to_close_stack+=c;}
            if (c == ')'){round--;
                if (i!=0)
                    if ( to_close_stack[i-1] != '('){return false;}
                    else {to_close_stack.pop_back();} }


            if (c == '['){square++; to_close_stack += '[';}
            if (c == ']'){square--;
                if (i!=0)
                    if ( to_close_stack[i-1] != '['){return false;}
                    else {to_close_stack.pop_back();} }


            if (c == '{'){curly++; to_close_stack += '{';}
            if (c == '}'){curly--;
                if (i!=0)
                    if ( to_close_stack[i-1]!= '{'){return false;}
                    else {to_close_stack.pop_back(); } }
        }
        if (max({round, square, curly}) == 0 && min({round, square, curly}) == 0){
            return true;
        }
        return false;
    }
};

