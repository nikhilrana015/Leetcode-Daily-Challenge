class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        int size = arr.size();
        unordered_map<int,int>dp;

        //vector<int>dp((2*maxii) + 5, 1);
        int maxLen = 1;

        for(int i=0; i<size; i++)
        {   
            int currElem = arr[i];
            
            if(dp.find(currElem-difference)!=dp.end())
            {
                dp[currElem] = max(1+dp[currElem-difference], dp[currElem]);
                maxLen = max(maxLen, dp[currElem]);
            }
            else
                dp[currElem] = 1;
                
        }

        return maxLen;
    }
};