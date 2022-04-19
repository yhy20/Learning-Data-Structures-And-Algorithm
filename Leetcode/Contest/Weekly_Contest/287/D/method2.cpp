#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; ++i)
#define per(i, a, n) for(int i = n - 1; i >= a; --i)
#define ms(x, y) memset(x, y, sizeof(x));
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)(x).size());
#define pb push_back
#define fi first
#define se second
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long ll;
typedef double db;
const ll mod = 1e9 + 7;

struct Node {
    Node() : child(26), isEnd(false) {}
    vector<Node*> child;
    bool isEnd;
};

class Trie {
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        int n = word.size();
        Node* curr = root;
        for(int i = 0; i < n; ++i) {
            if(curr->child[word[i] - 'a'] == nullptr) {
                curr->child[word[i] - 'a'] = new Node();
            }
            curr = curr->child[word[i] - 'a'];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        int n = word.size();
        Node* curr = root;
        for(int i = 0; i < n; ++i) {
            if(curr->child[word[i] - 'a'] == nullptr)
                return false;
            else
                curr = curr->child[word[i] - 'a'];
        }
        return curr->isEnd;
    }

    bool startsWith(string prefix) {
        int n = prefix.size();
        Node* curr = root;
        for(int i = 0; i < n; ++i) {
            if(curr->child[prefix[i] - 'a'] == nullptr)
                return false;
            else
                curr = curr->child[prefix[i] - 'a'];
        }
        return true;
    }

private:
    Node* root;
};

class Encrypter {
public:
    vector<char> keys;
    unordered_map<char, int> mp;
    unordered_map<string, unordered_set<int>> mp1;
    vector<string> values;
    Trie tree;
    Encrypter(vector<char>& _keys, vector<string>& _values, vector<string>& dictionary) {
        for(int i = 0; i < _keys.size(); ++i) mp[_keys[i]] = i;
        for(int i = 0; i < _values.size(); ++i) mp1[_values[i]].insert(i);
        keys = move(_keys);
        for(auto& s : dictionary) tree.insert(s);
        values = move(_values);
    }

    string encrypt(string word1) {
        string ret;
        for(auto c : word1) {
            ret += values[mp[c]];
        }
        return move(ret);
    }

    int decrypt(string word2) {
        int n = word2.size();
        vector<string> temp;
        auto& set = mp1[word2.substr(0, 2)];
        if(n == 2) {
            for(auto i : set) {
                string toFind = string(1, keys[i]);
                if(tree.search(toFind)) {
                    temp.push_back(toFind);
                }
            }
            return temp.size();
        }
        for(auto i : set) {
            string toFind = string(1, keys[i]);
            if(tree.startsWith(toFind)) {
                temp.push_back(toFind);
            }
        }
        vector<string> temp1;
        for(int i = 2; i < n; i += 2) {
            auto& set1 = mp1[word2.substr(i, 2)];
            if(i == n - 2) {
                for(int i = 0; i < temp.size(); ++i) {
                    for(auto j : set1) {
                        string find = temp[i] + keys[j];
                        if(tree.search(find)) {
                            temp1.push_back(find);
                        }
                    }
                }
            } else {
                for(int i = 0; i < temp.size(); ++i) {
                    for(auto j : set1) {
                        string find = temp[i] + keys[j];
                        if(tree.startsWith(find)) {
                            temp1.push_back(find);
                        }
                    }
                }
            }

            temp.clear();
            temp.swap(temp1);
        }
        return temp.size();
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */

int main() {
    return 0;
}