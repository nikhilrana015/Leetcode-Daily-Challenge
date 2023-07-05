class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int s=0, e=0;
        int cntZeros = 0;
        int maxii = 0;
        int lastIdxZero = -1;

        while(e<nums.size())
        {
            if(nums[e]==0)
            {
                cntZeros+=1;

                if(cntZeros==1)
                {  
                    lastIdxZero = e;
                    e++;
                }
                    
                
                else if(cntZeros==2)
                {
                    s = lastIdxZero+1;
                    cntZeros=0;
                }
            }
            else
            {  
                e++;
            }

            maxii = max(maxii, (e-s+1)-max(1,cntZeros));
        }

        return max(0,maxii-1);
    }
};