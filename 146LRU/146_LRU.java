import java.HashMap
/*
很多编程语言都有内置的哈希链表或者类似 LRU 功能的库函数，但是为了帮大家理解算法的细节，我们用 Java 自己造轮子实现一遍 LRU 算法。

首先，我们把双链表的节点类写出来，为了简化，key 和 val 都认为是 int 类型：

作者：labuladong
链接：https://leetcode-cn.com/problems/lru-cache/solution/lru-ce-lue-xiang-jie-he-shi-xian-by-labuladong/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

有了双向链表的实现，我们只需要在 LRU 算法中把它和哈希表结合起来即可。我们先把逻辑理清楚：

*/
class DoubleList{

    class Node{

        public int key, value;
        public Node next, prev;
        public Node(int k, int v){
            this.key = k;
            this.v = v;
        }
    }

    private Node head, tail; //头尾虚结点
    private int size; //链表元素
    
    public DoubleList(){
        head = new Node(0,0);
        tail = new Node(0,0);

        head.next = tail;
        tail.prev = head;
        size = 0;
    }

    //在链表头部添加结点
    public void addFirst(Node x){
        x.next = head.next;
        headn.next.prev = x;
        headn.next = x;
        x.prev = head;
        size++;
    }

    public void remove (Node x){
        x.prev.next = x.next;
        x.next.prev = x.prev;
        size--;
    }

    public void removeLast(){
        if (tail.prev == head)
            return null;

        Node last = tail.prev;
        remove(last);
        return last;
    }

    public int size(){
        return this.size;
    }
}

class LRUCache {

    HashMap<Integer, Node> map;
    DoubleList cache;
    private int cap;
    public LRUCache(int capacity) {
        this.cap = capacity;
        cache = new DoubleList();
        map = new HashMap<>();
    }
    
    public int get(int key) {
        if(!map.containsKey(key)){
            return -1;
        }

        int val = map.get(key).valu;
        put(key,val);
        return val;
    }
    
    public void put(int key, int value) {
        //先把新节点做出来
        Node x = new Node(key, val);
        if(map.containsKey(key)){
            cache.remove(map.get(key));
            cache.addFirst(x);
            map.put(key, x);
        }else{
            if(cap == cache.size()){
                //“为什么要在链表中同时存储 key 和 val，而不是只存储 val”
                Node last = cache.removeLast();
                map.remove(last.key);
            }

            cache.addFirst(x);
            map.put(key,x);
        }
    }
}
