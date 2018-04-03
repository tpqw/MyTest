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

//The longest common prefix between multiple strings.
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if (!strs.size())
        {
            return res;
        }
        for (int i = 0; i < strs[0].size(); i++)
        {
            char tmpchar = strs[0][i];
            for (auto s : strs)
            {
                if (i > s.size() || tmpchar != s[i])
                {
                    return res;
                }
            }
            res += tmpchar;
        }
        return res;
    }
};

//有效的括号，使用栈进行处理
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++)
        {
            char tmpchar = s[i];
            switch (tmpchar)
            {
                case '(':
                case '{':
                case '[':
                    stk.push(tmpchar);
                    break;
                case ')':
                    if (stk.empty() || stk.top() != '(')
                    {
                        return false;
                    }
                    else
                    {
                        stk.pop();
                    }
                    break;
                case '}':
                    if (stk.empty() || stk.top() != '{')
                    {
                        return false;
                    }
                    else
                    {
                        stk.pop();
                    }
                    break;
                case ']':
                    if (stk.empty() || stk.top() != '[')
                    {
                        return false;
                    }
                    else
                    {
                        stk.pop();
                    }
                    break;
                default:
                    return false;
                        
            }
        }
        if (!stk.empty())
        {
            return false;
        }
        return true;
    }
};

//合并两个有序列表，使用递归
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }
        if (l1->val > l2->val)
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        else
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
    }
};

//移除有序数组中相邻重复的多余元素
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        
        int newBack = 0, cur = 1, len = nums.size();
        while (cur < len)
        {
            if (nums[newBack] == nums[cur])
            {
                cur++;
            }
            else
            {
                nums[++newBack] = nums[cur++];
            }
        }
        
        return newBack + 1;
    }
};

//移除数组中指定元素
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())
        {
            return 0;
        }
        int newback = 0, cur = 0, len = nums.size();
        while (cur < len)
        {
            if (nums[cur] == val)
            {
                cur++;
            }
            else
            {
                nums[newback++] = nums[cur++];
            }
        }
        return newback;
    }
};

//实现 strStr()。
//返回蕴含在 haystack 中的 needle 的第一个字符的索引，如果 needle 不是 haystack 的一部分则返回 -1 
//使用KMP算法
class Solution {
public:
    void getnext(const string &str, int next[])
    {
        int i = 0, j = -1;
        next[0] = -1;
        int n = str.size();
        while (i < n)
        {
            if (j == -1 || str[i] == str[j])
            {
                next[++i] = ++j;
            }
            else
            {
                j = next[j];
            }
        }
        
    }
    int strStr(string haystack, string needle) {
        if (needle.empty())
        {
            return 0;
        }
        int m = haystack.size();
        int n = needle.size();
        int i = 0, j = 0;
        int next[n];
        getnext(needle, next);
        while (i < m && j < n)
        {
            if (j == -1 || haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                j = next[j];
            }
        }
        if (j == n)
        {
            return i - j;
        }
        else
        {
            return -1;
        }
    }
};

//给定一个排序数组和一个目标值，如果在数组中找到目标值则返回索引。如果没有，返回到它将会被按顺序插入的位置。
//你可以假设在数组中无重复元素。
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty())
        {
            return 0;
        }
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] >= target)
            {
                return i;
            }
            else
            {
                i++;
            }
        }
        return i;
    }
};

//给定一个字符串， 包含大小写字母、空格 ' '，请返回其最后一个单词的长度。
//如果不存在最后一个单词，请返回 0 。
//注意事项：一个单词的界定是，由字母组成，但不包含任何的空格。
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty())
        {
            return 0;
        }
        int end = s.size() - 1;
        while (end >= 0 && s[end] == ' ')
        {
            end--;
        }
        int p = end;
        while (p >= 0 && s[p] != ' ')
        {
            p--;
        }
        return end - p;
    }
};