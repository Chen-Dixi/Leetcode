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
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int N = dungeon.size();
        if (N<1) return 0;
        int M = dungeon[0].size();
        if (M<1) return 0;

        int dp[N][M];
        int hit[N][M];
        dp[0][0] = 0;
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
            {
                if (i==0 && j==0) {
                    dp[i][j] = min(dp[i][j], dungeon[i][j]); 
                    hit[i][j] = dungeon[i][j];
                }
                else if(i==0 && j!=0) {
                    dp[i][j] = min(dungeon[i][j] + hit[i][j-1], dp[i][j-1]); 
                    hit[i][j] = hit[i][j-1] + dungeon[i][j];
                }
                else if(i!=0 && j==0) {
                    dp[i][j] = min(dungeon[i][j] + hit[i-1][j], dp[i-1][j]);
                    hit[i][j] = hit[i-1][j] + dungeon[i][j];
                }
                else {  //这个情况的最优子结构 才是真的要注意的地方
                    if(min(hit[i-1][j]+dungeon[i][j],dp[i-1][j]) > min(hit[i][j-1] + dungeon[i][j], dp[i][j-1])){ //如果 选 向下
                        dp[i][j] = min(dungeon[i][j] + hit[i-1][j], dp[i-1][j]);
                        hit[i][j] = hit[i-1][j] + dungeon[i][j];
                    }else{
                        dp[i][j] = min(dungeon[i][j] + hit[i][j-1], dp[i][j-1]);
                        hit[i][j] = hit[i][j-1] + dungeon[i][j];
                    }
                    
                }
            }

        return dp[N-1][M-1]>0 ? 1: -dp[N-1][M-1] + 1;
        //return dp[N-1][M-1]>0 ? 1: 2;
    }

};

class Solution2 {
public:
    public int calculateMinimumHP(int[][] dungeon) {
        int row = dungeon.length;
        int col = dungeon[0].length;
        int[][] dp = new int[row + 1][col + 1];
        //终点所需要的值
        dp[row - 1][col - 1] = dungeon[row - 1][col - 1] > 0 ? 1 : -dungeon[row - 1][col - 1] + 1;
        //扩充的边界更新为最大值
        for (int i = 0; i <= col; i++) {
            dp[row][i] = Integer.MAX_VALUE;
        }
        for (int i = 0; i <= row; i++) {
            dp[i][col] = Integer.MAX_VALUE;
        }
        
        //逆过来更新
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                if (i == row - 1 && j == col - 1) {
                    continue;
                }
                //选择向右走还是向下走
                dp[i][j] = Math.min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                if (dp[i][j] <= 0) {
                    dp[i][j] = 1;
                }
            }
        }
        return dp[0][0];
    }

}

int main(){
    Solution sol = Solution();
    vector<vector<int>> dungeon = {{1,-3,3},{0,-2,0},{-3,-3,-3}};
    cout<<sol.calculateMinimumHP(dungeon)<<endl;
}