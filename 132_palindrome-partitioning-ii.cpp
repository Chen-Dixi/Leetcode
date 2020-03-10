#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
#include <climits>
using namespace std;

/*
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。
*/
class Solution {
public:
    

    int minCut(string s) {
        int ans=0;
        //动态规划，状态转移
        int len = s.size();
        //是不是回文的标志
        vector<vector<int> > p(len, vector<int>(len,0));
        vector<int> dp(len, INT_MAX);

        //初始化
        for(int j=0;j<len;j++){
            p[j][j]=1; 

            for(int i=0;i<=j;i++){

                if (s[i]==s[j] && i+1==j)
                    p[i][j]=1;

                if(s[i] == s[j] && j - i >= 2 && p[i+1][j-1])
                    p[i][j] = 1;

                if (p[i][j] && i != 0) 
                    dp[j] = min(dp[j], dp[i - 1] + 1);
                else if ( p[i][j] && i == 0) //f[0,j]是回文串，f[j] = 0 不需要切割
                    dp[j] = 0;

            }
        }
        return dp[len-1];
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
    int ans = sol.minCut(str);
    cout<< ans<<endl;
    return 0;
}