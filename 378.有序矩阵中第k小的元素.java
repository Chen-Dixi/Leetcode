/*
 * @lc app=leetcode.cn id=378 lang=java
 *
 * [378] 有序矩阵中第K小的元素
 */

// @lc code=start
class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        //二分法查找
        int n = matrix.length;
        if(n<=0){
            return -1;
        }
        //假设K永远有效

        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        int mid;
        while(left<right){
            mid = (left+right)/2;
            if(check(matrix, k, n,mid)){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }

    private boolean check(int[][] matrix, int k, int n, int mid){
        int num=0;
        //左下角开始搜索
        int i=n-1;
        int j=0;
        
        while( i>=0 && j<n ){
            if(matrix[i][j]<=mid){
                j++;
                num+=(i+1);
            }else{
                i--;
            }
        }

        return num>=k;
    }
}
// @lc code=end

