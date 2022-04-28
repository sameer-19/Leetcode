class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        
        int i,j,s1=0,s2=0;
        
        for(auto x: a) s1+=x;
        for(auto x: b) s2+=x;
        
        int d=(s2-s1)/2;
        
        set<int> s;
        
        for(auto x: b) s.insert(x);
        
        for(auto x: a){
            if(s.find(x+d)!=s.end()) return {x,x+d};
        }
        
        
        
        return {0,0};
    }
};