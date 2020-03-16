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
    string multiply(string num1, string num2) {
        //
        if(num1=="0" || num2=="0")
            return "0";

        string ans = "0";

        int len1 = num1.size();
        int len2 = num2.size();



        for(int i=len2-1; i>=0; i--){
            int b = num2[i]-'0';

            int a = 0;
            int j=len1-1;
            int carry=0;
            if(b==0)
                continue;
            string s="";
            while(j>=0){
                a = num1[j]-'0';
                int tmp=a*b+carry;
                char c = tmp%10+'0';
                s.insert(0,1,c);
                carry = tmp/10;
                j--;
            }
            if(carry>0){
                char c = carry+'0';
                s.insert(0,1,c);
            }

            for(int k=i;k<len2-1;k++){
                s.push_back('0');
            }

            ans = addString(ans, s);

        }

        return ans;
            
        

        
    }

    string addString(string num1, string num2){

        int carry=0;
        string ans="";

        int len1 = num1.size();
        int len2 = num2.size();

        int i=len1-1, j=len2-1;
        int a=0;
        int b=0;
        int tmp=0;
        while(i>=0 || j>=0){
            
            if(i>=0){
                a=num1[i]-'0';
                i--;
            }else{
                a=0;
            }

            if(j>=0){
                b=num2[j]-'0';
                j--;
            }else{
                b=0;
            }

            tmp = (a+b+carry);
            char c = tmp%10+'0';
            ans.insert(0,1,c);

            carry = (tmp)/10;
        }

        if(carry==1)
            ans.insert(0,1,'1');

        return ans;
    }
};

int main(){
    Solution sol = Solution();
    string num1="123", num2="456";
    cout<<sol.multiply(num1, num2)<<endl;

}