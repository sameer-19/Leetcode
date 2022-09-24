class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> a,b;
        
        int i,j,m=version1.length(),n=version2.length();
    
        int sum=0;
        
        for(i=0;i<m;i++)
        {
            if(version1[i]=='.')
            {
                a.push_back(sum);
                sum=0;
            }
            else
            {
                sum*=10;
                sum+=version1[i]-'0';
            }
        }
        a.push_back(sum);
        
        sum=0;
            
        for(i=0;i<n;i++)
        {
            if(version2[i]=='.')
            {
                b.push_back(sum);
                sum=0;
            }
            else
            {
                sum*=10;
                sum+=version2[i]-'0';
            }
        }
        b.push_back(sum);
        
        if(a.size()<b.size())
        {
            int d = b.size()-a.size();
            
            for(i=0;i<d;i++) a.push_back(0);
            
        }
        else if(a.size()>b.size())
        {
            int d = a.size()-b.size();
            
            for(i=0;i<d;i++) b.push_back(0);
        }   
        
        for(i=0;i<a.size();i++)
        {
            if(a[i]<b[i]) return -1;
            else if(a[i]>b[i]) return 1;
        }
        
        return 0;
    }
};