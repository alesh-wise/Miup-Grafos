/**
 *@file subordinate.cpp
 *@brief Solution to the CSES problem "Subordinates".
 *@link https://cses.fi/problemset/task/1674
 *
 *@details
 *The problem asks for the number of subordinates (direct and indirect) of each employee.
 *Algorithm: DFS on the tree from the root (1) — each node's subtree size minus 1.
 *Complexity: O(n).
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> subor;
vector<vector<int>> graph;

void dfs(int start)
{
    subor[start] = 0;
    for (int next : graph[start])
    {
        dfs(next);
        subor[start] += 1 + subor[next];
    }
}

int main()
{
    int n;
    cin >> n;
    subor.assign(n + 1, 0);
    graph.resize(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int boss;
        cin >> boss;
        graph[boss].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << subor[i] << " ";
    }
    return 0;
}