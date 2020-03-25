//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <math.h>
#include <time.h>

#include "apiheader.h"

using namespace std;

#define NONE "\033[m"
#define RED  "\033[0;32;31m"
#define CYAN "\033[0;36m"

#define DEBUG 1
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

/*
https://leetcode.com/problems/insert-delete-getrandom-o1/
380. Insert Delete GetRandom O(1)

Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();
*/

class RandomizedSet {
public:
    map<int, int> mapRecord;
    map<int, int>::iterator iter;
    vector<int> mDataArray;
    int mSize;
    unsigned seed;
    
    /** Initialize your data structure here. */
    RandomizedSet() {
        mSize = 0;
        seed = (unsigned)time(NULL);
        srand(seed);
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        iter = mapRecord.find(val);
        if(iter == mapRecord.end()) {
            mapRecord[val] = mSize;
            mDataArray.push_back(val);
            mSize++;
            return true;
        }

        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        iter = mapRecord.find(val);
        if(iter == mapRecord.end()) {
            return false;
        }
        mSize--;
        int target_idx = iter->second;
        int lastItem_idx = mSize;
        int lastItem_val = mDataArray[lastItem_idx];        

        mDataArray[target_idx] = lastItem_val;
        mDataArray.pop_back();
        mapRecord.erase(iter);
        iter = mapRecord.find(lastItem_val);
        iter->second = target_idx;

        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx;
        idx=(rand()%mSize);
        return mDataArray[idx];
    }
};

void Test_InsertDeleteGetRandom()
{
    LOGD("%s\n", __TIME__);
    RandomizedSet *xRandomizedSet = new RandomizedSet();
    int val = 10;
    LOGD("Insert Val: %d, Result: %d\n", val, xRandomizedSet->insert(val));
    LOGD("Insert Val: %d, Result: %d\n", val, xRandomizedSet->insert(val));
    val = 5;
    LOGD("Insert Val: %d, Result: %d\n", val, xRandomizedSet->insert(val));
    val = 6;
    LOGD("Insert Val: %d, Result: %d\n", val, xRandomizedSet->insert(val));
    val = 7;
    LOGD("Insert Val: %d, Result: %d\n", val, xRandomizedSet->insert(val));
    val = 8;
    LOGD("Insert Val: %d, Result: %d\n", val, xRandomizedSet->insert(val));    
    val = 6;
    LOGD("Remove Val: %d, Result: %d\n", val, xRandomizedSet->remove(val));
    
    LOGD("Random Val: %d, \n", xRandomizedSet->getRandom());
    LOGD("Random Val: %d, \n", xRandomizedSet->getRandom());
    LOGD("Random Val: %d, \n", xRandomizedSet->getRandom());
    LOGD("Random Val: %d, \n", xRandomizedSet->getRandom());
    LOGD("Random Val: %d, \n", xRandomizedSet->getRandom());
    delete xRandomizedSet;
}