class Solution
{
    public:
        int solve(int n)
        {
            int ans = 0;
            while (n != 0)
            {
                int x = n % 10;
                ans += (x *x);
                n /= 10;
            }
            return ans;
        }

    bool isHappy(int n)
    {
        bool a[1000] = { 0 };
        while (1)
        {
            int z = solve(n);
            if (z == 1)
            {
                return true;
                break;
            }
            else if (a[z] == 1)
            {
                return false;
                break;
            }
            else
            {
                a[z] = 1;
                n = z;
            }
        }
    }
};