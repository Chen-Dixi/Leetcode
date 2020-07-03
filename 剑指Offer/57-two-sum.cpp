class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> ans;
        if(len<=1)
            return ans;

        int i=0,j=len-1;
        int num1,num2;
        while(i<j){
            if(nums[i]+nums[j]>target){
                j=j-1;
            }else if(nums[i]+nums[j]<target){
                i=i+1;
            }else{
                ans.push_back(nums[i]);
                ans.push_back(nums[j]);
                break;
            }
        }

        return ans;
    }
};