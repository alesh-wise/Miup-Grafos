/**
 *@file policeChase.cpp
 *@brief Resolução do problema "Police Chase" do CSES.
 *@link https://cses.fi/problemset/task/1695
 *
 *@details
 *O problema pede o menor número de ruas a fechar para que não exista caminho entre o cruzamento 1 e o n.
 *Isto é um corte mínimo (min-cut): pelo teorema Max-Flow Min-Cut, o seu valor é igual ao fluxo máximo
 *de 1 para n com capacidade 1 em cada rua (nos dois sentidos, porque as ruas são não dirigidas).
 *Algoritmo: Edmonds-Karp (BFS para caminhos de aumento). No fim, faz-se uma BFS no grafo residual a partir de 1;
 *as ruas que ligam um nó alcançável a um não alcançável são exatamente as ruas do corte.
 *Complexidade: O(n·(n+m)) — o fluxo máximo é no máximo n-1 e cada BFS custa O(n+m).
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

    // Cada caminho de aumento tem gargalo 1 (todas as capacidades são 0/1/2)
    while (bfs())
    {
        for (int v = n; v != 1; v = pai[v])
        {
            int u = pai[v];
            cap[u][v]--;
            cap[v][u]++;
        }
    }

    // Após o fluxo máximo, pai[v] != -1 indica que v é alcançável a partir de 1 no grafo residual
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
