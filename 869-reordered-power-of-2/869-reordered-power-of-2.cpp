class Solution {
public:
    bool check(int x,int y)
    {
        int i,a[10]={0},b[10]={0};
        
        while(x)
        {
            a[x%10]++;
            x/=10;
        }
        while(y)
        {
            b[y%10]++;
            y/=10;
        }
        
        for(i=0;i<10;i++)
        {
            if(a[i]!=b[i]) return false;
        }
        
        return true;
    }
    
    int countDigits(int x)
    {
        int cnt=0;
        while(x)
        {
            cnt++;
            x/=10;
        }
        
        return cnt;
    }
    
    bool reorderedPowerOf2(int n) {
        long a[32],i;
        
        a[0]=1;
        for(i=1;i<31;i++) a[i]=2*a[i-1];
        
        int d=countDigits(n);
        
        vector<int> v;
        
        for(i=0;i<31;i++)
        {
            if(countDigits(a[i])==d)
            {
                v.push_back(a[i]);
            }
        }
        
        for(i=0;i<v.size();i++)
        {
            if(check(v[i],n))
            {
                return true;
            }
        }
        
        return false;
    }
};