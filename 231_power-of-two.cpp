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
    bool isPowerOfTwo(int n) {
        if (n==0)
            return false;
        long a = (long)n;
        return (a&(a-1)) == 0;
    }
};
