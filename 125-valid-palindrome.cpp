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
    bool isPalindrome(string s) {
        
        //
        string tmp="";

        for(auto c:s){
            if(islower(c) || isdigit(c)) tmp.push_back(c);
            else if (isupper(c)) tmp.push_back(tolower(c));
        }

        int i=0, j=tmp.size()-1;
        cout<<tmp<<endl;
        while(i<j){
            if(tmp[i]!=tmp[j])
                return false;
            i++;j--;
        }

        return true;
    }
};

int main(){
    Solution sol = Solution();
    string s = "A man, a plan, a canal: Panama";
    bool ans = sol.isPalindrome(s);
    cout<< (ans?"True":"False") << endl;
    return 0;
}