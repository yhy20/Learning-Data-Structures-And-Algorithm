#include <bits/stdc++.h>
using namespace std;

//快速选择算法只能保证第k个数正确，但前k - 1个数是乱序的
class Solution1 {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k == 0) return {};
        srand((unsigned)time(NULL));
        quickSelect(arr, 0, arr.size(), k);
        return vector<int>(arr.begin(), arr.begin() + k);
    }
    void quickSelect(vector<int>& a, int l, int r, int k) {
        if(l + 1 >= r) return;
        int pos = l + rand() % (r - l);
        int povit = a[pos];
        swap(a[pos], a[r - 1]);
        int index = l;
        for(int i = l; i < r; ++i) {
            if(a[i] <= povit) {
                swap(a[index++], a[i]);
            }
        }
        if(index == k)
            return;
        else if(k < index)
            quickSelect(a, l, index - 1, k);
        else
            quickSelect(a, index, r, k);
    }
};

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        nth_element(arr.begin(), arr.begin() + k - 1, arr.end());
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};

int main() {
    Solution s;

    return 0;
}