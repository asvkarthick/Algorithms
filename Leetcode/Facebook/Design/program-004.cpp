/* Problem: LRU Cache
 * Weblink: https://leetcode.com/explore/interview/card/facebook/56/design-3/311/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class LRUCache {
public:
    LRUCache(int capacity) : mCapacity(capacity) {

    }

    int get(int key) {
        if (mKeyValue.find(key) == mKeyValue.end()) return -1;
        mList.erase(mKeyIteratorMap[key]);
        mList.push_front(key);
        mKeyIteratorMap[key] = mList.begin();
        return mKeyValue[key];
    }

    void put(int key, int value) {
        if (mKeyValue.find(key) == mKeyValue.end()) { // Not present case
            mList.push_front(key);
            if (mList.size() > mCapacity) {
                int k = mList.back();
                mList.pop_back();
                auto it1 = mKeyValue.find(k);
                mKeyValue.erase(it1);
                auto it2 = mKeyIteratorMap.find(k);
                mKeyIteratorMap.erase(it2);
            }
            mKeyValue[key] = value;
            mKeyIteratorMap[key] = mList.begin();
        } else {
            mList.erase(mKeyIteratorMap[key]);
            mList.push_front(key);
            mKeyValue[key] = value;
            mKeyIteratorMap[key] = mList.begin();
        }
    }

private:
    int mCapacity;
    std::unordered_map<int, int> mKeyValue;
    std::unordered_map<int, std::list<int>::iterator> mKeyIteratorMap;
    std::list<int> mList;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
