class Solution {
public:
    int fib(int n) {
        int pre = 0;
        int cur = 1;
        if(n==0)
            return pre;
        if(n==1)
            return cur;
        
        while(n>1){
            int temp = (cur+pre)%1000000007;
            pre = cur;
            cur = temp;
            n--;
        }

        return cur%1000000007;
    }
};
