#define ll long long 
class Solution {
public:

    int mod = 1000000007;

    int helper(int n, int goal, int k, vector<vector<int>>&dp)
    {
        if(n==0 and goal==0)
            return 1ll;

        if(n==0 or goal==0)
            return 0*1ll;

        if(dp[n][goal]!=-1)
            return dp[n][goal];

        ll op1,op2;

        op1 = (helper(n-1, goal-1, k, dp) * 1ll * n)%mod;
        op2 = (helper(n, goal-1, k, dp) * 1ll * max(0, n-k))%mod;

        return dp[n][goal] = (op1+op2)%mod;

    }

    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>>dp(n+1, vector<int>(goal+1, -1));
        return helper(n, goal, k, dp);
    }
};
