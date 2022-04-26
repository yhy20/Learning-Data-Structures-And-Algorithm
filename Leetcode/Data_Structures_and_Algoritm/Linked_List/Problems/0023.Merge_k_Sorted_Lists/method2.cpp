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

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//优先级队列多路归并
class Solution {
public:
    struct Status {
        int val;
        ListNode* ptr;
        Status(int val, ListNode* ptr) : val(val), ptr(ptr) {}
        bool operator>(const Status& r) const {
            return val > r.val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Status, vector<Status>, greater<Status>> q;
        for(auto node : lists) {
            if(node) q.emplace(node->val, node);
        }

        ListNode dummy, *curr = &dummy;
        while(!q.empty()) {
            auto [val, ptr] = q.top();
            q.pop();
            curr->next = ptr;
            curr = curr->next;
            if(ptr->next) q.emplace(ptr->next->val, ptr->next);
        }
        return dummy.next;
    }
};

int main() {
    Solution s;

    return 0;
}