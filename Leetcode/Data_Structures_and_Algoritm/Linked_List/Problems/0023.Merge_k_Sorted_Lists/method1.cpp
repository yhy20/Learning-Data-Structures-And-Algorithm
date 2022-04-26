#include<bits/stdc++.h>
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

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//Merge Sort
class Solution {
public:
    ListNode* merge(vector<ListNode*>& lists , int l, int r){
        if(l == r){
            return lists[l];
        }
        int mid = l + ((r - l) >> 1);
        auto head1 = merge(lists, l, mid);
        auto head2 = merge(lists, mid + 1, r);
        ListNode head;
        auto curr = &head;
        while(head1 && head2){
            if(head1->val <= head2->val){
                curr->next = head1;
                head1 = head1->next;
            }
            else {
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }
        curr->next = head1 ? head1 : head2;
        return head.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return merge(lists, 0, lists.size() - 1);
    }
};

int main(){
    Solution s;
    
    return 0;
}