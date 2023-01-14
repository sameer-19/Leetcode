class Solution {
public:
    int parent[26];
    
    int findParent(int x)
    {
        if(parent[x]==x) return x;
        
        return parent[x] = findParent(parent[x]);
    }
    
    void Union(int a,int b)
    {
        int x = findParent(a);
        int y = findParent(b);
        
        if(x==y) return;
        if(x>y)
        {
            parent[a] = y;    
            parent[x]=y;
        }
        else
        {
            parent[b] = x;
            parent[y] = x;
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(int i=0;i<26;i++) parent[i]=i;
        
        for(int i=0;i<s1.length();i++)
        {
            Union(s1[i]-'a',s2[i]-'a');
        }
        
        for(int i=0;i<s1.length();i++)
        {
            Union(s1[i]-'a',s2[i]-'a');
        }
        
        string ans="";
        
        for(int i=0;i<baseStr.length();i++)
        {
            int x = parent[baseStr[i]-'a'];
            
            char ch='a';
            ch+=x;
            
            ans+=ch;
        }
        
        return ans;
    }
};