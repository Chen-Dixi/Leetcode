#include <vector>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1)
            return false;
        vector<vector<int> > dp(stones.size()+1,vector<int>());
        dp[1].push_back(1);
        for(int i=1;i<stones.size()-1;i++)
        {
            if(dp[i].size()==0) return false;
            
            for(int j=0;j<dp[i].size();j++){//上一步跳数
                int lastjump=dp[i][j];
                for(int k=i+1;stones[k]-stones[i]<=lastjump+1 && k<stones.size();k++)
                {
                    if((stones[k]-stones[i])>=lastjump-1 )
                    {
                        if(k==stones.size()-1) return true;
                        dp[k].push_back(stones[k]-stones[i]);
                    }
                }
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    std::vector<int> v = {0,1,3,6,7};
    cout<<solution.canCross(v);
    
}
