class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int size = nums.size();

        while(left<=right)
        {
            int mid = (left+right)/2;

            if(nums[mid]==target)
                return mid;

            if(nums[left]<=nums[mid])
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
        }

        return -1;
    }
};
