class Solution {
public:

    bool helper(string &s, unordered_map<string,int>&mapping, int idx, vector<int>&dp)
    {
        if(idx==s.length())
            return true;

        if(dp[idx]!=-1)
            return dp[idx];

        for(int i=idx; i<s.length(); i++)
        {
            string k = s.substr(idx, i-idx+1);

            if(mapping.count(k))
            {
                bool ans = helper(s, mapping, i+1, dp);
                if(ans)
                    return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mapping;

        for(auto v: wordDict)
        {
            mapping[v] += 1;
        }   

        vector<int>dp(s.length()+1, -1);
        return helper(s, mapping, 0, dp);
    }
};
