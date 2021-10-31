/* Problem: Add and search word - Data Structure Design
 * Weblink: https://leetcode.com/explore/interview/card/facebook/56/design-3/300/
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

    bool searchDot(string word)
    {
        int len = word.length();
        Trie *t = this;
        for (int i = 0; i < len; i++) {
            char ch = word[i];
            if (ch != '.' && t->hashMap.find(ch) == t->hashMap.end()) return false;
            if (ch == '.') {
                auto itr = t->hashMap.begin();
                for (; itr != t->hashMap.end(); itr++) {
                    auto &p = *itr;
                    Trie *tmp = p.second;
                    if (tmp->searchDot(word.substr(i + 1))) return true;
                }
                return false;
            } else {
                t = t->hashMap[ch];
            }
        }
        return t->isEnd;
    }
private:
    std::unordered_map<char, Trie*> hashMap;
    bool isEnd;
};

class WordDictionary {
public:
    WordDictionary() {

    }

    void addWord(string word) {
        int len = word.length();
        if (hashMap.find(len) == hashMap.end()) {
            hashMap[len] = new Trie();
        }
        hashMap[len]->insert(word);
    }

    bool search(string word) {
        int len = word.length();
        if (hashMap.find(len) == hashMap.end()) return false;
        Trie *t = hashMap[len];
        return t->searchDot(word);
    }
private:
    std::unordered_map<int, Trie*> hashMap;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
