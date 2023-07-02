class Solution {
public:

    int helper(int idx, vector<vector<int>>& requests, vector<int>&compute, int req)
    {
        if(idx==requests.size())
        {
            for(int i=0; i<compute.size(); i++)
            {
                if(compute[i]!=0)
                    return 0;
            }

            return req;
        }

        vector<int>vec = requests[idx];
        int src = vec[0];
        int dst = vec[1];

        int op1,op2;
        op1 = op2 = 0;

        op1 = helper(idx+1, requests, compute, req);

        compute[src]-=1;
        compute[dst]+=1;
        op2 = helper(idx+1, requests, compute, req+1);
        compute[src]+=1;
        compute[dst]-=1;

        return max(op1,op2);

    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        
        vector<int>compute(n,0);
        return helper(0, requests, compute, 0);
    }
};