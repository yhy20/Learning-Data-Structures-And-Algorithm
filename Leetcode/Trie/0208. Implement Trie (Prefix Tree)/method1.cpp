#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    bool isEnd = false;
    TrieNode* next[26];
    TrieNode() {
        memset(next, 0, sizeof(next));
    }
};

//字典树：结点与树分离
class Trie {
private:
    TrieNode* root;

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
        TrieNode* curr = root;
        for(auto c : word) {
            c -= 'a';
            if(curr->next[c] == nullptr) {
                return false;
                ;
            }
            curr = curr->next[c];
        }
        return curr->isEnd;
    }
    bool startsWith(const string& prefix) {
        TrieNode* curr = root;
        for(auto c : prefix) {
            c -= 'a';
            if(curr->next[c] == nullptr) {
                return false;
            }
            curr = curr->next[c];
        }
        return true;
    }
};

int main() {
    return 0;
}