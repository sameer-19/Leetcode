class Solution {
public:
    void solve(string &s,int idx,int k,vector<int> &ans)
    {
        if(idx<0)
        {
            int z=stoi(s);
            ans.push_back(z);
            return;
        }
        
        for(int i=0;i<=9;i++)
        {
            if(s.length()==0)
            {
                if(i==0) continue;
                char ch='0';
                ch+=i;
                s+=ch;
                solve(s,idx-1,k,ans);
                s.pop_back();
            }
            else
            {
                int diff= abs((s.back()-'0') - i); 
                if(diff==k)
                {
                    char ch='0';
                    ch+=i;
                    s+=ch;
                    solve(s,idx-1,k,ans);
                    s.pop_back();
                }
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        
        int idx=0;
        string s="";
        solve(s,n-1,k,ans);
        
        return ans;
    }
};