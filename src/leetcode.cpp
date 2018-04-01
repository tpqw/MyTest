/*********************
Description:MiniMum-depth-of-binary-tree.
            Given a binary tree, find its minimum depth.
            The minimum depth is the number of nodes along 
            the shortest path from the root node down to the nearest leaf node.
Author:fwg
Date:2018.3.24
**********************/

//BFS求树最小深度
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

/** 
Given a binary tree, return the preorder traversal of its nodes' values. 
For example:
Given binary tree{1,#,2,3}, 
   1
    \
     2
    /
   3

return[1,2,3]. 
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//递归求二叉树的前序遍历
class Solution {
public:
    void helper(TreeNode *root)
    {
        if (root != NULL)
        {
            res.push_back(root->val);
            helper(root->left);
            helper(root->right);
        }
    }
    vector<int> preorderTraversal(TreeNode *root) {
        helper(root);
        return res;
    }
private:
    vector<int> res;
};

//迭代求二叉树的前序遍历
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> stNode;
        if (root == NULL)
        {
            return res;
        }
        stNode.push(root);
        TreeNode* tmpNode;
        while (!stNode.empty())
        {
            tmpNode = stNode.top();
            stNode.pop();
            res.push_back(tmpNode->val);
            if (tmpNode->right != NULL)
            {
                stNode.push(tmpNode->right);
            }
            if (tmpNode->left != NULL)
            {
                stNode.push(tmpNode->left);
            }
        }
        return res;
    }
};

//罗马数到整数的转换，罗马数某个字母前面至多一个比它小，后面至多3个比它大
class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mRTI{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
			{'C', 100}, {'D', 500}, {'M', 1000}};
        int res = mRTI[s[0]];
        for (int i = 1; i < s.size(); i++)
        {
            if (mRTI[s[i]] <= mRTI[s[i - 1]])
            {
                res += mRTI[s[i]];
            }
            else
            {
                res += mRTI[s[i]] - 2 * mRTI[s[i - 1]];
            }
        }
        return res;
    }
};