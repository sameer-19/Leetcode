class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string, bool> m;
        int res = 0;
        for(auto word : words)
        {
            if(m.find(word) != m.end()){res += m[word]; continue;}
            int i=0, j=0;
            
            while(i<word.length() && j<s.length())
            {
                if(s[j] == word[i])i++,j++;
                else j++;
            }
            
            m[word] = i==word.length();
            res += i==word.length();
        }
        return res;
    }
};