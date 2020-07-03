class Solution {
    int ptr;
    public String decodeString(String s) {
        LinkedList<String> stk = new LinkedList<String>();
        ptr = 0;

        while(ptr < s.length()){
            char cur = s.charAt(ptr);

            if(Character.isDigit(cur)){ //是数字
                String digits = getDigits(s);
                stk.addLast(digits);
            }else if (Character.isLetter(cur) || cur == '[') { //是字符和左括号
                // 获取一个字母并进栈
                stk.addLast(String.valueOf(s.charAt(ptr++))); 
            }else{  //右括号，要开始出栈了
                ++ptr;
                LinkedList<String> sub = new LinkedList<String>();
                while(!"[".equals(stk.peekLast())){
                    sub.addLast(stk.removeLast());
                }
                Collections.reverse(sub);
                stk.removeLast();
                int repTime = Integer.parseInt(stk.removeLast());
                StringBuffer t = new StringBuffer();
                String o = getString(sub);
                while(repTime-- > 0){
                    t.append(o);
                }
                stk.addLast(t.toString());
            }
        }

        return getString(stk);
    }

    private String getDigits(String s){
        StringBuffer ret = new StringBuffer();
        while(Character.isDigit(s.charAt(ptr))){
            ret.append(s.charAt(ptr++));
        }
        return ret.toString();
    }

    public String getString(LinkedList<String> v) {
        StringBuffer ret = new StringBuffer();
        for (String s : v) {
            ret.append(s);
        }
        return ret.toString();
    }
}