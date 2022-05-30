class Solution {
public:
    int divide(int dividend, int divisor) {
        long ans = ((long)dividend/divisor);
        
        return ((ans>=INT_MIN and ans<INT_MAX) ? ans : (ans>=INT_MAX ? INT_MAX : INT_MIN));
    }
};