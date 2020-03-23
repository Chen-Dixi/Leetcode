#include <unordered_set>
#include <iostream>
#include <vector>
#include <cstdio>

class Solution {
public:
    //时间复杂度是O(n)，空间复杂度是O(n)
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> set;

        int len = nums.size();

        for(int i=0;i<len;i++){
            if(set.find(nums[i])==set.end()){
                set.insert(nunms[i]);
            }else{
                return nums[i];
            }
        }
    }
};

class Solution {
public:
    //时间复杂度是O(n)，空间复杂度是O(1)
    int findRepeatNumber(vector<int>& nums) {

        int len = nums.size();

        for(int i=0;i<len;i++){
            if(nums[i]==i)
                continue;

            //不等于i
            if(nums[nums[i]]==nums[i])
                return nums[i];
            else{
                int tmp = nums[nums[i]];
                nums[nums[i]] = nums[i];
                nums[i] = tmp;
            }
        }
        return -1;
    }  
};

class Solution{
public:
    //时间复杂度是O(n)，空间复杂度是O(1)
    int findRepeatNumber(vector<int>& nums) {

        int len = nums.size();

        for(int i=0;i<len;i++){
            while(nums[i]!=i){
                if(nums[i]==nums[nums[i]])
                    return nums[i];

                int tmp = nums[i];
                nums[nums[i]] = nums[i];
                nums[i] = tmp;
            }
        }
        return -1;
    }  
};