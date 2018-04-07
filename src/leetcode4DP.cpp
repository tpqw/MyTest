/*
 ***************************************************
 **The sulotion for the DP question from leetcode.**
 ***************************************************
 author:fwg
 date:2018.4.5
 */


//机器人位于一个 m x n 网格的左上角, 在下图中标记为“Start” (开始)。
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角，在下图中标记为“Finish”(结束)。
//问有多少条不同的路径？

//例如，上图是一个3 x 7网格。有多少可能的路径？
//注意: m 和 n 的值均不超过 100。
class Solution {
public:
    int uniquePaths(int m, int n) {
        int a[m][n] = { 0 };
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0)
                {
                    a[i][j] = 1;
                }
                else
                {
                    a[i][j] = a[i - 1][j] + a[i][j - 1];
                }
            }
        }
        return a[m - 1][n - 1];
    }
};

//这是“不同路径” 的进阶问题：
//现在考虑网格中有障碍物。那样将会有多少条不同的路径从左上角到右下角？
//网格中的障碍物和空位置分别用 1 和 0 来表示。
//例如，
//如下所示在 3x3 的网格中有一个障碍物。
//[
//  [0,0,0],
//  [0,1,0],
//  [0,0,0]
//]
//一共有 2 条不同的路径从左上角到右下角。
//注意: m 和 n 的值均不超过 100。
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1)
        {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m][n] = { 0 };
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else if (i ==0 && j == 0)
                {
                    dp[i][j] = 1;
                }
                else if (i == 0 && j > 0)
                {
                    dp[i][j] = dp[i][j - 1];
                }
                else if (j == 0 && i > 0)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

/*
给定一个只含非负整数的 m x n 网格，找到一条从左上角到右下角的可以使数字之和最小的路径。
注意: 每次只能向下或者向右移动一步。
示例 1:
[[1,3,1],
 [1,5,1],
 [4,2,1]]
根据上面的数组，返回 7. 因为路径 1→3→1→1→1 总和最小。*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
        {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n] = { 0 };
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0 )
                {
                    dp[i][j] = grid[i][j];
                }
                else if (i == 0 && j > 0)
                {
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                }
                else if (j == 0 && i > 0)
                {
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                }
                else
                {
                    dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
                }
            }
        }
        
        return dp[m - 1][n - 1];
    }
};

/*
你正在爬楼梯。需要 n 步你才能到达顶部。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方式可以爬到楼顶呢？
注意：给定 n 将是一个正整数。
 
示例 1：
输入： 2
输出： 2
说明： 有两种方法可以爬到顶端。

1.  1 步 + 1 步
2.  2 步
 
示例 2：
输入： 3
输出： 3
说明： 有三种方法可以爬到顶端。

1.  1 步 + 1 步 + 1 步
2.  1 步 + 2 步
3.  2 步 + 1 步
*/

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0)
        {
            return 0;
        }
        int dp[n] = { 0 };
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                dp[i] = 1;
            }
            else if (i == 1)
            {
                dp[i] = 2;
            }
            else
            {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
        }
        return dp[n - 1];
    }
};

/*
给出两个单词 word1 和 word2，找出将 word1 转换成 word2 所使用的最少的步骤数 (每个操作记为一步)。
你可以对一个单词进行以下三种操作：
a) 插入一个字符
b) 删除一个字符
c) 替换一个字符

*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        int dp[len1 + 1][len2 + 1] = { 0 };
        for (int i = 0; i <= len1; i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j <= len2; j++)
        {
            dp[0][j] = j;
        }
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    //删除一个字符：word1[i-2]到word2[j-1]的最少步骤数+1（删掉word1[i-1]）
                    //替换一个字符：word1[i-2]到word2[j-2]的最少步骤数+1（替换word1[i-1]为word2[j-1]）
                    //插入一个字符：word1[i-1]到word2[j-2]的最少步骤数+1（插入word2[j-1]）
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                }
            }
        }
        return dp[len1][len2];
    }
};

