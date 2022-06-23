//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

#include "apiheader.h"

using namespace std;

#define NONE "\033[m"
#define RED  "\033[0;32;31m"
#define CYAN "\033[0;36m"

#define DEBUG 1
#define _CPPVERSION_

#if DEBUG
#define LOGD(...) {printf(CYAN "[D] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#define LOGE(...) {printf(RED "[E] %s(%d): " NONE, __FUNCTION__, __LINE__);printf( __VA_ARGS__);}
#else
#define LOGD(...)
#define LOGE(...)
#endif

//
// MAP Ref:
// https://mropengate.blogspot.com/2015/12/cc-map-stl.html
//
// Unorder Map:
// https://shengyu7697.github.io/std-unordered_map/
// https://www.sczyh30.com/posts/C-C/cpp-stl-hashmap/
//

/*
https://leetcode.com/problems/lru-cache/
146. LRU Cache

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

1. LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
2. int get(int key) Return the value of the key if the key exists, otherwise return -1.
3. void put(int key, int value) Update the value of the key if the key exists. Otherwise, 
add the key-value pair to the cache. If the number of keys exceeds the capacity from this 
operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.

Example 1:

Input
["LRUCache", "put", "put",  "get", "put", "get", "put", "get", "get", "get"]
[[2],        [1, 1],[2, 2],  [1],  [3, 3], [2],  [4, 4], [1],  [3],   [4]]
Output
[null,        null,  null,   1,     null,   -1,   null,  -1,    3,     4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

Constraints:

1 <= capacity <= 3000
0 <= key <= 10^4
0 <= value <= 10^5
At most 2 * 10^5 calls will be made to get and put.

*/


#ifdef _CVERSION_
//C
/*

*/

typedef struct {
    
} LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
    
}

int lRUCacheGet(LRUCache* obj, int key) {
  
}

void lRUCachePut(LRUCache* obj, int key, int value) {
  
}

void lRUCacheFree(LRUCache* obj) {
    
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/


void Test_AM_LRUCache()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*

*/
#if 0 //NG
class LRUCache {
public:
    unordered_map<int, int>dataMap; //Key,  Value
    unordered_map<int, int>timeMap; //Time, Key
    unordered_map<int, int>KeyTimeMap; //Key, Time    
    priority_queue<int, vector<int>, greater<int> >pq; //Time    
    int mSize;
    int utcIdx;

    LRUCache(int capacity) {
        mSize = capacity;
        utcIdx = 0;
    }
    
    int get(int key) {
        LOGD("Get Key: %d\n", key);
        for (const auto& n : dataMap) {
            std::cout << "Key: " << n.first << ", Value: " << n.second << "\n";
        }
        unordered_map<int, int>::iterator iterData;
        unordered_map<int, int>::iterator iterKeyTime;
        if((iterData = dataMap.find(key)) != dataMap.end()) {
            iterKeyTime = KeyTimeMap.find(key);
            timeMap[iterKeyTime->second] = utcIdx;
            KeyTimeMap[key] = utcIdx;
            utcIdx++;
            return iterData->second;
        }        
        return -1;
    }
    
    void put(int key, int value) {
        unordered_map<int, int>::iterator iterData;
        unordered_map<int, int>::iterator iterTime;
        unordered_map<int, int>::iterator iterKeyTime;        
        
        //Get UTC
        int utc = utcIdx;
        utcIdx++;
        if(dataMap.size()<mSize) {
            dataMap[key] = value;
            timeMap[utc] = key;
            KeyTimeMap[key] = utc;
            pq.push(utc);
            return;
        }
        
        //Remove the oldest slot        
        if((iterData = dataMap.find(key)) == dataMap.end()) {
            int oldUtc;
            while(!pq.empty()){            
                oldUtc = pq.top();
                pq.pop();
            
                //Remove the slot
                iterTime = timeMap.find(oldUtc);            
                if((iterData = dataMap.find(iterTime->second)) != dataMap.end()) {
                    dataMap.erase(iterData);
                    timeMap.erase(iterTime);
                    break;
                }
                timeMap.erase(iterTime);
            }
        }
        
        //Insert the key & value
        dataMap[key] = value;
        timeMap[utc] = key;
        KeyTimeMap[key] = utc;
        pq.push(utc);
    }
};

#endif //NG

/*
Ref Solution:  Double Linked list + hashmap
Runtime: 736 ms, faster than 26.41% of C++ online submissions for LRU Cache.
Memory Usage: 165.2 MB, less than 71.09% of C++ online submissions for LRU Cache.
*/
typedef struct DLinkNode_T{
    int key;
    int value;
    struct DLinkNode_T* prev;
    struct DLinkNode_T* next;
    DLinkNode_T():prev(NULL), next(NULL){}
    DLinkNode_T(int k, int v): key(k), value(v), prev(NULL), next(NULL) {}
}DLinkNode;

class LRUCache {
private:
    DLinkNode* head;
    DLinkNode* tail;
    int mSize;
    int mCapacity;
    unordered_map<int, DLinkNode*> umap;
    
    void addNode(DLinkNode* node) {
        node->prev = head;
        node->next = head->next;
        
        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(DLinkNode* node) {
        DLinkNode* prev = node->prev;
        DLinkNode* next = node->next;
        
        prev->next = next;
        next->prev = prev;
    }
    
    void moveToHead(DLinkNode* node) {
        removeNode(node);
        addNode(node);
    }
    
    DLinkNode* popTail() {
        DLinkNode* res = tail->prev;
        removeNode(res);
        return res;
    }
    
public:
    ~LRUCache() {
        delete head;
        delete tail;
    }
    
    LRUCache(int capacity) {
        mSize = 0;
        mCapacity = capacity;
        head = new DLinkNode();
        tail = new DLinkNode();
        head->next = tail;
        tail->prev = head;        
    }
    
    int get(int key) {
        unordered_map<int, DLinkNode*>::iterator it;
        if((it = umap.find(key)) != umap.end()) {
            DLinkNode* node = it->second;
            moveToHead(node);
            return node->value;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        DLinkNode* node;
        unordered_map<int, DLinkNode*>::iterator it;
        
        if((it = umap.find(key)) != umap.end()) {
            DLinkNode* node = it->second;
            node->value = value;
            moveToHead(node);
        }
        else {
            DLinkNode* newNode = new DLinkNode(key,value);
            umap[key] = newNode;
            addNode(newNode);
            ++mSize;
            
            if(mSize > mCapacity) {
                DLinkNode* oldTail = popTail();
                it = umap.find(oldTail->key);
                umap.erase(it);
                --mSize;
                delete oldTail;
            }
        }
    }

};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

void Test_AM_LRUCache()
{
    LOGD("[CPP] %s\n", __TIME__);

    int val;
    LRUCache *lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // cache is {1=1}
    lRUCache->put(2, 2); // cache is {1=1, 2=2}
    val = lRUCache->get(1);    // return 1
    LOGD("Exp: 1, Val: %d\n", val);
    lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    val = lRUCache->get(2);    // returns -1 (not found)
    LOGD("Exp: -1, Val: %d\n", val);       
    lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    val = lRUCache->get(1);    // return -1 (not found)
    LOGD("Exp: -1, Val: %d\n", val);
    val = lRUCache->get(3);    // return 3
    LOGD("Exp: 3, Val: %d\n", val);
    val = lRUCache->get(4);    // return 4    
    LOGD("Exp: 4, Val: %d\n", val);
    delete lRUCache;
}

#endif// _CPPVERSION_