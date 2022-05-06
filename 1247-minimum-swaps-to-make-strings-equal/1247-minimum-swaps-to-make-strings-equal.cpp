class Solution {
public:
    int count1(string s1,string s2,char ch)
    {
        int i,cnt=0;
        for(i=0;i<s1.size();i++)
        {
            if(s1[i]==ch) cnt++;
        }
        for(i=0;i<s2.size();i++)
        {
            if(s2[i]==ch) cnt++;
        }
        return cnt;
    }
    
    int minimumSwap(string s1, string s2) {
        if(s1==s2) return 0;
        
        int ans=0,n=s1.size(),i;
        
        if(count1(s1,s2,'x')%2!=0 and count1(s1,s2,'y')%2!=0) return -1;
        
        int x=0,y=0;
        
        for(i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])
            {
                if(s1[i]=='x') x++; // means x-y pair
                else y++; // means y-x pair
            }
        }
        
        // x x or y y pair takes 1 swap
        // y y    x x 
        // x y or y x pair takes 2 swaps
        // y x    x y
        
        ans+=(x/2)+x%2;
        ans+=(y/2)+y%2;
        
        return ans;
    }
};