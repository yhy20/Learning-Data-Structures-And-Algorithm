#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* u) {
        if(!u) return nullptr;
        return dfs(u);
    }
    Node* dfs(Node* u){
        Node* ret = new Node(u->val);
        mp[u] = ret;
        for(auto v : u->neighbors){
            if(!mp[v]){ 
                ret->neighbors.push_back(dfs(v));
            }else{ 
                ret->neighbors.push_back(mp[v]);
            }
        }
        return ret;
    }
};

int main(){
    Solution s;
    
    return 0;
}