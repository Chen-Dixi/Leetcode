#include <cstdio>
#include <iostream>
class Solution {
public:
    void Print1ToMaxOfndigits(int n){
        if(n<=0)
            return;

        char * number = new char[n+1];

        number[n] = '\0';
        for(int i=0;i<10;i++)
        {
            number[0]=i+'0';
            Print1ToMaxOfNDigitsRecursively(number, n, 0);
        }

        delete [] number;
    }

    void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
    {
        if(index==length-1){
            //打印数字
            PrintNumber(number);
            return;
        }

        for(int i=0;i<10;i++){
            number[index+1]=i+'0';
            Print1ToMaxOfNDigitsRecursively(number, length,index+1);    
        }
    }
    void PrintNumber(char *number)
    {
        int index=0;
        int len = strlen(number);
        while(index<len && number[index]=='0')
            index++;
        while(index<len){
            printf("%c",number[index++]);
        }
        printf("\n");
    }
};

int main(){
    Solution sol = Solution();
    sol.Print1ToMaxOfndigits(2);
}

class Solution {
public:
    vector<int> res;
    vector<int> printNumbers(int n) {
        if(n <=0 ) return res;
        string number(n,'0');
        for(int i = 0;i <= 9;i++)
        {
            number[0] = i + '0';
            permutionNum(number, n, 1);
        }
        return res;
    }

    void permutionNum(string &number, int length, int index)
    {
        if(index == length)
        {
            saveNum(number);
            return;
        }else
        {
            for(int i=0;i<10;i++)
            {
                number[index] = '0' + i;
                permutionNum(number,length,index+1);
            }
        }
    }

    void saveNum(string number)
    {
        string tempStr(number.size(),'0');
        std::cout<< stoi(number) <<" ";
        if(number!=tempStr)
        res.push_back(stoi(number));
    }
};

class Solution {
public:
    vector<int> res;
    vector<int> printNumbers(int n) {
        //全排列
        string number(n,'0');

        for(int i=0;i<=9;i++){
            number[0]=i+'0';
            permutionNum(number, n, 1);
        }
        return ans;
    }

    void permutionNum(string &number, int length, int index)
    {
        if(index==length){
            saveNum(number);
            return;
        }
        for(int i=0;i<=9;i++)
        {
            number[index]=i+'0';
            permutionNum(number, length, index+1);
        }
    }

    void saveNum(string number)
    {
        //第一个0000不能放进去考虑
        int ans = stoi(number);
        if(ans!=0)
            res.push_back(stoi(number));//stoi直接使用
    }
};
