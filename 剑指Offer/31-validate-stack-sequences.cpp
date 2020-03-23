#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std; 

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int push_len = pushed.size();
        int pop_len = popped.size();
        if(push_len<=0 && pop_len<=0)
            return true;
        if((push_len<=0 || pop_len<=0))
            return false;
        stack<int> stc;

        int next2push=0;
        for(int i=0;i<pop_len;i++){
            if(stc.empty())
                stc.push(pushed[next2push++]);

            while(next2push<=push_len){
                if(stc.top()==popped[i]){
                    stc.pop();
                    break;
                }
                if(next2push>=pop_len)
                    return false;
                stc.push(pushed[next2push++]);
            }
        }

        return true;
    }
};

class Solution{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int push_len = pushed.size();
        int pop_len = popped.size();
        if(push_len<=0 && pop_len<=0)
            return true;
        if((push_len<=0 || pop_len<=0))
            return false;
        stack<int> stc;

        int nextpush = 0;
        int nextpop = 0;

        while(nextpop<pop_len){
            while(stc.empty() || stc.top()!=popped[nextpop]){
                if(nextpush==push_len)
                    break;

                stc.push(pushed[nextpush++]);
            }

            if(stc.top()!=popped[nextpop]){
                break;
            }

            stc.pop();

            nextpop++;
        }



        return nextpop==pop_len;
    }
};