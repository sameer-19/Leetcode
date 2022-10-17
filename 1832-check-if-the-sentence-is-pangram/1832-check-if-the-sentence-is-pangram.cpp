class Solution {
public:
    bool checkIfPangram(string sentence) {
        int a[26]={0};
        for(int i=0;i<sentence.size();i++)
        {
            a[sentence[i]-'a']++;
            
        }
        
        for(int i=0;i<26;i++)
        {
            if(a[i]<1) return false;
        }
        return true;
    }
};