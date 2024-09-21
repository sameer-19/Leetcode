class Solution {
public:
    void generate(int num, int limit, vector<int> &ans)
    {
        if(num>limit) return;
        
        ans.push_back(num);
        
        for(int i=0;i<=9;i++)
        {
            int current = num*10 + i;
            if(current>limit) break;
            
            generate(current,limit,ans);
        }
        
        return;
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        
        for(int start=1;start<=9;start++)
        {
            generate(start,n,ans);
        }
        
        return ans;
    }
};