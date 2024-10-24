#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void delete_part(vector<vector<int>>& vecvec, int d, int date_type){
    while (vecvec[0][date_type]==d)
    {
        vecvec.erase(begin(vecvec));
        if (vecvec.size()==0){break;}
    }
    
}

int main() {
    vector<vector<int>> exams;
    int n, a, b;
    cin >> n;
    exams.reserve(2*n);
    int max = -1;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        exams.push_back({a, b});
        if (a>max){max = a;}
    }
    sort(rbegin(exams), rend(exams),
        [](vector<int> exam1, vector<int> exam2){ return exam1[0] > exam2[0];
    }) ;
    for (int day = 1; day<max+1; day++){
        if(day==exams[0][1]){delete_part(exams, day, 1);}
        else if(day==exams[0][0]){delete_part(exams, day, 0);}
        if (exams.size()==0){cout<<day;return 0;}
    }
    
}
