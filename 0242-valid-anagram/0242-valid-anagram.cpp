class Solution {
public:
    bool brute(string s, string t)
    {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        if(s.size()!=t.size()) return false;
        
        int first=0,second=0;
        
        while(first<s.size() and second<t.size()){
            if(s[first]==t[second])
            {
                first++;second++;
            }
            else
            {
                first++;
            }
        }
        
        return second==t.size();
    }
    
    bool isAnagram(string s, string t) {
        return brute(s,t);
    }
};