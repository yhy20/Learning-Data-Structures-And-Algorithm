#include <bits/stdc++.h>
using namespace std;

//优先级队列归并至第k个数

//重载 operator > 的写法
class Solution1 {
public:
    struct State {
        int val, x, y;
        State(int _val, int _x, int _y) : val(_val), x(_x), y(_y) {}
        bool operator>(const State& r) const {
            return this->val > r.val;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<State, vector<State>, greater<State>> q;
        for(int i = 0; i < n; ++i) {
            q.emplace(matrix[i][0], i, 0);
        }
        for(int i = 1; i < k; ++i) {
            auto [val, x, y] = q.top();
            q.pop();
            if(y + 1 < n) {
                q.emplace(matrix[x][y + 1], x, y + 1);
            }
        }
        return q.top().val;
    }
};

//自定义比较器的写法一
class Solution2 {
public:
    struct State {
        int val, x, y;
        State(int _val, int _x, int _y) : val(_val), x(_x), y(_y) {}
    };
    struct cmp {
        bool operator()(const State& l, const State& r) const {
            return l.val > r.val;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<State, vector<State>, cmp> q;
        for(int i = 0; i < n; ++i) {
            q.emplace(matrix[i][0], i, 0);
        }
        for(int i = 1; i < k; ++i) {
            auto [val, x, y] = q.top();
            q.pop();
            if(y + 1 < n) {
                q.emplace(matrix[x][y + 1], x, y + 1);
            }
        }
        return q.top().val;
    }
};

//定义比较器的写法二
class Solution {
public:
    struct State {
        int val, x, y;
        State(int _val, int _x, int _y) : val(_val), x(_x), y(_y) {}
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        auto cmp = [](const State& l, const State& r) -> bool {
            return l.val > r.val;
        };
        priority_queue<State, vector<State>, decltype(cmp)> q(cmp);
        for(int i = 0; i < n; ++i) {
            q.emplace(matrix[i][0], i, 0);
        }
        for(int i = 1; i < k; ++i) {
            auto [val, x, y] = q.top();
            q.pop();
            if(y + 1 < n) {
                q.emplace(matrix[x][y + 1], x, y + 1);
            }
        }
        return q.top().val;
    }
};

int main() {
    Solution s;

    return 0;
}