class Solution {
    public boolean patternMatching(String pattern, String value) {
        String s[]=new String[2];
        return solve(s,pattern,0,value,0);
    }
    /**
     * 回溯遍历设置a,b的对应值，尝试每一种可能。
     * @param s   s[0]=a对应的字符串 s[1]=b对应的字符串
     * @param pattern 模式串
     * @param index1 模式串匹配位置
     * @param value 匹配串（待匹配的字符串）
     * @param index2 匹配串匹配位置
     * @return
     */
    public boolean solve(String []s,String pattern,int index1,String value,int index2){
        //匹配完成
        if(index1==pattern.length()&&index2==value.length()) return true;
        //注意匹配串匹配位置等于长度的时候也可以继续匹配，因为模式串的a，b可以匹配空串。
        if(index1>=pattern.length()||index2>value.length()) return false;
        int num=pattern.charAt(index1)-'a';
        if(s[num]==null){
            //从当前尝试a或b对应的字符串的每一种可能
            for(int i=index2;i<=value.length();i++){
                s[num]=value.substring(index2,i);
                //(!s[num].equals(s[num^1]))  [是指a，b对应的字符串不可相等]
                if(!s[num].equals(s[num^1])&&solve(s,pattern,index1+1,value,i)) return true;
            }
            //失配时应将设置过的对应字符串为空
            s[num]=null;
            return false;
        }else{
            //若此前a或b已有对应的字符串匹配了，则查看当前位置时候能够匹配上。
            int end=index2+s[num].length();
            if(end> value.length()||!value.substring(index2,end).equals(s[num])) return false;
            return solve(s,pattern,index1+1,value,end);
        }
    }
}