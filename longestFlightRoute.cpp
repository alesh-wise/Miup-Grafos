#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;

    vector<int> indegree(n + 1, 0);
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;
    vector<int> parent(n + 1, -1);

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> dist(n + 1, INT_MIN);
    dist[1] = 1;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();

        for (int next : graph[top])
        {
            if (dist[top] != INT_MIN && dist[next] < dist[top] + 1)
            {
                dist[next] = dist[top] + 1;
                parent[next] = top;
            }
            indegree[next]--;
            if (indegree[next] == 0)
            {
                q.push(next);
            }
        }
    }

    if (dist[n] == INT_MIN)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << dist[n] << "\n";
        vector<int> caminho;
        int atual = n;
        while (atual != -1)
        {
            caminho.push_back(atual);
            atual = parent[atual];
        }

        reverse(caminho.begin(), caminho.end());
        for (int i = 0; i < caminho.size(); i++)
        {
            cout << caminho[i] << (i == caminho.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}