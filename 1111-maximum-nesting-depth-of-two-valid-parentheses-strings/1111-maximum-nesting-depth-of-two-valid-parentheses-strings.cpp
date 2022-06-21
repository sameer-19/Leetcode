class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        int n=s.length();
        
        vector<int> ans(n,0);
        
        int i;
        stack<int> first,second;
        
        for(i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                if(first.empty() || first.size()<=second.size())
                {
                    first.push(i);
                }
                else{
                    second.push(i);
                    ans[i]=1;
                }
            }
            else
            {
                if(first.size()>second.size())
                {
                    first.pop();
                }
                else
                {
                    second.pop();
                    ans[i]=1;
                }
            }
        }
    
        return ans;
    }
};