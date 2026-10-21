//
// Created by alesh-wise on 23/09/2026.
//
/**
 *@file shortestRouteII.cpp
 *@brief Solution to the CSES problem "Shortest Route II".
 *@link https://cses.fi/problemset/result/18837199/
 *
 *@details
 *The problem asks for the minimum distance for several queries, so the shortest path from every point of the graph to every other point must be computed.
 *The Floyd-Warshall algorithm (all-pairs shortest paths) is used, taking each node as an intermediate.
 *Complexity: O(n³) + O(1) per query.
 */
//
// Created by alesh-wise on 23/09/2026.
//



#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    long long grid[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            grid[i][j] = LLONG_MAX;
        }
        grid[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        grid[a - 1][b - 1] = min(grid[a - 1][b - 1], c);
        grid[b - 1][a - 1] = min(grid[b - 1][a - 1], c);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (grid[j][i] != LLONG_MAX && grid[i][k] != LLONG_MAX)
                {
                    grid[j][k] = min(grid[j][k], grid[j][i] + grid[i][k]);
                }
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        if(grid[a-1][b-1] == LLONG_MAX) {
            cout << -1 << "\n";
        } else {  
            cout << grid[a - 1][b - 1] << "\n";
        }
    }
    cout << "\n";
    return 0;
}