#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

//题解：https://leetcode-cn.com/problems/max-points-on-a-line/solution/zhi-xian-shang-zui-duo-de-dian-shu-by-leetcode/
//主要是怎么保存边，用字典保存边有很多种方式，这里用一个pair作键
class Solution {
public:
    using pii = pair<int, int>;
    int maxPoints(vector<vector<int>>& points) {
        int ans=1;
        if(points.size()<=2)
            return points.size();

        map<pii,int> mp;

        for(int i=0;i<points.size()-1;i++){
            mp.clear();
            int counts=1;
            int duplicates=0;
            for(int j=i+1;j<points.size();j++){
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                if( dx == 0 && dy == 0) {  // check for the duplicate points 
                    duplicates ++;     
                    continue;
                }

                int gcd = GCD(dx,dy);
                ++mp[{dx / gcd, dy / gcd}];

            }
            for (auto p : mp) {
                counts = max (p.second+1, counts);
            }

            ans = max(ans, counts+ duplicates);
        }



        return ans;
    }
    
private:
    int GCD(int a, int b){
        return b==0 ? a: GCD(b, a%b);
    }
};


int main(){
    Solution sol = Solution();
    vector<vector<int> > points = {{1,1},{2,2},{3,3}};
    int ans = sol.maxPoints(points);
    printf("%d\n",ans );
    return 0;
}