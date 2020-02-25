#include <iostream>
#include <stack>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n<1)
            return 0;
        
        if(n<2)
            return 1;
        int dp[n];
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }

        return dp[n-1];
    }
};

int main(){
    Solution sol = Solution();
    int n=10;
    int ans = sol.climbStairs(n);
    printf("%d\n",ans );
    return 0;
}