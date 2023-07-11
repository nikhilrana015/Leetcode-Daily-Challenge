/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>parent;

    void findParent(TreeNode *root)
    {
        if(root==nullptr)
            return;

        if(root->left!=nullptr)
            parent[root->left] = root;

        if(root->right!=nullptr)
            parent[root->right] = root;

        findParent(root->left);
        findParent(root->right);
        
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findParent(root);
        queue<TreeNode*>q;
        unordered_map<TreeNode*,int>isVisited;
        isVisited[target] = 1;
        q.push(target);

        while(!q.empty() and k>0)
        {
            int size = q.size();

            while(size--)
            {
                TreeNode *currNode = q.front();
                q.pop();
                //cout<<currNode->val<<" ";

                if(currNode->left!=nullptr and isVisited.find(currNode->left)==isVisited.end())
                {
                    isVisited[currNode->left] = 1;
                    q.push(currNode->left);
                }

                if(currNode->right!=nullptr and isVisited.find(currNode->right)==isVisited.end())
                {
                    isVisited[currNode->right] = 1;
                    q.push(currNode->right);
                }

                if(parent.find(currNode)!=parent.end() and isVisited.find(parent[currNode])==isVisited.end())
                {
                    isVisited[parent[currNode]] = 1;
                    q.push(parent[currNode]);
                }

            }

            //cout<<"\n";
            k-=1;
        }

        vector<int>ans;

        while(q.size()>0)
        {   
            TreeNode *node = q.front();
            q.pop();
            ans.push_back(node->val);
        }

        //cout<<q.size();
        return ans;
        
    }
};