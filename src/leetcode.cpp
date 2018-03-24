/*********************
Description:MiniMum-depth-of-binary-tree.
            Given a binary tree, find its minimum depth.
            The minimum depth is the number of nodes along 
            the shortest path from the root node down to the nearest leaf node.
Author:fwg
Date:2018.3.24
**********************/

class Solution {
public:
    int run(TreeNode *root) {
        if (root == NULL)
        {
            return 0;
        }
        int curheight = 1;
        int minheight = 1;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            minheight = curheight;
            queue<TreeNode*>::size_type size = que.size();
            for (queue<TreeNode*>::size_type i = 0; i < size; i++)
            {
                TreeNode* tmpNode = que.front();
                if (tmpNode->left == NULL && tmpNode->right == NULL)
                {
                    return minheight;
                }
                else
                {
                    curheight = minheight + 1;
                }
                que.pop();
                if (tmpNode->left != NULL)
                {
                    que.push(tmpNode->left);
                }
                if (tmpNode->right != NULL)
                {
                    que.push(tmpNode->right);
                }
            }
        }
        return minheight;
    }
};