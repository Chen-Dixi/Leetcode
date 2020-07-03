class Solution {
public:
    /*题目描述：把 n 个骰子仍在地上，求点数和为 s 的概率。

解题思路：定义 dp[i][j] 为前 i 个骰子产生点数 j 的次数。

状态转移方程为：dp[i][j] = dp(i-1,j-1) + dp(i-1,j-2) + dp(i-1,j-3) + dp(i-1,j-4) + dp(i-1,j-5)+dp(c-1,k-6)。*/
    vector<double> twoSum(int n) {
        //n个骰子的点数
        int dp[15][70]; //1<=n<=11
        vector<double>ans;
        memset(dp,0,sizeof(dp));

        for(int i=1;i<=6;i++)
            dp[1][i]=1;

        for(int i=2;i<=n;i++) //骰子数量
        {
            for(int j=i; j<=6*i; j++){ //骰子点数
                for(int cur=1;cur<=6&&j-cur>0;cur++) //处理边界
                    dp[i][j]+=dp[i-1][j-cur];
            }
        }

        int all = pow(6,n);
        for (int i = n; i <= 6 * n; i ++) {
            ans.push_back(dp[n][i] * 1.0 / all);
        }
        return ans;
    }
};