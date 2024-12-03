class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int spaceIndex = 0;
        
        for(int i=0;i<s.size();i++)
        {
            if(spaceIndex<spaces.size() && i==spaces[spaceIndex])
            {
                ans+=' ';
                spaceIndex++;
            }
            ans+=s[i];
        }
        
        return ans;
    }
};