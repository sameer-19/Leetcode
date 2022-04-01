class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size()==1) return;
        int i;
        for(i=0;i<s.size()/2;i++)
        {
            swap(s[i],s[s.size()-i-1]);
        }
        return;
    }
};