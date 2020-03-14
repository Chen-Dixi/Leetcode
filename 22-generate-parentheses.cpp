#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
#include <cstring>
using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        search(ans, "",0,0,0,n);
        return ans;
    }

    void search(vector<string>& ans, string cur, int cur_end, int cur_start,int cur_left,int n){
        if(cur_end==n){
            ans.push_back(cur);
            return;
        }

        if(cur_left>0){
            cur.push_back(')');
            search(ans,cur,cur_end+1,cur_start, cur_left-1,n);
            cur.pop_back();//回溯
        }

        if(cur_start<n){
            cur.push_back('(');
            search(ans,cur,cur_end,cur_start+1,cur_left+1,n);
            cur.pop_back();
        }

    }
};

class Solution2 {
public:
    void getAns(string str, int l, int r, vector<string>& ans){
        if(l == 0 && r == 0)
            ans.push_back(str);
        if(l > 0)
            getAns(str + "(", l - 1, r + 1, ans);
        if(r > 0) 
           getAns(str + ")", l, r - 1, ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        getAns("", n, 0, ans);
        return ans;
    }
};


int main(){

    Solution sol = Solution();

    int n=3;

    vector<string> results = sol.generateParenthesis(n);
    for(vector<string>::iterator it=results.begin(); it!=results.end(); it++){
        cout<< *it <<" "<<endl;
    }
}