#include <bits/stdc++.h>
using namespace std;

class WordDictionary {
private:
    bool isEnd;
    WordDictionary* next[26];
    bool rsearch(const string& word, WordDictionary* root, int index) {
        if(index == word.size()) {
            return root->isEnd;
        }
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
    WordDictionary() : isEnd(false) {
        memset(next, 0, sizeof(next));
    }

    void addWord(const string& word) {
        WordDictionary* curr = this;
        for(auto c : word) {
            c -= 'a';
            if(!curr->next[c]) {
                curr->next[c] = new WordDictionary();
            }
            curr = curr->next[c];
        }
        curr->isEnd = true;
    }

    bool search(const string& word) {
        return rsearch(word, this, 0);
    }
};

int main() {
    WordDictionary s;

    return 0;
}