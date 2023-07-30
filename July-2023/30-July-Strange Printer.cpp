class Solution {
public:

    int helper(string &str, int s, int e, vector<vector<int>>&dp)
    {
        if(s>e)
            return 0;

        if(dp[s][e]!=-1)
            return dp[s][e];
        
        int count = 1e9;

        count = 1 + helper(str, s+1, e, dp);

        for(int j=s+1; j<=e; j++)
        {
            if(str[j]==str[s])
            {
                int newAnswer = helper(str, s, j-1, dp) + helper(str, j+1, e, dp);
                count = min(count, newAnswer);
            }
        }

        return dp[s][e] = count;
        
    }


    int strangePrinter(string s) {

        int len = s.length();
        vector<vector<int>>dp(len, vector<int>(len, -1));

        return helper(s, 0, len-1, dp);
        
    }
};
