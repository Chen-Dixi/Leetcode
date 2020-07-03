/*
 * @lc app=leetcode.cn id=718 lang=java
 *
 * [718] 最长重复子数组
 */

// @lc code=start
class Solution {
    public int findLength(int[] A, int[] B) {
        int aLength = A.length;
        int bLength = B.length;
        int[][] dp = new int[aLength+1][bLength+1];

        dp[0][0] = 0;
        int ans = 0;
        for(int i=1; i <= aLength; i++)
            for(int j=1; j <= bLength; j++){
                if(A[i-1]==B[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=0;
                }
                ans = Math.max(ans, dp[i][j]);
            }
        
        return ans;
    }
}
// @lc code=end

