#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<long long> path(n + 1, 0);
    path[1] = 1;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();

        for (int next : graph[top])
        {
            path[next] = (path[next] + path[top]) % MOD;

            indegree[next]--;
            if(indegree[next] == 0) q.push(next);
        }
    }

    cout << path[n] << "\n";
    return 0;
}