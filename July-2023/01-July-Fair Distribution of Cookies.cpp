class Solution {
public:

    int helper(vector<int>&cookies, vector<int>&distribution, int idx)
    {
        if(idx==cookies.size())
        {
            int getMax = 0;
            for(auto k: distribution)
                getMax = max(getMax, k);

            return getMax;
        }

        int ans = 1e9;

        for(int i=0; i<distribution.size(); i++)
        {   
            distribution[i] += cookies[idx];
            int curr = helper(cookies, distribution, idx+1);
            ans = min(ans, curr);
            distribution[i] -= cookies[idx];
        }
        
        return ans;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        
        vector<int>distribution(k,0);
        return helper(cookies, distribution, 0);

    }
};