#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char,int> dict;
        int len = s.size();
        if(len<=0)
            return " ";

        for(int i=0;i<len;i++)
        {
            if(dict.find(s[i])==dict.end())
            {
                //没找到
                dict[s[i]]=0;
            }else{
                dict[s[i]]=dict[s[i]]+1;
            }
        }

        for(int i=0;i<len;i++){
            if(dict[s[i]]==0)
                return s[i];
        }
        return " ";
    }
};