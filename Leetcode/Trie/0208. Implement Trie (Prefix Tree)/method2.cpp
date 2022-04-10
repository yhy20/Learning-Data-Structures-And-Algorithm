#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    bool isEnd = false;
    TrieNode* next[26];
    TrieNode() {
        memset(next, 0, sizeof(next));
    }
};

//字典树：结点与树分离(代码复用版)
class Trie {
private:
    TrieNode* root;
    TrieNode* searchPrefix(const string& prefix) {
        TrieNode* curr = root;
        for(auto c : prefix) {
            c -= 'a';
            if(curr->next[c] == nullptr) {
                return nullptr;
            }
            curr = curr->next[c];
        }
        return curr;
    }

public:
    Trie() {
        root = new TrieNode();
    }
    void insert(const string& word) {
        TrieNode* curr = root;
        for(auto c : word) {
            c -= 'a';
            if(curr->next[c] == nullptr) {
                curr->next[c] = new TrieNode();
            }
            curr = curr->next[c];
        }
        curr->isEnd = true;
    }
    bool search(const string& word) {
        auto node = searchPrefix(word);
        return node && node->isEnd;
    }
    bool startsWith(const string& prefix) {
        return searchPrefix(prefix);
    }
};

int main() {
    return 0;
}