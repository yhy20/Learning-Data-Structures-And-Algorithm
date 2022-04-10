#include <bits/stdc++.h>
using namespace std;

//本题是交互式题目，此处的FontInfo类只是一个描述，详见LeetCode题目1618
class FontInfo {
public:
    // Return the width of char ch when fontSize is used.
    int getWidth(int fontSize, char ch) { return 0; }

    // Return Height of any char when fontSize is used.
    int getHeight(int fontSize) { return 0; }
};

class Solution {
public:
    long cnt[26] = {0};
    bool check(int w, int h, int fontSize, FontInfo &fontInfo) {
        if (fontInfo.getHeight(fontSize) > h) return false;
        long sum = 0;
        for (int i = 0; i < 26; ++i) {
            sum += cnt[i] * fontInfo.getWidth(fontSize, (i + 'a'));
            if (sum > w) return false;
        }
        return true;
    }
    int maxFont(string &text, int w, int h, vector<int> &fonts, FontInfo &fontInfo) {
        int ans = -1;
        int l = 0, r = fonts.size() - 1;
        for (auto c : text)
            ++cnt[c - 'a'];
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (check(w, h, fonts[mid], fontInfo)) {
                ans = fonts[mid];
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}