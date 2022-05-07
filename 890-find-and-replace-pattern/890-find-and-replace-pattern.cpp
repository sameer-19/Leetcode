class Solution {
public:
    
    bool match(string& w1, string& w2) 
    {
        unordered_map<char, char> w1_to_w2;
        for(int i = 0; i < size(w1); i++) 
        {
            if( (w1_to_w2.count(w1[i]) && w1_to_w2[w1[i]] != w2[i]) ) 
                return false; 
            else
                w1_to_w2[w1[i]] = w2[i];
        }    
        bool visited[26]={false};
        
        for(auto x: w1_to_w2)
        {
            if(visited[x.second-'a']) return false;
            else visited[x.second-'a'] = true;
        }
        
        return true;
    }
    
    
    vector<string> findAndReplacePattern(vector<string>& words, string pat) {
        vector<string> ans;
        
        for(auto x: words)
        {
            if(match(x,pat)) ans.push_back(x);
        }
        
        return ans;
    }
};