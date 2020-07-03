#include <iostream>
using namespace std;
class Solution {
public:
    int hammingWeight(int n) {
        uint32_t s = n;
        int count=0;
        while(s){
            s = s & (s-1);
            count++;
        }
        return count;
    }
};

int main()
{
    Solution sol = Solution();
    cout<<(sol.hammingWeight(-2))<<endl;
}