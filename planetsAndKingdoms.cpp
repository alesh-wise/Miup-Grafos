#include <bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<int> order;
vector<int> scc_id;
vector<vector<int>> sccs;

vector<vector<int>> graph;
vector<vector<int>> graphR;
int scc_count;

void dfs(int start, vector<vector<int>> &graph)
{
    visited[start] = true;
    for (int v : graph[start])
    {
        if (!visited[v])
            dfs(v, graph);
    }
    order.push_back(start);
}

void dfs1(int start, vector<vector<int>> &graph)
{
    visited[start] = true;
    scc_id[start] = scc_count;
    sccs.back().push_back(start);
    for (int v : graph[start])
    {
        if (!visited[v])
            dfs1(v, graph);
    }
}

void kosaraju(int n)
{
    sccs.clear();
    scc_count =0;
    visited.assign(n+1,false);
    for(int i = 1; i<=n;i++) {
        if(!visited[i]) dfs(i,graph);
    }
    visited.assign(n+1,false);
    scc_id.assign(n+1,0);
    vector<int> conexos;

    for(int i = order.size()-1; i>=0; i--) {
        int u = order[i];
        if(!visited[u]){
            sccs.push_back({});
            dfs1(u,graphR);
            conexos.push_back(u);
            scc_count++;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    graphR.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graphR[b].push_back(a);
    }
    kosaraju(n);
    cout << scc_count << "\n";
    for(int i =1; i <=n; i++) {
        cout << scc_id[i] +1 << " ";
    }
    return 0;
}