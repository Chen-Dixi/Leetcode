class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();

        if(len<=0)
            return 0;

        int first = GetFirstTarget(nums, target, 0, len-1);
        int last = GetLastTarget(nums, target, 0, len-1);

        if(first!=-1 && last!=-1)
            return last-first+1;

        return 0;
    }

    int GetFirstTarget(vector<int>& nums, int target, int start, int end)
    {
        if(start>end)
            return -1;

        int m = (start+end)/2;
        int m_data = nums[m];
        if(m_data==target)
        {
            if((m > 0 && nums[m-1]!=target) || m == 0 )
                return m;
            else
                end = m-1;
        }
        else if(m_data>target)
            end = m-1;
        else 
            start = m+1;

        return GetFirstTarget(nums, target, start, end);
    }

    int GetLastTarget(vector<int>& nums, int target, int start, int end)
    {
        if(start>end)
            return -1;

        int m = (start+end)/2;
        int m_data = nums[m];
        if(m_data==target)
        {
            if((m < nums.size()-1 && nums[m+1]!=target) || m == nums.size()-1 )
                return m;
            else
                start = m+1;
        }
        else if(m_data>target)
            end = m-1;
        else 
            start = m+1;

        return GetLastTarget(nums, target, start, end);
    }
};