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

/*
考察字符串编程能力
分析时间效率能力
两种不同方法时间效率各是多少
*/

class Solution {
public:
    string replaceSpace(char[] str, int length) {
        if(string == nullptr || length<=0){
            return;
        }

        int originalLength = 0;
        int numberOfBlank = 0;

        int i=0;
        while(str[i]!='\0'){
            originalLength++;
            if(str[i]==' ')
                ++numberOfBlank;
            i++;
        }

        int newLength = originalLength+2*numberOfBlank;
        if(newLength>length)
            return;

        int indexOfOriginal = originalLength; //这个时候 index 指的是最后的'\0';
        int indexOfNew = newLength;

        while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal){
            if(str[indexOfOriginal--]==' '){
                str[indexOfNew--]='0';
                str[indexOfNew--]='2';
                str[indexOfNew--]='%';
            
            }else{
                str[indexOfNew--]=str[indexOfOriginal--];
            }
        }
    }
};

int main(){

}