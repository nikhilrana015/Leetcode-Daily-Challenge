/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<TreeNode*> helper(int s, int e)
    {
        if(s>e)
            return {nullptr};

        if(s==e)
            return {new TreeNode(s)};


        vector<TreeNode*>ans;

        for(int i=s; i<=e; i++)
        {
            vector<TreeNode*>left = helper(s, i-1);
            vector<TreeNode*>right = helper(i+1, e);

            for(auto k: left)
            {
                for(auto m: right)
                {
                    if((k==nullptr or i>k->val) and (m==nullptr or i<m->val))
                    {   
                        TreeNode *root = new TreeNode(i);
                        root->left = k;
                        root->right = m;
                        ans.push_back(root);
                    }
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(n==1)
            return {new TreeNode(1)};

        return helper(1, n);
    }
};
