class Solution {
public:

    vector<vector<int>>ans;

    void helper(int n, int k, int no, vector<int>&curr)
    {
        if(curr.size()==k)
        {
            ans.push_back(curr);
            return;
        }

        if(no>n)
            return;

        curr.push_back(no);
        helper(n, k, no+1, curr);
        curr.pop_back();

        helper(n, k, no+1, curr);
    }

    void helper2(int n, int k, int no, vector<int>&curr)
    {
        if(curr.size()==k)
        {
            ans.push_back(curr);
            return;
        }

        if(no>n)
            return;

        for(int i=no; i<=n; i++)
        {
            curr.push_back(i);
            helper(n, k, i+1, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int>curr;
        helper2(n, k, 1, curr);
        return ans;
    }
};
