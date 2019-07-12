/*
76.最小覆盖子串
给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：

如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size()==0 || t.size()==0)
            return "";
        
        unordered_map<char,int> dict;
        for (int i = 0; i < t.size(); ++i)
        {
            if(dict.find(t[i])==dict.end())
                dict[t[i]]=1;
            else
                dict[t[i]]++;
        }

        int required = dict.size();
        //满足条件的最小的窗口和 l r 指针
        int ans[3]={-1,0,0};
        int l=0,r=0;
        /*
    formed 用于跟踪当前窗口中以其所需频率存在多少个唯一字符。
    例如 如果t是“AABC”那么窗口必须有两个A，一个B和一个C.
    因此，当满足所有这些条件时，formed = 3。
    */
        int formed=0;
        unordered_map<char,int> windowCounts;
        while(r<s.size()){
            char c = s[r];
            if(windowCounts.find(s[r])==windowCounts.end())
                windowCounts[s[r]]=1;
            else
                windowCounts[s[r]]++;
            //如果添加的当前字符的频率等于t中的所需计数，则将formed增加1。
            if (dict.find(c)!=dict.end() && dict[c]==windowCounts[c] )
                formed++;

            while(l<=r && formed==required){
                c = s[l];
                // 更新满足条件的最小的窗口和 l r 指针
                if (ans[0] == -1 || r - l + 1 < ans[0]) {
                    ans[0] = r - l + 1;
                    ans[1] = l;
                    ans[2] = r;
                }
                //Left”指针指向的位置处的字符不再是窗口的一部分。
                windowCounts[c]--;
                if (dict.find(c)!=dict.end() && dict[c]>windowCounts[c] )
                    formed--;
                // 将左指针向前移动，这将有助于查找新窗口。
                l++;
            }
            r++;
        }
        

        return ans[0]==-1 ? "" : s.substr(ans[1],ans[2]-ans[1]+1);

    }
};

int main(){
    Solution sol = Solution();

    cout<<sol.minWindow("ADOBECODEBANC","ABC")<<endl;
}