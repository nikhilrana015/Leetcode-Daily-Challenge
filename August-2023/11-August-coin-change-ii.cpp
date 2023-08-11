class Solution {
public:

    int helper(vector<int>&coins, int amount, int idx, vector<vector<int>>&dp)
    {   
        if(amount==0)
            return 1;

        if(idx==coins.size())
        {
            if(amount==0)
                return 1;
            return 0;
        }

        if(dp[idx][amount]!=-1)
            return dp[idx][amount];

        int op1,op2;
        op1 = op2 = 0;

        if(amount>=coins[idx])
            op1 = helper(coins, amount-coins[idx], idx, dp);

        op2 = helper(coins, amount, idx+1, dp);

        return dp[idx][amount] = op1+op2;

    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1, -1));
        return helper(coins, amount, 0, dp);
    }
};
