/*
 * @lc app=leetcode.cn id=11 lang=java
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
    public int maxArea(int[] height) {
        int i=0;
        int j=height.length-1;
        int area = 0;
        while(i<j){
            int cur = Math.min(height[i],height[j]) * (j-i);
            area = Math.max(area, cur);
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return area;
    }
}
// @lc code=end

