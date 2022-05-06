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
        
        int ans=0,n=s1.size(),i,cnt=0;
        
        if(count1(s1,s2,'x')%2!=0 and count1(s1,s2,'y')%2!=0) return -1;
        
        string s;
        
        for(i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])
            {
                s.push_back(s1[i]);
            }
        }
        
        int x=count(s.begin(),s.end(),'x');
        int y=count(s.begin(),s.end(),'y');
        
        ans+=(x/2)+x%2;
        ans+=(y/2)+y%2;
        
        
        return ans;
    }
};