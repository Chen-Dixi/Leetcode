#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
#include <cstring>
using namespace std;


class Solution {

private:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;
public:
    void DFS(int start, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            path.push_back(candidates[i]);
            // 元素不可重复利用，使用下一个即i+1
            DFS(i + 1, target - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        //吸纳拍好
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        DFS(0, target);
        return res;
    }
};

class Solution{
public :
    vector<vector<int> > res;
    int target;

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        //吸纳拍好
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        this->target = target;
        dfs(0, 0, candidates, path);
        
        return this->res;
    }

    void dfs(int index, int sum, vector<int> &candidates, vector<int> & path){
        
        if(sum == this->target){
            this->res.push_back(path);
        }

        for(int i=index;i<candidates.size() && sum+candidates[i]<=this->target;i++){
            if(i>index && candidates[i]==candidates[i-1]) //同一层内搜索就不行
                continue;
            path.push_back(candidates[i]);
            dfs(i+1, sum+candidates[i],candidates,path); //注意第一个参数，我们先排好序，就是为了防止搜索到重复的答案，所以第一个参数别写成index+1，应该写成i+1
            path.pop_back();
        }

    }
};

int main(){
    Solution sol = Solution();
    vector<int> points = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> ans = sol.combinationSum2(points, target);
    cout<<ans<<endl;
    return 0;
}