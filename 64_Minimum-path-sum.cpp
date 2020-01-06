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
    int minPathSum(vector<vector<int>>& grid) {
        int N = grid.size();
        if (N<1) return 0;
        int M = grid[0].size();
        if (M<0) return 0;

        long dp[N][M];

        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++){
                if (i==0 && j==0) dp[i][j]=grid[0][0];
                else if(i==0 && j!=0) dp[i][j] = grid[i][j]+dp[i][j-1];
                else if(i!=0 && j==0) dp[i][j] = grid[i][j]+dp[i-1][j];
                else dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
            }

        return dp[N-1][M-1];
    }
};

int main(){
    Solution sol = Solution();
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout<<sol.minPathSum(grid)<<endl;
}