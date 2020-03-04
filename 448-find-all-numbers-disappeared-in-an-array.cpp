#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
#include <cstdint>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int len = nums.size();

        for(int i=0;i<len;i++){
            if(nums[abs(nums[i])-1]>0){
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            }
        }

        for(int i=0;i<len;i++){
            if(nums[i]>0)
                ans.push_back(i+1);
        }
        return ans;
    }
};
