#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <utility>
#include <cstdint>
#include <cstdint>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int valley;
        int peak;
        int maxprofit = 0;
        if(prices.size()==0)
            return 0;
        while (i < prices.size() - 1) {
            while (i < prices.size() - 1 && prices[i] >= prices[i + 1])
                i++;
            valley = prices[i];
            while (i < prices.size() - 1 && prices[i] <= prices[i + 1])
                i++;
            peak = prices[i];
            maxprofit += peak - valley;
        }
        return maxprofit;
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        //状态转移
        int totaldays = prices.size();
        if (totaldays < 2) {
            return 0;
        }
        int dp[totaldays][2];
        dp[0][0]=0;
        dp[0][1]=-prices[0];

        for(int i=1;i<totaldays;i++){
            dp[i][0] = max(dp[i-1][1]+prices[i], dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0]-prices[i], dp[i-1][1]);
        }

        return dp[totaldays-1][0];
    }
};

class Solution3 {
public:
    int maxProfit(vector<int>& prices) {
        //状态转移
        //状态压缩动态规划

        int totaldays = prices.size();
        if (totaldays < 2) {
            return 0;
        }
        int dp[2];
        dp[0]=0;
        dp[1]=-prices[0];
        int last=dp[0];
        for(int i=1;i<totaldays;i++){
            dp[0] = max(dp[1]+prices[i], dp[0]);
            dp[1] = max(last-prices[i], dp[1]);
            last = dp[0]
        }

        return dp[totaldays-1][0];
    }
};

int main(){
    Solution sol = Solution();
    vector<int> points = {7,1,5,3,6,4};
    int ans = sol.maxProfit(points);
    printf("%d\n",ans );
    return 0;
}