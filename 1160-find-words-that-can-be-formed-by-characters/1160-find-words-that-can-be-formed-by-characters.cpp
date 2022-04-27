class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int a[26]={0};
        
        int i,j,ans=0;
        
        for(auto x: chars) a[x-'a']++;
        
        for(auto x: words)
        {
            int b[26]={0},f=0;
            for(auto y: x) b[y-'a']++;
            
            for(i=0;i<26;i++){
                if(b[i]>a[i]) { f=1;break;}
            }
            if(f==0) ans+=x.length(); 
            
        }
        
        return ans;
    }
};