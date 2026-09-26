#include <bits/stdc++.h>
using namespace std;

static vector<bool> inCall;
static int inicio = -1, fim = -1;
static vector<bool> visited;
static vector<int> origem;

void dfs(int current, const vector<vector<int>> &graph)
{
    visited[current] = true;
    inCall[current] = true;

    for (int adj : graph[current])
    {
        if (!visited[adj])
        {
            origem[adj] = current;
            dfs(adj, graph);
            if (inicio != -1)
                break;
        }
        else if (inCall[adj])
        {
            fim = current;
            inicio = adj;
            return;
        }
    }

    inCall[current] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    inCall.assign(n + 1, false);
    visited.assign(n + 1, false);
    origem.assign(n + 1, -1);
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        dfs(i, graph);
        if(inicio!=-1) break;
    }

    if (inicio == -1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> caminho;
    int atual = fim;
    while (atual != inicio)
    {
        caminho.push_back(atual);
        atual = origem[atual];
    }
    caminho.push_back(atual);
    reverse(caminho.begin(), caminho.end());
    caminho.push_back(inicio);
    cout << caminho.size() << "\n";
    for (int i = 0; i < caminho.size(); i++)
    {
        cout << caminho[i] << " ";
    }
    cout << "\n";

    return 0;
}