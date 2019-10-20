#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
using namespace std;
/*
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。
*/
class Solution {
public:
    vector<vector<string> > partition(string s) {
        
        vector<vector<string>> ans;
        if (s.size()==0)
            return ans;

        

        
        return fenzhi(s,0);


    }

    vector<vector<string> > fenzhi(string s, int start){
        vector<vector<string> > ans = {};
        if (start == s.size()){
            return ans;//空
        }

        for(int i=1;i<=s.size()-start;i++){
            //切割后是回文串才考虑
            if (isPalindrome(s.substr(start,i))) {
                string left = s.substr(start,i);
                vector<vector<string> > part = fenzhi(s, start+i);
                for(vector<string> split: part){
                    split.insert(split.begin(),left);
                    ans.push_back(split);
                }
                if(part.size()==0){
                    vector<string> temp = {left};
                    ans.push_back(temp);
                }
            }
        }

        return ans;
    }

private:

    bool isPalindrome(string s){ //判断s是不是回文函数
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if (s[j] != s[i]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};




int main(){
    Solution sol = Solution();
    string str = "aab";
    vector<vector<string> > ans = sol.partition(str);
    //cout<< ans[0]<<endl;
    return 0;
}