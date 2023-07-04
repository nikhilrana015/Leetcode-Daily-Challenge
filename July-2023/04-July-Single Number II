class Solution {
public:

    int firstApproach(vector<int>&nums)
    {
        unordered_map<int,int>umap;

        for(auto v: nums)
        {
            umap[v]++;
        }

        for(auto v: umap)
        {
            if(v.second%3==1)
                return v.first;
        }

        return -1;
    }

    int secondApproach(vector<int>&nums)
    {
        vector<int>cntBits(32,0);

        for(int i=0; i<nums.size(); i++)
        {   
            int currVal = nums[i];

            for(int j=0; j<32; j++)
            {
                int val = currVal&1;
                if(val!=0)
                    cntBits[j]++;
                
                currVal = currVal>>1;
            }
        }

        int number = 0;

        for(int i=0; i<32; i++)
        {
            if(cntBits[i]%3!=0)
            {
                number += (1<<i);
            }
        }

        return number;
    }


    int singleNumber(vector<int>& nums) {
        //return firstApproach(nums);
        return secondApproach(nums);
    }
};