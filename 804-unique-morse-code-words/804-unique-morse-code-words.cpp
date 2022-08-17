class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s;
        
        vector<string> v={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(auto x: words)
        {
            string str="";
            for(auto y: x)
            {
                str+=(v[y-'a']);
            }
            s.insert(str);
        }
        
        int ans=s.size();
        
        return ans;
    }
};