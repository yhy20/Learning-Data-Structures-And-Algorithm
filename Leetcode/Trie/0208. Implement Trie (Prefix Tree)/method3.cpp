#include <bits/stdc++.h>
using namespace std;

//字典树：树本身即是结点
class Trie {
private:
    bool isEnd;
    Trie* next[26];

public:
    Trie() : isEnd(false) {
        memset(next, 0, sizeof(next));
    }
    void insert(const string& word) {
        Trie* curr = this;
        for(auto c : word) {
            c -= 'a';
            if(curr->next[c] == nullptr) {
                curr->next[c] = new Trie();
            }
            curr = curr->next[c];
        }
        curr->isEnd = true;
    }
    bool search(const string& word) {
        Trie* curr = this;
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
        Trie* curr = this;
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