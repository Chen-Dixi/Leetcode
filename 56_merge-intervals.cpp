#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
using namespace std;


class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return {};
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int> > ans;

        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();++i){
            if (intervals[i][0]<=ans.back()[1]){
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};

int main(){
    Solution sol = Solution();
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int> > ans = sol.merge(intervals);
    //cout<<sol.minPathSum(grid)<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<"("<<ans[i][0]<<","<<ans[i][1]<<")"<<endl;

}