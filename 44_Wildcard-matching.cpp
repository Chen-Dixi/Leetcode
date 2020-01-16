#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        
        int m = s.size(), n = p.size(), i=0, j=0, iStar=-1, jStar=-1;
        while(i<m){
            if ( j < n && ( s[i]==p[j] || p[j]=='?' )){
                i++;
                j++;
            }else if(j<n&&p[j]=='*'){
                iStar = i;//这里i的光标不动
                jStar = j++;//j的光标移动
            }else if(iStar>=0){
                i = ++iStar;//p里面的* 尝试匹配更多s里面的字符
                j = jStar + 1; //把j重新移动回来，因为有可能之前让*匹配的字符失败了，现在让*匹配更多s里面的字符，j的光标就移动回来。
            }else return false;
        }
        while(j<n && p[j]=='*') j++;
        return j==n;

        // return true;
    }
};

class Solution2 {
public:

    // 药分析出这个状态转移的细节，还是需要一定问题分析能力的
    bool isMatch(string s, string p) {
        
        int m = p.size(); // m表示pattern的长度
        int n = s.size(); // n表示s的长度

        // 减少空间使用，就用一个dp数组
        bool dp[m+1]; //虽然是从0开始索引，但是我们需要一个m的索引

        dp[m] = true; //因为此时假想 i==n;

        for (int j=m-1; j >= 0; j--){
            dp[j] = p[j] == '*' ? dp[j+1] : false; //题解公式的第3条
        }

        for(int i=n-1; i>=0; i--){
            bool lastRight = dp[m]; //opt(i+1,m) 当后面(i,n-1)是s[i]==p[m-1]匹配的上的话，就需要用到 (i,m-1) = (i+1,m) = (i+1,j+1) = lastRight 

            for(int j=m-1;j>=0;j--){
                if (s[i]==p[j] || p[j]=='?'){ // 题解公示第4条
                    
                    // dp[j]=dp[j+1];不对，这里的dp[j+1]已经变成(i,j+1),而我们需要(i+1,j+1)
                    int temp = dp[j];
                    dp[j]=lastRight; // 这里的lastRight保存着 (i+1,j+1);
                    lastRight = temp; //lastRight保存(i+1,j)，当j减小的时候，后面的(i,j-1)需要用到这个{ (i+1),[(j-1)+1] }
                }else if (p[j]=='*'){ // 题解公示第5条
                    lastRight = dp[j];
                    dp[j] = dp[j] || dp[j+1]; // (i,j) = (i+1,j) || (i,j+1)
                    
                }else{
                    lastRight = dp[j];
                    dp[j] = false;
                }
            }
            dp[m]=false;//i在小于n后，dp[m]都是false，
        }


        return dp[0];
    }
};

int main(int argc, char const *argv[])
{
    Solution2 sol = Solution2();
    // string s = "adceb";
    // string p = "*a*b";

    // string s = "acdcb";
    // string p = "a*c?b";

    string s = "abccdc";
    string p = "ab*c*";
    cout << (sol.isMatch(s,p) ? "True" : "False") << endl;
}

