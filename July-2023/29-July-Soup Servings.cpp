class Solution {
public:

    double helper(int soupA, int soupB, vector<vector<double>>&dp)
    {
        if(soupA==0 and soupB==0)
            return 0.5;

        if(soupA==0)
            return 1.0;

        if(soupB==0)
            return 0.0;

        if(dp[soupA][soupB]!=-1)
            return dp[soupA][soupB];

        double op1,op2,op3,op4;
        op1 = op2 = op3 = op4 = 0;

        op1 = 0.25 * helper(max(soupA-100,0),soupB, dp);
        op2 = 0.25 * helper(max(soupA-75,0), max(soupB-25,0), dp);
        op3 = 0.25 * helper(max(soupA-50,0), max(soupB-50,0), dp);
        op4 = 0.25 * helper(max(soupA-25,0), max(soupB-75,0), dp);

        return dp[soupA][soupB] = op1+op2+op3+op4;
    }

    double soupServings(int n) {

        if(n>=4800)
            return 1.0;

        vector<vector<double>>dp(n+1, vector<double>(n+1, -1.0));
        return helper(n, n, dp);
    }
};
