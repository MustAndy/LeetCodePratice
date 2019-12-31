/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (26.80%)
 * Likes:    3458
 * Dislikes: 135
 * Total Accepted:    340.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * The cache is initialized with a positive capacity.
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * 
 * LRUCache cache = new LRUCache( 2  capacity 
**cache.put(1, 1);
*cache.put(2, 2);
*cache.get(1);    // returns 1
*cache.put(3, 3); // evicts key 2
*cache.get(2);    // returns -1 (not found)
*cache.put(4, 4); // evicts key 1
*cache.get(1);    // returns -1 (not found)
*cache.get(3);    // returns 3
*cache.get(4);    // returns 4
*****/
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
class LRUCache
{
public:
    LRUCache(int capacity)
    {
        this->LRUcapacity = capacity;
    }

    int get(int key)
    {
        int result(-1);
        if (this->CacheHashMap.count(key))
        {
            result = this->CacheHashMap[key]->value;
            this->CacheList.splice(this->CacheList.begin(), this->CacheList, this->CacheHashMap[key]);
            this->CacheHashMap[key] = this->CacheList.begin();
        }
        return result;
    }

    void put(int key, int value)
    {
        if (this->CacheHashMap.count(key))
        {
            this->CacheHashMap[key]->value = value;
            this->CacheList.splice(this->CacheList.begin(), this->CacheList, this->CacheHashMap[key]);
            this->CacheHashMap[key] = this->CacheList.begin();
        }
        else
        {
            if (this->CacheList.size() >= this->LRUcapacity)
            {
                this->CacheHashMap.erase(this->CacheList.back().key);
                this->CacheList.pop_back();
            }
            this->CacheList.push_front(CacheNode(key, value));
            this->CacheHashMap[key] = this->CacheList.begin();
        }
    }

private:
    struct CacheNode
    {
        int key;
        int value;
        CacheNode(const int &k, const int &v) : key(k), value(v) {}
    };
    list<CacheNode> CacheList;
    unordered_map<int, list<CacheNode>::iterator> CacheHashMap;
    int LRUcapacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
