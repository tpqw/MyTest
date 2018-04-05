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

