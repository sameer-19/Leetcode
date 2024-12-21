class Solution {
public:
    int p = 1e9 + 7;
    
    // calculating x^y efficiently
    long long power(long long x, long long y) {
      long long res = 1;    

      x = x % p; // Update x if it is more than or equal to p
      if (x == 0) return 0; 

      while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1) res = (res*x) % p;
        
        // we have did the odd step is it was odd, now do the even step
        y = y>>1; // dividing y by 2, y>>1 is same as y/2
        x = (x*x) % p;
      }
      return res;
    }
    
    int countGoodNumbers(long long n) {        
        long long cnt4 = n/2, cnt5 = ceil(n/2.0);
        
        return (power(4, cnt4)%p*power(5, cnt5)%p)%p;
    }
};