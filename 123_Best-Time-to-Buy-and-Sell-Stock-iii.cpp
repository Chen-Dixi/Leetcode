#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
#include <cstdint>
using namespace std;

//通用方法 https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-wen/
//3元组状态转移
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalDays = prices.size();
        int dp[100000][3][2];// 选了100000这个数字就可以通过样例了

        for(int k=0;k<=2;k++){
            dp[0][k][0]=0;
            dp[0][k][1]=INT_MIN;
        }

        for(int i=1;i<=totalDays;i++){
            dp[i][0][0]=0;
            dp[i][0][1]=INT_MIN;
        }        

        for(int i=1;i<=totalDays;i++){
            for(int k=1;k<=2;k++){
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1]+prices[i-1]);
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0]-prices[i-1]);
            }
        }

        return dp[totalDays][2][0];
    }
};

//另一种状态转移
class Solution2{
public:
    int maxProfit(vector<int>& prices) {
        int lens = prices.size();
        
        if (lens < 2){
            return 0;
        }

        int dp[lens][5];
        //=====处理好初始状态
        dp[0][0]=0;
        dp[0][1]=-prices[0];

        for(int i=0;i<lens;i++){
            dp[i][3] = -(1<<24); //第二次买股票设定为不可能的额熟
        }
        //======

        for(int i=1;i<lens;i++){
            dp[i][0]=0;
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
            dp[i][2]=max(dp[i-1][2],dp[i-1][1]+prices[i]);
            dp[i][3]=max(dp[i-1][3],dp[i-1][2]-prices[i]);
            dp[i][4]=max(dp[i-1][4],dp[i-1][3]+prices[i]);
        }

        return max(0, max(dp[lens-1][2],dp[lens-1][4]));
    }
};

int main(){
    Solution2 sol = Solution2();
    vector<int> points = {3,3,5,0,0,3,1,4};
    int ans = sol.maxProfit(points);
    printf("%d\n",ans );
    return 0;
}

