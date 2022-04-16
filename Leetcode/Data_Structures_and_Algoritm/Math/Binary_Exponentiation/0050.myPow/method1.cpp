#include<bits/stdc++.h>
using namespace std;

//快速幂：无大数求余
class Solution {
public:
    //long long 是为了解决 INT_MAX取负值越界的问题
    double myPow(double x, long long n) {
        return n > 0 ? iterate(x, n) : 1.0 / iterate(x, -n);
        //return n > 0 ? recursion(x, n) : 1.0 / recursion(x, -n);
    }
    double iterate(double x, long long n){
        double ans = 1.0;
        while(n){
            if(n & 1) ans *= x;
            x *= x;
            n >>= 1;
        }
        return ans;
    }
    double recursion(double x, long long n){
        if(n == 0) return 1.0;
        double y = recursion(x, n >> 1);
        return n & 1 ? y * y * x : y * y;
    }
};

int main(){
    Solution s;
    
    return 0;
}