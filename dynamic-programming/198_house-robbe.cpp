#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int ans=0;
        int len=nums.size();

        if (len<1)
            return 0;
        if (len==1)
            return nums[0];
        if (len==2)
            return max(nums[0],nums[1]);

        int dp[len];

        dp[0]=nums[0];
        dp[1]=nums[1];
        ans = max(dp[0],dp[1]);
        for(int i=2;i<len;i++){
            if(i==2){
                dp[i] = dp[i-2]+nums[i];
            }else{
                dp[i] = max(dp[i-2],dp[i-3])+nums[i];
            }
            ans=max(ans, dp[i]);
        }

        return ans;
    }
};

int main(){
    Solution sol = Solution();
    vector<int> nums = {2,7,9,3,1};
    int ans = sol.rob(nums);
    printf("%d\n",ans );
    return 0;
}