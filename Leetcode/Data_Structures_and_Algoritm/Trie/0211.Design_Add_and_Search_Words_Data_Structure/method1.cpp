#include <bits/stdc++.h>
using namespace std;

class Trie {
private:
    bool isEnd;
    Trie* next[26];
    bool rsearch(const string& word, Trie* root, int index) {
        if(index == word.size()) return root->isEnd;
        if(word[index] == '.') {
            for(int i = 0; i < 26; ++i) {
                if(root->next[i] && rsearch(word, root->next[i], index + 1)) {
                    return true;
                }
            }
        } else {
            if(!root->next[word[index] - 'a']) return false;
            return rsearch(word, root->next[word[index] - 'a'], index + 1);
        }
        return false;
    }

public:
    Trie() : isEnd(false) {
        memset(next, 0, sizeof(next));
    }

    void insert(const string& key) {
        Trie* curr = this;
        for(auto c : key) {
            c -= 'a';
            if(!curr->next[c]) {
                curr->next[c] = new Trie();
            }
            curr = curr->next[c];
        }
        curr->isEnd = true;
    }

    bool search(const string& word) {
        return rsearch(word, this, 0);
    }
};

class WordDictionary {
private:
    Trie tree;

public:
    WordDictionary() {}

    void addWord(const string& word) {
        tree.insert(word);
    }

    bool search(const string& word) {
        return tree.search(word);
    }
};

int main() {
    WordDictionary s;

    return 0;
}