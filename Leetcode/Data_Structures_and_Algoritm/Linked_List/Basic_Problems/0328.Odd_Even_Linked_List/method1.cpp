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

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode head1, head2;
        ListNode *curr1 = &head1, *curr2 = &head2;
        bool isOdd = true;
        while(head) {
            if(isOdd){
                curr1->next= head;
                curr1 = curr1->next;
                isOdd = false;
            }
            else{
                curr2->next = head;
                curr2 = curr2->next;
                isOdd = true;
            }
            head = head->next;
        }
        curr1->next = head2.next;
        curr2->next = nullptr;
        return head1.next;
    }
};

int main(){
    Solution s;
    
    return 0;
}