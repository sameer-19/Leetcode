class Solution {
public:
    int minBitFlips(int start, int goal) {
        int first[32] = {0}, second[32] = {0};
        
        int ans = 0, i = 0;
        
        while(start) {
            first[i++] = start%2;
            start/=2;
        }
        
        i = 0;
        while(goal) {
            second[i++] = goal%2;
            goal/=2;
        }
        
        for(int i=0;i<32;i++)
        {
            ans+= second[i]!=first[i];
        }
        
        return ans;
    }
};