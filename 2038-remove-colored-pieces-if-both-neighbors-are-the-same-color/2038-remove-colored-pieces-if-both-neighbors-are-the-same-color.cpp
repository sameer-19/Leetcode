class Solution {
public:
    bool winnerOfGame(string s) {
        int n = s.length(),countA = 0, countB = 0;
        
        int i=2;
        
        while(i<n)
        {
            if(s[i]==s[i-1] and s[i-1]==s[i-2])
            {
                if(s[i]=='A') countA++;
                else countB++;
            }
            i++;
        }
        
        return countA>countB;
    }
};