class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        set<pair<string,string>> s;
        
        for(int i=0;i<words.size();i++)
        {
            pair<string,string> p;
            for(int j=0;j<words[i].size();j++)
            {
                if(j%2==0) p.first+=words[i][j];
                else p.second+=words[i][j];
            }
            sort(p.first.begin(),p.first.end());
            sort(p.second.begin(),p.second.end());
            
            s.insert(p);
            
        }
        return s.size();
    }
};