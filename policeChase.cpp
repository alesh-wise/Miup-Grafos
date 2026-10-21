/**
 *@file policeChase.cpp
 *@brief Solution to the CSES problem "Police Chase".
 *@link https://cses.fi/problemset/task/1695
 *
 *@details
 *The problem asks for the minimum number of streets to close so that there is no path between crossing 1 and n.
 *This is a minimum cut (min-cut): by the Max-Flow Min-Cut theorem, its value equals the maximum flow
 *from 1 to n with capacity 1 on each street (in both directions, since the streets are undirected).
 *Algorithm: Edmonds-Karp (BFS for augmenting paths). At the end, a BFS is run on the residual graph from 1;
 *the streets connecting a reachable node to an unreachable one are exactly the cut streets.
 *Complexity: O(n·(n+m)) — the max flow is at most n-1 and each BFS costs O(n+m).
 */

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<vector<int>> cap;
vector<int> pai;

bool bfs()
{
    pai.assign(n + 1, -1);
    pai[1] = 1;
    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (pai[v] == -1 && cap[u][v] > 0)
            {
                pai[v] = u;
                q.push(v);
            }
        }
    }
    return pai[n] != -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    adj.assign(n + 1, {});
    cap.assign(n + 1, vector<int>(n + 1, 0));
    vector<pair<int, int>> ruas(m);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        ruas[i] = {a, b};
        adj[a].push_back(b);
        adj[b].push_back(a);
        cap[a][b] = 1;
        cap[b][a] = 1;
    }

    // Every augmenting path has bottleneck 1 (all capacities are 0/1/2)
    while (bfs())
    {
        for (int v = n; v != 1; v = pai[v])
        {
            int u = pai[v];
            cap[u][v]--;
            cap[v][u]++;
        }
    }

    // After the max flow, pai[v] != -1 means v is reachable from 1 in the residual graph
    vector<pair<int, int>> corte;
    for (auto [a, b] : ruas)
    {
        if ((pai[a] != -1) != (pai[b] != -1))
            corte.push_back({a, b});
    }

    cout << corte.size() << "\n";
    for (auto [a, b] : corte)
        cout << a << " " << b << "\n";

    return 0;
}
