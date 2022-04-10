#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    int nums = 0;
    int prefix_nums = 0;
    TrieNode* next[26];
    TrieNode() {
        memset(next, 0, sizeof(next));
    }
};

//字典统计树：结点与树分离
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
            if(!curr->next[c]) {
                curr->next[c] = new TrieNode();
            }
            curr = curr->next[c];
            ++curr->prefix_nums;
        }
        ++curr->nums;
    }

    int countWordsEqualTo(const string& word) {
        TrieNode* curr = root;
        for(auto c : word) {
            c -= 'a';
            if(!curr->next[c]) return 0;
            curr = curr->next[c];
        }
        return curr->nums;
    }

    int countWordsStartingWith(const string& prefix) {
        TrieNode* curr = root;
        for(auto c : prefix) {
            c -= 'a';
            if(!curr->next[c]) return 0;
            curr = curr->next[c];
        }
        return curr->prefix_nums;
    }

    void erase(const string& word) {
        TrieNode* curr = root;
        for(auto c : word) {
            curr = curr->next[c - 'a'];
            --curr->prefix_nums;
        }
        --curr->nums;
    }
};

int main() {
    return 0;
}