class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        if(nums.size()<k)
            return {};

        vector<int>ans;
        deque<int>dq;
        
        int left = 0;

        for(int right=0; right<nums.size(); right++)
        {
            while(!dq.empty() and nums[dq.back()]<nums[right])
                dq.pop_back();
            
            while(!dq.empty() and dq.front()<left)
                dq.pop_front();

            dq.push_back(right);
            
            if(right>=k-1)
            {
                ans.push_back(nums[dq.front()]);
                left+=1;
            }
        }

        return ans;

    }
};
