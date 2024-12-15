class Solution {
public:
    double calculateGain(int passes, int totalStudents)
    {
        return (double)(passes + 1) / (totalStudents + 1) - (double)passes / totalStudents;
    }
    
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int,int>>> pq;
        
        int k = extraStudents, n = classes.size();
        
        double ans = 0;
        
        for(int i=0;i<n;i++)
        {
            double res = calculateGain(classes[i][0], classes[i][1]);
            
            pq.push({res, {classes[i][0], classes[i][1]}});
        }
        
        while(k--)
        {
            pair<double, pair<int,int>> value = pq.top();
            // cout<<value.first<<" "<<value.second.first<<" "<<value.second.second<<"\n";
            pq.pop();
            
            int passes = value.second.first;
            int totalStudents = value.second.second;
            
            pq.push({calculateGain(passes+1, totalStudents+1), {passes+1, totalStudents+1}});
        }
        
        while(!pq.empty())
        {
            ans+=(double)pq.top().second.first/pq.top().second.second;
            pq.pop();
        }
        
        return ans/n;
    }
};