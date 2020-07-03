#include <cstdio>
#include <iostream>
#include <cstring>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len=nums.size();
        if(len<=0) 
            return 0;
        if(len==1)
            return nums[0];
        
        int ans=nums[0];
        for(int i=1;i<len;i++){
            nums[i] = max(nums[i-1]+nums[i],nums[i]);
            ans = max(ans, nums[i]);
        }
        return ans;
    }
};