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
    string addStrings(string num1, string num2) {
        
        //num1,num2
        string res = "";
        int p1 = num1.size()-1;
        int p2 = num2.size()-1;

        int carry = 0;

        while (p1>=0 || p2 >= 0){
            int n1=0,n2=0;

            if (p1>=0)
                n1 = num1[p1]-'0';
            else
                n1 = 0;

            if (p2>=0)
                n2 = num2[p2]-'0';
            else
                n2 = 0;

            p1--;p2--;
            int tmp = n1+n2+carry;
            carry = tmp / 10;
            char c = tmp%10 + '0';

            res.insert(0,1,c);
        }
        if (carry==1)
            res.insert(0,1,'1');
        
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    
    cout<<solution.addStrings("51189","967895");
    
}