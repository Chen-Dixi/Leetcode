class Solution {

    public boolean wordBreak(String s, List<String> wordDict) {
        if("".equals(s))
            return true;
        for(int i = 1; i <= s.length; i++){
            String str = s.substring(0,i);
            if(wordDict.contains(str) && wordBreak(str.substring(i), wordDict))
                return true;
        }

        return false;
    }

    public boolean help(String, List<String> wordDict){
        if("".equals(s))
            return true;
        for(int i = 1; i <= s.length; i++){
            String str = s.substring(0,i);
            if(wordDict.contains(str) && wordBreak(str.substring(i), wordDict))
        }

        return false;   
    }

}

class Solution {

    public boolean wordBreak(String s, List<String> wordDict) {
        return help(s, wordDict, new Boolean[s.length()], 0);
    }

    public boolean help(String s, List<String> wordDict, Boolean [] memo, int start){
        
        if(start==s.length())
            return true;

        if(memo[start]!=null)//true和false都保存
            return memo[start];

        for(int i = start; i < s.length(); i++){
            String str = s.substring(start,i+1);
            if(wordDict.contains(str) && help(s, wordDict, memo, i+1)){
                return memo[start]=true;
            }
        }

        return memo[start] = false;   
    }

}