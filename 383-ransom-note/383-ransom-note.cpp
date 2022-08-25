class Solution {
public:
    bool canConstruct(string note, string mg) {
        int a[26]={0},b[26]={0};
        
        int i;
        for(i=0;i<note.size();i++)
        {
            a[note[i]-'a']++;
        }
        
        for(i=0;i<mg.size();i++)
        {
            b[mg[i]-'a']++;
        }
        
        for(i=0;i<26;i++)
        {
            if(a[i]>b[i]) return false; 
        }
        
        return true;
    }
};