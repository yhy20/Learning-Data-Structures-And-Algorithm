#include <bits/stdc++.h>
using namespace std;

//字典统计树：树本身即是结点
class Trie {
private:
    int nums = 0;
    int prefix_nums = 0;
    Trie* next[26];

public:
    Trie() {
        memset(next, 0, sizeof(next));
    }

    void insert(const string& word) {
        Trie* curr = this;
        for(auto c : word) {
            c -= 'a';
            if(!curr->next[c]) {
                curr->next[c] = new Trie();
            }
            curr = curr->next[c];
            ++curr->prefix_nums;
        }
        ++curr->nums;
    }

    int countWordsEqualTo(const string& word) {
        Trie* curr = this;
        for(auto c : word) {
            c -= 'a';
            if(!curr->next[c]) return 0;
            curr = curr->next[c];
        }
        return curr->nums;
    }

    int countWordsStartingWith(const string& prefix) {
        Trie* curr = this;
        for(auto c : prefix) {
            c -= 'a';
            if(!curr->next[c]) return 0;
            curr = curr->next[c];
        }
        return curr->prefix_nums;
    }

    void erase(const string& word) {
        Trie* curr = this;
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