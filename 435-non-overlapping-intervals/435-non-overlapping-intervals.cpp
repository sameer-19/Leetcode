class Solution
{
    public:
        static bool cmp(vector<int> &a, vector<int> &b)
        {
            if (a[1] < b[1]) return true;
            else if (a[1] == b[1])
            {
                return a[0] < b[0];
            }
            return false;
        }

    int eraseOverlapIntervals(vector<vector < int>> &a)
    {
        sort(a.begin(), a.end(), cmp);

        int ans = 0;
        int n = a.size(), i, j;

        int end = a[0][1];

        for (i = 1; i < n; i++)
        {
            if (a[i][0] < end)
            {
                ans++;
            }
            else
            {
                end = max(end, a[i][1]);
            }
        }

        return ans;
    }
};