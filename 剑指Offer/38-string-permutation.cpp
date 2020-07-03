#include <cstdio>
#include <iostream>
#include <cstring>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> result;
    vector<string> permutation(string s) {
        dfs(s, 0);
        return result;
    }
    void dfs(string& s, int pos) {
        if (pos >= s.size()) {
            result.push_back(s);
            return;
        }
        for (int i = pos; i < s.size(); ++i) {
            if (judge(s, pos, i)) continue;   // 如果pos和i之间有字符等于s[i]，则跳过。
            swap(s[pos], s[i]);
            dfs(s, pos+1);
            swap(s[pos], s[i]);
        }
    }

    bool judge(string& s, int start, int end) {
        for (int i = start; i < end; ++i) {
            if (s[i] == s[end]) return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> ans;
        dfs(s,0,ans);
        return ans;
    }

    void dfs(string& s, int pos, vector<string> &ans)
    {
        if (pos >= s.size()){
            ans.push_back(s);
            return;
        }
        for(int i=pos; i<s.size(); i++){
            if( judge(s, pos, i) ) continue;  // 如果pos和i之间有字符等于s[i]，跳过  //abbc abbc两个组合重复
            swap(s[pos],s[i]);//递归，拿第一个字符和后面的字符逐个交换
            dfs(s,pos+1,ans);
            swap(s[pos],s[i]);//回溯，换回来
        }

    }

    bool judge(string& s,int pos, int i){
        for(int k=pos;k<i;k++){
            if(s[k]==s[i])
                return true;
        }
        return false;
    }
};

class Solution{
public:
    vector<string> permutation(string s){
        vector<string> ans;
        dfs(s,0,ans);
        return ans;
    }

    void dfs(string& s, int pos, vector<string>& ans)
    {
        if(pos >= s.size()){
            ans.push_back(s);
            return;
        }
        for(int i=pos;i<s.size();i++){
            if(!judge(s, pos, i)) continue;//交换第i个字符不行
            swap(s[pos],s[i]);
            dfs(s,pos+1,ans);
            swap(s[pos],s[i]);
        }
    }

    bool judge(string& s, int pos, int end)
    {
        for(int i=pos;i<end;i++)
            if(s[i]==s[end])    return false;//s[end]就是这次尝试要交换的字符，如果前面重复过这个字符，那可定这个分支就会产生相同结果
        return true;
        
    }
};