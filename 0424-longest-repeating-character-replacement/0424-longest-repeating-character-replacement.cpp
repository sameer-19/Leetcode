class Solution {
public:
    bool check(vector<int> &freq, int &k)
    {   
        int mx=0,sum=0;
        for(int i=0;i<26;i++) mx=max(mx,freq[i]);
        
        for(int i=0;i<26;i++)
        {
            sum+=freq[i];
        }
        
        sum-=mx;
        
        return sum<=k;
    }
    
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        
        int ans=1,len = s.length();
        
        int left=0,right=0;
        
        while(right<len)
        {
            freq[s[right]-'A']++;
            bool res = check(freq,k);
            if(res)
            {
                ans = max(ans,right-left+1);
            }
            else
            {
                while(left<=right)
                {
                    freq[s[left]-'A']--;
                    left++;
                    bool res = check(freq,k);
                    if(res) 
                    {
                        ans=max(ans,right-left+1);
                        break;
                    }
                }
            }
            right++;
        }
        
        return ans;
    }
};