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
    int nthUglyNumber(int index) {
        if(index<0){
            return 0;
        }
        int number=0;
        int uglyFound=0;
        while(uglyFound<index){
            ++number;
            if(IsUgly(number)){
                uglyFound++;
            }
        }
        return number;
    }

    bool IsUgly(int number){
        while(number%2==0)
            number/=2;
        while(number%3==0)
            number/=3;
        while(number%5==0)
            number/=5;

        return number==1?true:false;
    }
};

class Solution {
public:
    int nthUglyNumber(int index) {
        int *table = new int[index];

        table[0]=1;
        int* mul2 = table;
        int* mul3 = table;
        int* mul5 = table;
        int i=1;
        while(i<index){
            table[i] = getMin(*mul2,*mul3,*mul5);//打表，下一个，大家都是从1开始，*2，*3，*5这样乘上来的
            //getMin的结果是最小的，所以后面无关的mulk指针就不会更新
            while(*mul2*2<=table[i])
                mul2++;
            while(*mul3*3<=table[i])
                mul3++;
            while(*mul5*5<=table[i])
                mul5++;
            
            i++;
        }

        int ans = table[index-1];
        delete[] table;
        return ans;
    }

    int getMin(int m2,int m3,int m5){
        return min(m2*2,min(m3*3,m5*5));
    }
};