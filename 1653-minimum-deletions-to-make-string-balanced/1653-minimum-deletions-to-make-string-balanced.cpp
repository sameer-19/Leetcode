class Solution {
public:
    int minimumDeletions(string s) {
        int length = s.length();
        vector<int> prefixOfB(length,0), suffixOfA(length,0);
        
        int ans = INT_MAX;
        
        for(int i=1;i<length;i++) {
            if(s[i-1]=='b') prefixOfB[i] = prefixOfB[i-1]+1;
            else prefixOfB[i] = prefixOfB[i-1];
        }
        
        for(int i=length-2;i>=0;i--) {
            if(s[i+1]=='a') suffixOfA[i] = suffixOfA[i+1]+1;
            else suffixOfA[i] = suffixOfA[i+1];
        }
        
        for(int i=0;i<length;i++) {
            ans = min(ans, suffixOfA[i]+prefixOfB[i]);
        }
        
        return ans;
    }
};