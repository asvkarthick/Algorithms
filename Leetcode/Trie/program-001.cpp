/* Problem: Implement Trie
 * Weblink: https://leetcode.com/problems/implement-trie-prefix-tree/submissions/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Trie {
public:
    Trie() : isEnd(false) {
    }

    void insert(string word) {
        int len = word.length();
        Trie *t = this;
        for (int i = 0; i < len; i++) {
            char ch = word[i];
            if (t->hashMap.find(ch) == t->hashMap.end()) {
                t->hashMap[ch] = new Trie();
            }
            t = t->hashMap[ch];
        }
        t->isEnd = true;
    }

    bool search(string word) {
        int len = word.length();
        Trie *t = this;
        for (int i = 0; i < len; i++) {
            char ch = word[i];
            if (t->hashMap.find(ch) == t->hashMap.end()) return false;
            t = t->hashMap[ch];
        }
        return t->isEnd;
    }

    bool startsWith(string prefix) {
        int len = prefix.length();
        Trie *t = this;
        for (int i = 0; i < len; i++) {
            char ch = prefix[i];
            if (t->hashMap.find(ch) == t->hashMap.end()) return false;
            t = t->hashMap[ch];
        }
        return true;
    }
private:
    std::unordered_map<char, Trie*> hashMap;
    bool isEnd;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
