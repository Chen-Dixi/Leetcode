#include <bits/stdc++.h>

class LRUCache {
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end())
        {
            int value = mp[key]->second;
            lt.splice(lt.begin(), lt, mp[key]);
            return value;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end())
        {
            mp[key]->second = value;
            get(key);
        }
        else
        {
            lt.emplace_front(key,value);
            mp[key] = lt.begin();
            if (lt.size() > size)
            {
                mp.erase(lt.back().first);
                lt.pop_back();

            }
        }
    }
private:
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int,int>> lt;
    int size;
};

//双向链表，+hash
/*
C++ 可以利用迭代器更方便实现 LRU 算法
*/
//1. put：在key存在的时候，从list去掉原来的，插入新的，更新map；key没存在的时候，如果容量满了，从list最后面删掉，获取pair里面的key，更新map.erase(key)，然后插入新的，更新map。
//2. get：key存在的时候，从list里面放到最前面，更新map对应key的位置map[key]=list.begin();
class LRUCache{
private:
    list<pair<int,int> > cache;
    unordered_map<int, list<pair<int, int> >::iterator> map;
    int cap;

public:
    LRUCache(int capacity){
        this->cap = capacity;
    }

    int get(int key){
        if(map.find(key)!=map.end()){//找到了
            pair<int,int> kv = *map[key];
            cache.erase(map[key]);//erase里面放的是iterator
            cache.push_front(kv);
            map[key] = cache.begin();

            return kv.second;
        }else{
            return -1;
        }

    }

    void put(int key, int val){
        if(map.find(key)!=map.end()){//找到了
            
            cache.erase(map[key]);//erase里面放的是iterator
            cache.push_front(make_pair(key,val));
            map[key] = cache.begin();

        }else{
            if(this->cap == cache.size()){//满了
                pair<int,int> lastkv = cache.back();
                int lastKey = lastkv.first; //这就是为什么链表要存储key
                cache.pop_back();
                map.erase(lastKey);
            }

            cache.push_front(make_pair(key,val));
            map[key] = cache.begin();
        }
    }

};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

