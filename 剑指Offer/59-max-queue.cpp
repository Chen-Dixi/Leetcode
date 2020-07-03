class MaxQueue {
private:
    deque<int> maxqueue;
    deque<int> que;
public:
    MaxQueue() {

    }
    
    int max_value() {
        //要判定-1
        if(maxqueue.empty())
            return -1;
        return maxqueue.front();
    }
    
    void push_back(int value) {
        que.push_back(value);
        //一个最大队列存储
        while(!maxqueue.empty() && maxqueue.back()<value) maxqueue.pop_back();
        maxqueue.push_back(value);

    }
    
    int pop_front() {
        if(que.empty())
            return -1;
        int value = que.front();
        que.pop_front();
        if(maxqueue.front()==value)
            maxqueue.pop_front();
        return value;
    }
};


/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

//两种队列
class MaxQueue {
    queue<int> q;
    deque<int> d;
public:
    MaxQueue() {
    }
    
    int max_value() {
        if (d.empty())
            return -1;
        return d.front();
    }
    
    void push_back(int value) {
        while (!d.empty() && d.back() < value) {
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if (q.empty())
            return -1;
        int ans = q.front();
        if (ans == d.front()) {
            d.pop_front();
        }
        q.pop();
        return ans;
    }
};

