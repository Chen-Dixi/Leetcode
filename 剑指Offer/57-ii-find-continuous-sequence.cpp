class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        if(target<3)
            return ans;

        int small=1,big=2;
        int middle = (1+target)/2;
        int curSum = small+big;

        while(small<middle){
            if(curSum==target)
                saveSequence(ans, small,big);
            while(curSum > target && small < middle){
                curSum-=small;
                small++;
                if(curSum==target)
                    saveSequence(ans, small,big);
            }

            big++;
            curSum+=big;
        }

        return ans;
    }

    void saveSequence( vector<vector<int>> &ans, int small,int big)
    {
        vector<int> one;
        for(int i=small;i<=big;i++)
        {
            one.push_back(i);
        }
        ans.push_back(one);
    }
};