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
                int lastKey = laskkv.first; //这就是为什么链表要存储key
                cache.pop_back();
                map.erase(lastkey);
            }

            cache.push_front(make_pair(key,val));
            map[key] = cache.begin();
        }
    }

}

