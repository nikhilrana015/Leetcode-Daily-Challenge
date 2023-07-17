class Solution {
public:

    int findIndex(vector<vector<int>>&events, int start, int value)
    {
        int end = events.size()-1;
        int ans = -1;

        while(end>=start)
        {
            int mid = (start+end)/2;
            if(events[mid][0]>value)
            {
                ans = mid;
                end = mid-1;
            }
            else
                start = mid+1;
        }

        return ans;
    }

    int helper(vector<vector<int>>&events, int k, int idx, vector<vector<int>>&dp)
    {
        if(idx==events.size() or k==0 or idx==-1)
            return 0;

        if(dp[idx][k]!=-1)
            return dp[idx][k];
        
        int index = findIndex(events, idx+1, events[idx][1]);
        int op1 = events[idx][2] + helper(events, k-1, index, dp);

        int op2 = helper(events, k, idx+1, dp);

        return dp[idx][k] = max(op1,op2);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        vector<vector<int>>dp(events.size()+1, vector<int>(k+1, -1));
        return helper(events, k, 0, dp);
        
    }
};