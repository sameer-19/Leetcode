class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int ans = 0;
        
        unordered_map<string, int> mp;
        
        int rows = matrix.size(), cols = matrix[0].size();
        
        for(int i=0;i<rows;i++)
        {
            string pattern = "";
            
            for(auto c: matrix[i])
            {
                if(c==matrix[i][0]) pattern+='T';
                else pattern+='F';
            }
            
            mp[pattern]++;
        }
        
        for(auto x: mp)
        {
            ans = max(ans, x.second);
        }
        
        return ans;
    }
};