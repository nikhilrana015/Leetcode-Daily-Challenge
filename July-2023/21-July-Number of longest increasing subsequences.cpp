class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int size = nums.size();

        vector<int>dp(size, 1);
        vector<int>cnt(size, 1);
        int maxLen = 1;
        int nTimes = 0;

        for(int i=0; i<size; i++)
        {  
            for(int j=0; j<i; j++)
            {
                if(nums[i]>nums[j])
                {   
                    if(dp[i]<dp[j]+1)
                    {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }

                    else if(dp[i]==dp[j]+1)
                    {
                        cnt[i] += cnt[j];
                    }
                }
            }

            if(dp[i]>maxLen)
            {
                maxLen = dp[i];
                nTimes = cnt[i];
            }

            else if(dp[i]==maxLen)
            {
                nTimes += cnt[i];
            }


        }

        // for(int i=1; i<=size; i++)
        //     cout<<cnt[i]<<" ";

        return nTimes;
    }
};