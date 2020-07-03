#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <complex>
using namespace std;

//超出时间限制
// class Solution {
// public:
//     int findNthDigit(int n) {
        
//         int count=0;
//         int number=1;
//         int prev;
        
//         while(count<n){
//             prev=count;
//             count+=numberOfdigit(number++);
//         }
//         int index = n-prev;
//         return numberOfIndex(number-1, index);
//     }

//     int numberOfdigit(int n){
//         int ans=0;
//         for(int i=1;i<=n;i*=10){
//             ans++;
//         }
//         return ans;
//     }

//     int numberOfIndex(int number,int index){
//         int n = numberOfdigit(number);
//         for(int i=0;i<n-index;i++){
//             number/=10;
//         }
//         return number % 10;
//     }
// };

class Solution {
public:
    int findNthDigit(int n) {
         if(n<0)return -1;

         int wei=1;
         while(true){
            int numbers = numberOfWei(wei);
            if(n<numbers*wei){
                return  findNthDigit(n, wei);   
            }

            n-=numbers*wei;
            wei++;
         }
         
         return -1;
    }

    int numberOfWei(int wei){
        if(wei==1)
            return 10;

        int count = (int) pow(10,wei-1);
        return 9*count;
    }
    //在wei位的数字中找第n位的数字
    int findNthDigit(int n, int wei){
        int number=beginNumber(wei)+n/wei;
        int indexFromRight=wei-n % wei;
        for(int i=1;i<indexFromRight;++i){
            number/=10;
        }
        return number % 10;
    }

    int beginNumber(int wei){
        if(wei==1)
            return 0;
        return (int) pow(10,wei-1);
    }
};

class Solution {
public:
    int findNthDigit(int n) {
        // 计算该数字由几位数字组成，由1位：digits = 1；2位：digits = 2...
        long base = 9,digits = 1;
        while (n - base * digits > 0){
            n -= base * digits;
            base *= 10;
            digits ++;
        }

        // 计算真实代表的数字是多少
        int idx = n % digits;  // 注意由于上面的计算，n现在表示digits位数的第n个数字
        if (idx == 0)idx = digits;
        long number = 1;
        for (int i = 1;i < digits;i++)
            number *= 10;
        number += (idx == digits)? n/digits - 1:n/digits;

        // 从真实的数字中找到我们想要的那个数字
        for (int i=idx;i<digits;i++) number /= 10;
        return number % 10;
    }
};

作者：z1m
链接：https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/solution/zhe-shi-yi-dao-shu-xue-ti-ge-zhao-gui-lu-by-z1m/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。