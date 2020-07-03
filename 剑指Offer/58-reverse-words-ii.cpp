//先把第一部分 和剩余字符串分别旋转，然后反转整个字符串
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        if(n>=s.size())
            return s;

        reverse(s,0,n-1);
        reverse(s,n,s.size()-1);

        reverse(s,0,s.size()-1);
    }

    void reverse(string &s, int i, int j){
        while(i<=j){
            swap(s[i++],s[j--]);
        }
    }
};