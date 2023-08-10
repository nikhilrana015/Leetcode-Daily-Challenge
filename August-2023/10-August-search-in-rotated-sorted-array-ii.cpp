class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        int left = 0;
        int right = nums.size()-1;

        if(nums[left]==target or nums[right]==target)
            return true;

        while(right-1>=0 and nums[right]==nums[right-1])
            right-=1;

        while(left+1<size and nums[left]==nums[left+1])
            left+=1;

        while(left<=right)
        {
            int mid = (left+right)/2;

            if(nums[mid]==target)
                return true;

            else if(nums[left]<=nums[mid])
            {
                if(target>=nums[left] and target<nums[mid])
                    right = mid-1;
                else
                    left = mid+1;
            }
            else
            {
                if(target>nums[mid] and target<=nums[right])
                    left = mid+1;
                else
                    right = mid-1;

            }

            while(right-1>=0 and nums[right]==nums[right-1])
                    right-=1;

            while(left+1<size and nums[left]==nums[left+1])
                    left+=1;
        }

        return false;
    }
};
