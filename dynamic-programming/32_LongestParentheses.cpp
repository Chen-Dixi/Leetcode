#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        //用vector的坏处就是，每个else都要push_back, 否则会出问题
        vector<int> dp;

        
        dp.push_back(0);
        int max_length=0;
        for(int i=1; i<s.size(); i++){
            if(s[i]==')' && s[i-1]=='('){
                if(i-2 >= 0){
                    dp.push_back(dp[i-2]+2);
                }else
                    dp.push_back(2);


            }else if(s[i]==')' && s[i-1]==')'){
                if (i-dp[i-1]-1 >= 0) 
                {
                    if(s[i-dp[i-1]-1] == '('){
                    /* code */
                        dp.push_back(dp[i-1]+2);
                        if(i-dp[i-1]-2>=0)
                            dp[i] = dp[i]+dp[i-dp[i-1]-2];
                    }else
                        dp.push_back(0);        
                }else
                    dp.push_back(0);
            }
            else
                dp.push_back(0);
            max_length = max(max_length,dp[i]);
        }
        return max_length;
    }
};


int main(){
    Solution sol = Solution();
    int ans = sol.longestValidParentheses("()");
    printf("%d\n",ans );
    return 0;
}