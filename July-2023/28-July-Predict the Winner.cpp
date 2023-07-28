class Solution {
public:

    int helper(vector<int>&nums, int i, int j)
    {
        if(i>j)
            return 0;

        int op1,op2;
        op1 = op2 = 0;

        op1 = nums[i] + min(helper(nums, i+2, j), helper(nums, i+1, j-1));
        op2 = nums[j] + min(helper(nums, i+1, j-1), helper(nums, i, j-2));

        return max(op1,op2);
        
    }

    bool PredictTheWinner(vector<int>& nums) {
        int sum = 0;
        for(int val: nums)
            sum += val;
        
        int score1 = helper(nums, 0, nums.size()-1);
        int score2 = sum - score1;

        return score1>=score2;
    }
};
