class Solution {
public:

    int findAllSubsequences(string &s1, string &s2, vector<vector<int>>&dp, int l1, int l2, vector<vector<int>>&dp2)
    {
        if(l1==0 or l2==0)
        {   
            // cout<<calc<<" ";
            // maxii = max(maxii, calc);
            // return;
            return 0;
        }

        if(dp2[l1][l2]!=-1)
            return dp2[l1][l2];

        if(s1[l1-1]==s2[l2-1])
        {
            return dp2[l1][l2] = findAllSubsequences(s1, s2, dp, l1-1, l2-1, dp2) + (int)s1[l1-1];
        }

        if(dp[l1-1][l2]>dp[l1][l2-1])
            return dp2[l1][l2] = findAllSubsequences(s1, s2, dp, l1-1, l2, dp2);

        if(dp[l1-1][l2]<dp[l1][l2-1])
            return dp2[l1][l2] = findAllSubsequences(s1, s2, dp, l1, l2-1, dp2);


        int op1 = findAllSubsequences(s1, s2, dp, l1-1, l2, dp2);
        int op2 = findAllSubsequences(s1, s2, dp, l1, l2-1, dp2);
        
        return dp2[l1][l2] = max(op1,op2);
    }


    int helper(string &s1, string &s2)
    {
        int len1 = s1.length();
        int len2 = s2.length();

        vector<vector<int>>dp(len1+1, vector<int>(len2+1, 0));

        for(int i=1; i<=len1; i++)
        {
            for(int j=1; j<=len2; j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];

                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        cout<<"Total Length: "<<dp[len1][len2]<<"\n";
        int sumV = 0;

        vector<vector<int>>dp2(len1+1, vector<int>(len2+1, -1));

        return findAllSubsequences(s1, s2, dp, len1, len2, dp2);
    
    }

    int minimumDeleteSum(string s1, string s2) {
        
        int delete_val = helper(s1, s2);
        cout<<delete_val<<" ";

        int ascii_s1, ascii_s2;
        ascii_s1 = ascii_s2 = 0;

        for(auto v: s1)
            ascii_s1 += v;

        for(auto v: s2)
            ascii_s2 += v;

        return (ascii_s1+ascii_s2) - 2*delete_val;

    }
};
