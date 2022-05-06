class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int res = 24*60;
        vector<int> temp(timePoints.size(),0);
        for(int i = 0 ; i < timePoints.size() ; i ++)
            temp[i] = stoi(timePoints[i].substr(0,2))*60 + stoi(timePoints[i].substr(3,2));
        sort(temp.begin(),temp.end());
        temp.push_back(temp[0]+res);
        for(int i = 1 ; i < temp.size() ; i ++)
            res = min(res,temp[i]-temp[i-1]);
        return res;
    }
};