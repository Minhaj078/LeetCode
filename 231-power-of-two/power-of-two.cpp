class Solution {
public:
    bool isPowerOfTwo(int n) {
        for (int i = 0; i <= 31; i++) {
        if ((1LL << i) == n) return true;
    }
    return false;
    }
};