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
    bool isMatch(string s, string p) {
        
        int m = s.size(), n = p.size(), i=0, j=0, iStar=-1, jStar=-1;
        while(i<m){
            if ( j < n && ( s[i]==p[j] || p[j]=='?' )){
                i++;
                j++;
            }else if(j<n&&p[j]=='*'){
                iStar = i;//这里i的光标不动
                jStar = j++;//j的光标移动
            }else if(iStar>=0){
                i = ++iStar;//p里面的* 尝试匹配更多s里面的字符
                j = jStar + 1; //把j重新移动回来，因为有可能之前让*匹配的字符失败了，现在让*匹配更多s里面的字符，j的光标就移动回来。
            }else return false;
        }
        while(j<n && p[j]=='*') j++;
        return j==n;



        // return true;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol = Solution();
    // string s = "adceb";
    // string p = "*a*b";

    // string s = "acdcb";
    // string p = "a*c?b";

    string s = "abccdc";
    string p = "ab*c*";
    cout << (sol.isMatch(s,p) ? "True" : "False") << endl;
}

