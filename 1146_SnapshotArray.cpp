//g++ *.cpp -o tool

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>


#include "apiheader.h"

using namespace std;

#define NONE "\033[m"
#define RED  "\033[0;32;31m"
#define CYAN "\033[0;36m"

#define _CPPVERSION_

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
// Set Ref:
// https://shengyu7697.github.io/std-unordered_set/
//
// Priority Queue:
// https://yuihuang.com/cpp-stl-priority-queue/
//

/*
https://leetcode.com/problems/snapshot-array/
1146. Snapshot Array

Implement a SnapshotArray that supports the following interface:

SnapshotArray(int length) initializes an array-like data structure with the given length. Initially,
each element equals 0.
void set(index, val) sets the element at the given index to be equal to val.
int snap() takes a snapshot of the array and returns the snap_id: the total number of times we 
called snap() minus 1.
int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with 
the given snap_id
 

Example 1:

Input: ["SnapshotArray","set","snap","set","get"]
[[3],[0,5],[],[0,6],[0,0]]
Output: [null,null,0,null,5]
Explanation: 
SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
snapshotArr.set(0,5);  // Set array[0] = 5
snapshotArr.snap();  // Take a snapshot, return snap_id = 0
snapshotArr.set(0,6);
snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return 5

Constraints:

1 <= length <= 5 * 10^4
0 <= index < length
0 <= val <= 10^9
0 <= snap_id < (the total number of times we call snap())
At most 5 * 10^4 calls will be made to set, snap, and get.

*/
#ifdef _CVERSION_
//C
/*

*/
typedef struct {
    
} SnapshotArray;


SnapshotArray* snapshotArrayCreate(int length) {
    
}

void snapshotArraySet(SnapshotArray* obj, int index, int val) {
  
}

int snapshotArraySnap(SnapshotArray* obj) {
  
}

int snapshotArrayGet(SnapshotArray* obj, int index, int snap_id) {
  
}

void snapshotArrayFree(SnapshotArray* obj) {
    
}

/**
 * Your SnapshotArray struct will be instantiated and called as such:
 * SnapshotArray* obj = snapshotArrayCreate(length);
 * snapshotArraySet(obj, index, val);
 
 * int param_2 = snapshotArraySnap(obj);
 
 * int param_3 = snapshotArrayGet(obj, index, snap_id);
 
 * snapshotArrayFree(obj);
*/

void Test_GG_SnapshotArray()
{
    LOGD("[C] %s\n", __TIME__);
}

#endif// _CVERSION_

#ifdef _CPPVERSION_
//C++
/*
Ref Solution,
Runtime
244 ms
Beats
93.81%
*/
class SnapshotArray {
private:
    int cur_snap = 0;
    unordered_map<int, map<int, int>> a;
public:
    SnapshotArray(int length) {
    }

    void set(int index, int val) {
        a[index][cur_snap] = val; 
    }
    
    int snap() {
        return cur_snap++;
    }
    
    int get(int index, int snap_id) {
        auto it = a[index].upper_bound(snap_id);
        return it == begin(a[index]) ? 0 : prev(it)->second;
    }
};

#if 0
/*
Self
Time Limit Exceeded
*/
class SnapshotArray {
private:
    int mCount;
    int mLength;
    vector<int> mArray;
    unordered_map<int, vector<int> > mMap;

public:
    SnapshotArray(int length) {
        mCount = 0;
        mLength = length;
        mArray = vector<int>(length);
    }

    void set(int index, int val) {
        if(index < mLength) {
            mArray[index] = val;
        }
    }
    
    int snap() {
        mMap[mCount] = mArray;
        return mCount++;
    }
    
    int get(int index, int snap_id) {
        return mMap[snap_id][index];
    }
};
#endif

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
 
void Test_GG_SnapshotArray()
{
    LOGD("[CPP] %s\n", __TIME__);    
    SnapshotArray *solution = new SnapshotArray(3);
    int ans = solution->snap();
    LOGD("Ans: %d\n", ans);
    delete solution;    
}

#endif //_CPPVERSION_
