class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.isEmpty()) {
            return 0;
        }
        char[] h = haystack.toCharArray();
        char[] n = needle.toCharArray();
        int lenH = h.length, lenN = n.length;
        if (lenN > lenH) {
            return -1;
        }
        // 主串的下标。
        int i = 0;
        // 搜索串的下标。
        int j = 0;
        // 定义 next 数组，存储 n[j] 前不必重复匹配的最大长度。
        int[] next = getNext(needle);
        // 主串不够用或者搜索串匹配完成则跳出循环。
        while (i < lenH && j < lenN) {
            if (j == -1 || h[i] == n[j]) {
                // 当从头开始匹配搜索串或者当前位置匹配继续下一个位置。
                i++;
                j++;
            } else {
                // 出现不匹配字符则从最大可复用部分的下一个位置开始比较。
                j = next[j];
            }
        }
        // 搜索串的每一位都能匹配成功，则返回匹配的起始位置。
        if (j == lenN) {
            return i - j;
        } else {
            return -1;
        }
    }

    private int[] getNext(String needle) {
        char[] n = needle.toCharArray();
        // 定义 next 数组，存储 n[j] 前不必重复匹配的最大长度。
        int[] next = new int[n.length];
        // 数组第一位设为 -1 ，方便判断当前位置是否为搜索串的最开始。
        next[0] = -1;
        // 搜索串的下标。
        int j = 0;
        // 搜索串匹配的位置。
        int k = -1;
        // 从第二个位置开始计算搜索串每个位置之前不必重复匹配的最大长度。
        while (j < n.length - 1) {
            // 当从头开始匹配搜索串或者当前位置匹配继续下一个位置。
            if (k == -1 || n[j] == n[k]) {
                // 当前位置 j 之前不必重复匹配的最大长度为 k 。
                next[++j] = ++k;
            } else {
                // 回溯直到找到与 j 位置匹配的 k 或者从头开始匹配下一个字符。
                k = next[k];
            }
        }
        return next;
    }
}

作者：iceblood
链接：https://leetcode-cn.com/problems/implement-strstr/solution/28ti-shi-xian-strstr-by-iceblood/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
    public int strStr(String haystack, String needle) {
        if (needle==null||haystack==null||needle.length()<=0) {
            return 0;
        }
        char[] haychar = haystack.toCharArray();
        char[] needchar = needle.toCharArray();
        int hayindex = 0;
        int needindex = 0;
        int[] next = getNextArray(needchar);
        while (hayindex < haychar.length && needindex < needchar.length) {
            if (haychar[hayindex] == needchar[needindex]) {
                hayindex++;
                needindex++;
            } else if (next[needindex] == -1) {
                hayindex++;
            } else {
                needindex = next[needindex];
            }
        }
        return needindex == needchar.length ? hayindex - needindex : -1;
    }

    public static int[] getNextArray(char[] ms) {
        if (ms.length == 1) {
            return new int[] { -1 };
        }
        int[] next = new int[ms.length];
        next[0] = -1;
        next[1] = 0;
        int pos = 2;
        int cn = 0;
        while (pos < next.length) {
            if (ms[pos - 1] == ms[cn]) {
                next[pos++] = ++cn;
            } else if (cn > 0) {
                cn = next[cn];
            } else {
                next[pos++] = 0;
            }
        }
        return next;
    }
}
————————————————
版权声明：本文为CSDN博主「AaronLin_」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_35159818/article/details/84112727