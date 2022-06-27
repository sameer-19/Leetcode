class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b) 
    {  // sorting according to last day (deadline)
        if(a[1]<b[1]) return true;
        else if(a[1]==b[1])
        {
            if(a[0]<b[0]) return true;
        }
        return false; 
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        int i,n=(courses.size()),time=0;
        
        priority_queue<int> q;
        
        sort(courses.begin(),courses.end(),cmp);
        
        for(i=0;i<n;i++)
        {
            if(time+courses[i][0]<=courses[i][1])
            {
                time+=courses[i][0];
                q.push(courses[i][0]);
            }
            else
            {
                if(!q.empty() && q.top()>courses[i][0]) // if taken course duration more than given course duration then remove taken course and select given course.
                {
                    int c=q.top();
                    q.pop();
                    time-=c;
                    time+=courses[i][0];
                    q.push(courses[i][0]);
                }
            }
        }
        return q.size();
    }
};