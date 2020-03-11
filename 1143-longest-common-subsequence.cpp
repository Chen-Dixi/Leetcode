#include <cstdio>
#include <iostream>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    //注意问题是公共子序列
    int longestCommonSubsequence(string text1, string text2) {
        int len1=text1.size();
        int len2=text2.size();

        if(len1==0 || len2==0){
            return 0;
        }

        int dp[len1+1][len2+1];
        
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=len1;i++)
            for(int j=1;j<=len2;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }

        return dp[len1][len2];
    }
};


int main(){
    string text1 = "abcde";
    string text2 = "ace";

    Solution sol = Solution();
    int ans = sol.longestCommonSubsequence(text1, text2);
    cout<<ans<<endl;
}