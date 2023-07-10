class Solution {
public:
    
    int merge(int target, vector<int>&nums, int s, int e)
    {   
        int currSum = 0, minLen = 1e9;
        int idx = s;

        while(idx<=e)
        {
            currSum += nums[idx];
            
            if(currSum>=target)
            {
                while(currSum>=target)
                {
                    minLen = min(minLen, (idx-s+1));
                    currSum -= nums[s];
                    s++;
                }
            }

            idx++;
        }

        return minLen;
    
    }


    int helper2(int target, vector<int>&nums, int s, int e)
    {
        if(s>e)
            return 1e9;

        if(s==e)
        {
            if(nums[s]>=target)
                return 1;
            return 1e9;
        }

        int mid = (s+e)/2;
        int minLen1 = helper2(target, nums, s, mid);
        int minLen2 = helper2(target, nums, mid+1, e);
        return min({minLen1, minLen2, merge(target, nums, s, e)});
    }

    int helper1(int target, vector<int>&nums)
    {
        int s=0, e=0;
        int minLen = 1e9;
        int currSum = 0;

        while(e<nums.size())
        {
            currSum += nums[e];

            if(currSum>=target)
            {   
                while(currSum>=target)
                {   
                    minLen = min((e-s)+1,minLen);
                    currSum -= nums[s];
                    s++;
                }
            }

            e++;
        }

        return minLen==1e9? 0:minLen;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        
        // O(N) solution
        return helper1(target, nums);

        // O(nlogn) solution (Divide and conquer)
        int ans = helper2(target, nums, 0, nums.size()-1);
        return ans==1e9? 0:ans;

        /*
                            [2,3,1,2,4,3]
                                /   \
                            [2,3,1]  [2,4,3]
                            /   \     /    \
                        [2,3]  [1]  [2,4]  [3]
                        /  \         / \
                       [2] [3]      [2] [4]
        */
    }
};