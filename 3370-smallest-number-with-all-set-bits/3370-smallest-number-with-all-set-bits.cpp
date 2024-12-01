class Solution {
public:
    int smallestNumber(int n) {
        int ans = 1, cnt = 0;
        
        while(ans<=n)
        {
            ans*=2;
            cnt++;
        }
        
        return ans-1;
    }
};