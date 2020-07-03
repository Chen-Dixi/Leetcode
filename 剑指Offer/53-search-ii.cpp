class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();

        //[0,1,3,4]
        int i=0;int j=len-1;
        while(i<=j){
            int m=(i+j)/2;
            if(nums[m]!=m){
                // 找到了
                if(m==0 || nums[m-1]==m-1){
                    return m;//缺的就是这个
                }
                //else，在左边二分查找
                j = m-1;
            }else{
                //
                i = m+1;
            }
        }
        //还有最后一种情况，没有nums[m]!=m的情况，则，[0,1,2,3]这种情况，4个数字， 0~
        if(i==len)
            return len;
        return 0;
    }
};
