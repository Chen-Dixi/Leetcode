class Solution {
public:
    int strToInt(string str) {
        int res = 0;
        int i = 0;
        int flag = 1;
        // 1. 检查空格
        while (str[i] == ' ') { i++; }
        // 2. 检查符号
        if (str[i] == '-') { flag = -1; }
        if (str[i] == '+' || str[i] == '-') { i++; }
        // 3. 计算数字
        while (i < str.size() && isdigit(str[i])) {
            int r = str[i] - '0';
            // ------ 4. 处理溢出，这是关键步骤 ------
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7)) { 
                return flag > 0 ? INT_MAX : INT_MIN;
            }
            // ------------------------------------
            res = res * 10 + r;
            i++;
        }
        return flag > 0 ? res : -res;
    }
};

//之前也遇到过这个问题，超过 INT_MAX 该怎么做的问题
class Solution {
public:
    int strToInt(string str) {
        int res=0;
        int i=0;
        int flag=1;
        //检查空格
        while( str[i] == ' ' )  {i++};
        if(str[i] == '-'){flag=-1};
        if(str[i] == '+' || str[i] == '-') {i++;}
        //计算数字
        while(i<str.size() && isdigit(str[i])){
            int r = str[i] - '0';
            //溢出处理 记住溢出处理的操作 ( INT_MAX / 10 || (res == INT_MAX / 10 && r > 7))
            if( res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7)){
                return flag > 0 ? INT_MAX : INT_MIN;
            }
            //
            res = res*10 + r;
            i++;
        }
        return flag
    }
};