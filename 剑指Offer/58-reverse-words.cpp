//这个代码是
class Solution {
public:
    //空格，两边不能留
    //先翻转每个单词，再反转整个字符串
    string reverseWords(string s) {
        //翻转字符串
        int len=s.size();
        if(len<=0)
            return "";

        //除去空格
        int start = 0, end=s.size()-1;
        while(end>=0&&s[end]==' ')
            end--;
        while(start<len&&s[start]==' ')
            start++;
        //处理“ ”这个异常输入
        if(start>end)
            return "";
        s = s.substr(start,end-start+1);
        len = s.size();

        //反转每个单词
        int i=0,j=0;
        while(j<=len){
            if(j==len||s[j]==' '){
                reverseWord(s, i,j-1);
                i=j+1;
            }
            j++;
        }

        reverseWord(s, 0,len-1);
        //删除多余空格
        int space=0;
        for(string::iterator it=s.begin();it!=s.end();it++){
            if(*it==' '){
                if(space>0){
                    string::iterator next = s.erase(it);
                    it = next-1;
                }else{
                    space++;
                }
            }else{
                space=0;
            }
        }
        return s;
    }

    void reverseWord(string &s, int i, int j)//反转一个单词
    {
        

        while(i<j){
            swap(s[i],s[j]);
            i++;j--;
        }  
    }
};