#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int len = strs.size();
        if( len==0 )
            return "";
        
        string ans = strs[0];
        
        for(int i=1; i<len; i++){
            while(strs[i].find(ans,0)!=0){ //这里面直接用了一个 内置函数，find
                ans = ans.substr(0,ans.size()-1);
                if(ans == "")
                    return "";
            }
        }

        return ans;


    }
};