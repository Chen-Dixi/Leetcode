class Solution {
public:
    int sumNums(int n) {
        return quick_sum(n+1,n) >> 1; 
    }

    int quick_sum(int a, int n)//a*n
    {
        int ans=0;
        (n>0) && (ans = ans + quick_sum(a<<1,n>>1) );
        (n & 1) && (ans = ans + a);

        return ans;
    }
};