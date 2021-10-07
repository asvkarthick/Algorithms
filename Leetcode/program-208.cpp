/* Problem: Implement Trie
 * Weblink: https://leetcode.com/problems/implement-trie-prefix-tree/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class TrieNode
{
public:
    TrieNode() : end(false)
    {
        //links = new TrieNode[26];
        for (int i = 0; i < 26; i++) links[i] = nullptr;
    }

    TrieNode* get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, TrieNode *node)
    {
        links[ch - 'a'] = node;
    }

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != nullptr;
    }

    void setEnd()
    {
        end = true;
    }

    bool isEnd()
    {
        return end;
    }
private:
    TrieNode *links[26];
    bool end;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if (!node->containsKey(ch)) {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool search(string word) {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if (!node->containsKey(ch)) return false;
            node = node->get(ch);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        TrieNode *node = root;
        for (int i = 0; i < prefix.length(); i++) {
            char ch = prefix[i];
            if (!node->containsKey(ch)) return false;
            node = node->get(ch);
        }
        return true;
    }
private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
