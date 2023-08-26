class Solution {
public:
    bool bruteForce(string s)
    {
        int n = s.length();
        
        for(int i=1;i<=n/2;i++) // i represents length of the repeated string
        {
            string pre = "", cur = "";
            int j=0;
            bool flag=1;
            while(j<i) pre+=s[j++];
            
            while(j<n)
            {
                cur+=s[j];
                if((j+1)%i==0) 
                {
                    if(pre!=cur) {flag=false; break;}
                    cur = "";
                }
                j++;
            }
            if(cur.length()>0 and pre!=cur) flag=false;
            if(flag) return true; 
        }
        
        return false;
    }
    
    bool repeatedSubstringPattern(string s) {
        // return bruteForce(s);
        
        string doubled = s+s;
        string cur = doubled.substr(1,doubled.size()-2);
        return cur.find(s)!=string::npos;
    }
};