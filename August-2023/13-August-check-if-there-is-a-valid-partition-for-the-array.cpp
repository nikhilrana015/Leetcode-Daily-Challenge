class Solution {
public:

    //map<pair<int,int>,int>dp;

    bool helper(vector<int>&nums, int idx, vector<int>&dp)
    {   
        if(idx<0)
            return true;

        if(dp[idx]!=-1)
            return dp[idx];

        bool ans = false;

        if(idx>0 and nums[idx]==nums[idx-1])
            ans = ans | helper(nums, idx-2, dp);

        if(idx>1 and nums[idx]==nums[idx-1] and nums[idx-1]==nums[idx-2])
            ans = ans | helper(nums, idx-3, dp);

        if(idx>1 and nums[idx]-nums[idx-1]==1 and nums[idx-1]-nums[idx-2]==1)
            ans = ans | helper(nums, idx-3, dp);

        return dp[idx] = ans;
    }

    bool validPartition(vector<int>& nums) {
        vector<int>dp(nums.size()+1, -1);
        return helper(nums, nums.size()-1, dp);   
    }
};
