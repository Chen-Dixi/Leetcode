#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

//符号匹配就用栈来做
class Solution {
public:
    //用栈来解决
    bool isValid(string s) {
        int len = s.size();

        if(len==0){
            return true;
        }
        unordered_map<char,char> dict = {{')','('},{'}','{'},{']','['}};

        stack<char> stac;
        stac.push('?');
        for(int i=0;i<len;i++){
            if(s[i]=='(' || s[i]=='{' ||s[i]=='['){
                stac.push(s[i]);
            }else{
                if(stac.top()==dict[s[i]]){
                    stac.pop();
                }else{
                    return false;
                }
            }
        }

        return stac.size()==1;
    }
};

int main(){
    Solution2 sol = Solution2();
    string s = "()[]{}";
    bool ans = sol.isValid(s);
    printf("%s\n",ans ? "true":"false" );
    return 0;
}
