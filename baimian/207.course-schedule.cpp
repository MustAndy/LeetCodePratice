/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (38.85%)
 * Likes:    2154
 * Dislikes: 102
 * Total Accepted:    253.2K
 * Total Submissions: 647K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * Example 1:
 * 
 * 
 * Input: 2, [[1,0]] 
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * Example 2:
 * 
 * 
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 * 
 * 
 * Note:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 */
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> degrees = computeIndegrees(g);
        for (int i = 0; i < numCourses; i++)
        {
            int j = 0;
            for (; j < numCourses; j++)
            {
                if (!degrees[j])
                {
                    break;
                }
            }
            if (j == numCourses)
            {
                return false;
            }
            degrees[j]--;
            for (int v : g[j])
            {
                degrees[v]--;
            }
        }
        return true;
    }

private:
    typedef vector<vector<int>> graph;

    graph buildGraph(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        graph g(numCourses);
        for (auto p : prerequisites)
        {
            g[p.second].push_back(p.first);
        }
        return g;
    }

    vector<int> computeIndegrees(graph &g)
    {
        vector<int> degrees(g.size(), 0);
        for (auto adj : g)
        {
            for (int v : adj)
            {
                degrees[v]++;
            }
        }
        return degrees;
    }
};