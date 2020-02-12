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
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
