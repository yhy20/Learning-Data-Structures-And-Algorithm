#include<bits/stdc++.h>
using namespace std;

//Segment Tree
class SegmentTree{
private:
    int n;
    vector<int> tree;

public:
    SegmentTree(vector<int>& nums) : n(nums.size()), tree(n * 4){
        build(0, 0, n - 1, nums);
    }
    void build(int node, int s, int e, vector<int>& nums){
        if(s == e){
            tree[node] = nums[s];
            return;
        }
        int mid = s + ((e - s) >> 1);
        int l = node * 2 + 1, r = node * 2 + 2;
        build(l, s, mid, nums);
        build(r, mid + 1, e, nums);
        tree[node] = tree[l] + tree[r];
    }
    void change(int index, int val, int node, int s, int e){
        if(s == e){
            tree[node] = val;
            return;
        }
        int mid = s + ((e - s) >> 1);
        int l = node * 2 + 1, r = node * 2 + 2;
        if(index <= mid){
            change(index, val, l, s, mid);
        }else{
            change(index, val, r, mid + 1, e);
        }
        tree[node] = tree[l] + tree[r];
    }
    int range(int left, int right, int node, int s, int e){
        if(left == s && right == e){
            return tree[node];
        }
        int mid = s + ((e - s) >> 1);
        int l = node * 2 + 1, r = node * 2 + 2;
        if(right <= mid){
            return range(left, right, l, s, mid);
        }else if(left > mid){
            return range(left, right, r, mid + 1, e);
        }else{
            return range(left, mid, l, s, mid) + range(mid + 1, right, r, mid + 1, e);
        }
    }
};


class NumArray {
public:
    int n;
    SegmentTree tree;
    NumArray(vector<int>& nums) : n(nums.size()), tree(nums) {}
    
    void update(int index, int val) {
        tree.change(index, val, 0, 0, n - 1);
    }
    
    int sumRange(int left, int right) {
        return tree.range(left, right, 0, 0, n - 1);
    }
};

int main(){
    vector<int> a = {1, 2, 3, 4, 6};
    NumArray s(a);
    
    return 0;
}