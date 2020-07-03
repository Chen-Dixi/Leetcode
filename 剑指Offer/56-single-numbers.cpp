#include <stack>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int num1=0,num2=0;
        int len = nums.size();
        vector<int> ans;
        if(len<0)
            return ans;

        int xordata=0;
        for (int i = 0; i < len; ++i)
        {
            xordata^=nums[i];
        }

        int firstBit = rightBits(xordata);
        for (int i = 0; i < len; ++i)
        {
            if(isBit1(nums[i], firstBit)){
                num1^=nums[i];
            }else{
                num2^=nums[i];
            }
            /* code */
        }

        ans.push_back(num1);
        ans.push_back(num2);

        return ans;
    }

    unsigned int rightBits(int num){
        int bit=0;
        while((num&1)==0 && bit<8*sizeof(int)){
            num=num>>1;
            bit++;
        }   
        return bit;
    }

    bool isBit1(int num,unsigned int indexBit){
        num = num>>indexBit;
        return(num&1);
    }

};
