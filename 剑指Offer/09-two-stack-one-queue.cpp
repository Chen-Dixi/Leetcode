#include <bits/bstdc++.h>

class CQueue {
private:
    stack<int> stc1;
    stack<int> stc2;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        while(!stc1.empty())
        {
            int a = stc1.top();
            stc1.pop();
            stc2.push(a);
        }
        stc1.push(value);
        while(!stc2.empty())
        {
            int a = stc2.top();
            stc2.pop();
            stc1.push(a);
        }
    }
    
    int deleteHead() {
        if(stc1.empty())
            return -1;
        int res = stc1.top();
        stc1.pop();
        return res;
    }
};

class CQueue {
private:
    stack<int> stc1;
    stack<int> stc2;
    int size;
public:
    CQueue() {
        this->size=0;
    }
    
    void appendTail(int value) {
        stc1.push(value);
        this.size++;
    }
    
    int deleteHead() {
        if(stc2.empty()){
            if(stc1.empty()){
                return -1;
            }
            else{
                while(!stc1.empty()){
                    int a = stc1.top();
                    stc2.push(a);
                    stc1.pop();
                }
            }
        }
        int res = stc2.top();
        stc2.pop();
        this->size--;
        return res;
    }
};