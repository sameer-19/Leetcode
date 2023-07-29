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
    
    bool optimal(string s, string t) {
        int a[26]={0}, b[26]={0};
        
        for(int i=0;i<s.length();i++){
            a[s[i]-'a']++;
        }
        
        for(int i=0;i<t.length();i++){
            b[t[i]-'a']++;
        }
        
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i]) return false;
        }
        
        return true;
    }
    
    bool isAnagram(string s, string t) {
        return optimal(s,t);
    }
};