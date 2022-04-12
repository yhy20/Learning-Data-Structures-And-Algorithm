#include<bits/stdc++.h>
using namespace std;

class ArrayReader {
public:
    // Compares the sum of arr[l..r] with the sum of arr[x..y] 
    // return 1 if sum(arr[l..r]) > sum(arr[x..y])
    // return 0 if sum(arr[l..r]) == sum(arr[x..y])     
    // return -1 if sum(arr[l..r]) < sum(arr[x..y])
    int compareSub(int l, int r, int x, int y);
    // Returns the length of the array
    int length();
};
//关键在于区分奇偶区间，分别处理
class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int l = 0, r = reader.length() - 1;
        while(l <= r){
            if(l == r) return l;
            int mid = l + ((r - l) >> 1);
            if((r - l + 1) & 1){
                int check = reader.compareSub(l, mid - 1, mid + 1, r);
                if(check == 0) return mid;
                else if(check > 0) r = mid - 1;
                else l = mid + 1;
            }else{
                int check = reader.compareSub(l, mid, mid + 1, r);
                if(check == 0) return mid;
                else if(check > 0) r = mid;
                else l = mid + 1;
            }   
        }
        return -1;
    }
};

int main(){
    Solution s;
    
    return 0;
}