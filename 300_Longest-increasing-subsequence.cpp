#include <iostream>
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
    int lengthOfLIS(vector<int>& nums) {
        //dp[i]表示nums[i]的最长上升子序列长度
        //比较dp中元素的最大值，就是答案了
        int len = nums.size();
        if(len == 0)return 0;
        int ans = 1;
        vector<int> dp(len,1);
        for(int i = 1;i < len;i++){
            for(int j = 0;j < i;j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[j]+1,dp[i]);
                    ans = max(dp[i],ans);     
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution sol = Solution()
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout<<sol.lengthOfLIS(nums)<<endl;
}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //dp[i]表示nums[i]的最长上升子序列长度
        //比较dp中元素的最大值，就是答案了
        int len = nums.size();
        if(len == 0)return 0;
        int ans = 1;
        vector<int> dp(len,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i])
                {
                    dp[i]=max(dp[j]+1,dp[i]);
                    ans = max(dp[i],ans);
                }
            }
        }
        
        return ans;
    }
};
