#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int N = obstacleGrid.size(); //竖着的方向
        //=========== 对特殊输入情况的处理
        if (N<1) return 0; //这样来判断无输入的情况
        int M = obstacleGrid[0].size();//横着的方向
        if(M<1) return 0;
        long dp[M][N];
        if(1==obstacleGrid[0][0]) return 0; // 把障碍放在了第一个格子
        //===========

   
        for(int i=0;i < M;i++)
            for(int j=0;j< N;j++) {
                if (i==0 && j==0) dp[0][0]=1;
                else if (obstacleGrid[j][i]==1) dp[i][j]=0;
                else if(i==0 && j!=0)
                    dp[i][j]=dp[i][j-1];
                else if(j==0 && i!=0)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        return static_cast<int>(dp[M-1][N-1]);
    }
};



int main(){
    Solution sol = Solution();
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    cout<<sol.uniquePathsWithObstacles(obstacleGrid)<<endl;
}