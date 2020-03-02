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
public:

    vector<int> input;
    int target;
    vector<vector<int>> result;
    vector<int> vc;

    void dfs(int index, int sum) {
        // index >= input.size() ，写成 index == input.size() 即可
        // 因为每次都 + 1，在 index == input.size() 剪枝就可以了
        if (sum >= target || index == input.size()) {
            if (sum == target) {
                result.push_back(vc);
            }
            return;
        }
        for (int i = index; i < input.size(); i++) {
            if (input[i] > target) {
                continue;
            }

            // 【我添加的代码在这里】：
            // 1、i > index 表明剪枝的分支一定不是当前层的第 1 个分支
            // 2、input[i - 1] == input[i] 表明当前选出来的数等于当前层前一个分支选出来的数
            // 因为前一个分支的候选集合一定大于后一个分支的候选集合
            // 故后面出现的分支中一定包含了前面分支出现的结果，因此剪枝
            // “剪枝”的前提是排序，升序或者降序均可
            if (i > index && input[i - 1] == input[i]) {
                continue;
            }

            vc.push_back(input[i]);
            sum += input[i];
            dfs(i + 1, sum);
            vc.pop_back();
            sum -= input[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        // “剪枝”的前提是排序，升序或者降序均可
        sort(candidates.begin(), candidates.end());
        this->input = candidates;
        this->target = target;
        dfs(0, 0);
        return result;
    }
};

作者：liweiwei1419
链接：https://leetcode-cn.com/problems/combination-sum-ii/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int main(){
    Solution sol = Solution();
    vector<int> points = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> ans = sol.combinationSum2(points, target);
    cout<<ans<<endl;
    return 0;
}