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