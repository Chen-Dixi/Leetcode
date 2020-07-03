//循环写法
class Solution {
public:
    int add(int a, int b) {
        int sum,carry;
        do{
            sum = a^b;
            carry = ((unsigned int)(a & b)<<1);//注意-号
            
            a=sum;b=carry;
        }while(b!=0); 

        return a;
    }
};
//递归写法
class Solution {
public:
    int add(int a, int b) {
        if(b==0)
            return a;

        int sum=a^b;
        int carry=((unsigned int) (a & b) << 1);
        


        return add(sum,carry);
    }
};