class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0) return false;
        if(n<0) return false;
        
        if(ceil(log2(n))==floor(log2(n)))
        {
            int d=log2(n);
            if(d%2==0) return true;
        }
        return false;
    }
};