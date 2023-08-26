class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while(n>0)
        {
            int rem = n%26;
            if(rem==0) 
            {
                ans+='Z';
                n/=26;
                n--;
            }
            else
            {
                char ch = 'A';
                ch+=rem-1;
                ans+=ch;
                n-=rem;
                n/=26;
            }
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};