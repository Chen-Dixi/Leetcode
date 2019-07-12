class Solution {
public:
    int calculate(string s) {
        int num=0;
        int ans=0;
        stack<int> signs;
        int sign=1;
        
        signs.push(1);
        
        for(auto c:s){
            if (c<='9' && c>= '0'){
                num = num*10+c-'0';
            }else if(c=='('){
                signs.push(sign*signs.top());
                sign=1;
            }else if(c==')'){
                ans = ans + sign*signs.top()*num;
                signs.pop();
                num=0;
                sign=1;
            }else if(c=='+' || c=='-'){
                ans = ans + signs.top()*sign*num;
                num=0;
                sign = (c == '-') ? -1:1;
            }
        }
        if (num>0){
            ans = ans + signs.top()*sign*num;
        }
        return ans;
    }
};
