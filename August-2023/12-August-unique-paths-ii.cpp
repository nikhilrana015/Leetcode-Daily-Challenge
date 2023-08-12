class Solution {
public:

    int helper(vector<vector<int>>&obstacle, int x, int y, vector<vector<int>>&dp)
    {   
        if(x<0 or y<0 or x>=obstacle.size() or y>=obstacle[0].size() or obstacle[x][y]==1)
            return 0;

        if(x==obstacle.size()-1 and y==obstacle[0].size()-1)
            return 1;

        if(dp[x][y]!=-1)
            return dp[x][y];

        int op1,op2;
        op1 = op2 = 0;

        op1 = helper(obstacle, x, y+1, dp);
        op2 = helper(obstacle, x+1, y, dp);

        return dp[x][y] = op1+op2;

        
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacle) {
        int m = obstacle.size();
        int n = obstacle[0].size();

        if(obstacle[m-1][n-1]==1)
            return 0;

        vector<vector<int>>dp(m, vector<int>(n, -1));
        return helper(obstacle, 0, 0, dp);
    }
};
