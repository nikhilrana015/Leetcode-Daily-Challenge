class Solution {
public:

    int dx[8] = {-2,-2,-1,1,-1,1,2,2};
    int dy[8] = {-1,1,-2,-2,2,2,-1,1};

    bool isValid(int row, int col, int n)
    {
        if(row<0 or col<0 or row>=n or col>=n)
            return false;

        return true;
    }

    double helper(int n, int k, int row, int col, vector<vector<vector<double>>>&dp)
    {   
        if(k==0)
            return 1.0;

        if(dp[row][col][k]!=-1)
            return dp[row][col][k];

        // double cnt = 0.0;
        double ans = 0.0;

        for(int m=0; m<8; m++)
        {
            int nrow = row + dx[m];
            int ncol = col + dy[m];

            if(isValid(nrow, ncol, n))
            {
                ans = ans  + (helper(n, k-1, nrow, ncol, dp)/8.0);
                // cnt += 1.0;
            }
        }
        
        // return ans * (cnt/8.0);
        return dp[row][col][k] = ans;
    }

    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>>dp(n, vector<vector<double>>(n, vector<double>(k+1,-1)));
        return helper(n, k, row, column, dp);
    }
};