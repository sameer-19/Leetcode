class Solution {
public:
    int par[27];
    
    int findParent(int x)
    {
        if(par[x]==-1) return x;
        
        return par[x] = findParent(par[x]);
    }
    
    void unionNode(int a,int b)
    {   
        int p1=findParent(a);
        int p2=findParent(b);
        
        if(p1!=p2) par[p1]=p2;
    }
    
    bool equationsPossible(vector<string>& a) {
        int i,n=a.size();
        
        for(i=0;i<27;i++) par[i]=-1;
        
        for(auto s: a)
        {
            if(s[1]=='=')
            {
                unionNode(s[0]-'a',s[3]-'a');
            }
        }
         
        for(auto s: a)
        {
            if(s[1]=='!' and findParent(s[0]-'a')==findParent(s[3]-'a')) return false;
        }
        
        return true;
    }
};