class Solution {
public:
    //思路，n有<0的情况，用while循环代替递归。
    //
    double myPow(double x, int n) {
        //x的n次方
        if(n==0)
            return 1;
        if(n==1)
            return x;

        long b = n;
        if(b<0){
            b=-b;
            x = 1/x;
        }

        double res = 1.0;
        while(b>0){
            if(b & 1==1){
                res = res*x;
            }
            x *= x;
            b>>=1;
        }
        
        return res;
    }
};

class Solution {
public:
    //思路，n有<0的情况，用while循环代替递归。
    //
    double myPow(double x, int n) {
        //x的n次方
        if(n==0)
            return 1;
        if(n==1)
            return x;

        long b = n;
        if(b<0){
            b=-b;
            x = 1/x;
        }
        double res = longpow(x,b);
        return res;
    }

    double longpow(double x, long n){
        if(n==0)
            return 1;
        if (n==1)
            return x;

        double tmp = longpow(x, n>>1);
        tmp*=tmp;
        if(n&1==1){
            tmp*=x;
        }
        return tmp;
    }
};