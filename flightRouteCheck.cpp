#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<int> scc_id;
int scc_count;
stack<int> s;


void dfs(int start, vector<vector<int>>& list, stack<int>& stack)
{
    visited[start] = true;
    for (int v : list[start])
    {
        if(!visited[v]) dfs(v,list,stack);
    }
    stack.push(start);
}

void dfs1(int start, vector<vector<int>>& list) {
    visited[start] = true;
    scc_id[start] = scc_count;
    for(int v : list[start]) {
        if(!visited[v]) {
            dfs1(v,list);
        }
    }
}


int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<vector<int>> inverso(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        inverso[b].push_back(a);
    }
    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i, graph, s);
    }
    visited.assign(n + 1, false);
    scc_count = 0;
    scc_id.assign(n + 1, 0);
    vector<int> conexos;
    while(!s.empty()) {
        int i = s.top();
        s.pop();
        if(!visited[i]) {
            dfs1(i, inverso);
            conexos.push_back(i);
            scc_count++;
        }
    }
    if(scc_count == 1) {cout << "YES";}else{
        cout << "NO\n";
        cout << conexos[1] << " " << conexos[0];
    }
    return 0;
}
