/*
求区间中的最大值，用递减栈

双端队列，维护队头是否已经出区间

时间复杂度 O(N)
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> deq;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            while(!deq.empty() && nums[i] > nums[deq.back()]){
                deq.pop_back();
            }
            if (!deq.empty() && deq.front() < i - k + 1) deq.pop_front();
            deq.push_back(i);
            if (i >= k -1) ans.push_back(nums[deq.front()]);
        }
        return ans;

    }
};

class Solution{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> deq;
        //O(n)
        int n = nums.size();
        //从0～n-1遍历
        for (int i = 0; i < n; i++){
            //刚开始，如队列，把比当前小的都排出去
            while(!deq.empty() && nums[deq.back()]<nums[i])
                deq.pop_back();
            //如果扫面窗口离开了这个位置
            if(!deq.empty() && deq.front() < i-k+1) deq.pop_front();
            //压入栈就行了，压栈压的是索引
            deq.push_back(i);
            //获取结果
            if(i>=k-1) ans.push_back(nums[deq.front()]);
        }
        return ans;
    }
}