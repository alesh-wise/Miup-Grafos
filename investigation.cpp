#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
struct aresta
{
    int v;
    long long w;
};

struct estado
{
    int v;
    long long custo;
    bool operator<(const estado &outro) const
    {
        return this->custo > outro.custo;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<aresta>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    vector<long long> dist(n + 1, LLONG_MAX);
    vector<long long> routes(n + 1, 0);
    vector<long long> min_f(n + 1, 0);
    vector<long long> max_f(n + 1, 0);
    dist[1] = 0;
    routes[1] = 1;
    priority_queue<estado> pq;
    pq.push({1, 0});

    while (!pq.empty())
    {
        estado atual = pq.top();
        pq.pop();

        for (aresta adj : graph[atual.v])
        {
            int v = adj.v;
            long long peso = adj.w;
            long long novo_peso = peso + atual.custo;

            if (novo_peso < dist[v])
            {
                dist[v] = novo_peso;
                routes[v] = routes[atual.v];
                min_f[v] = min_f[atual.v] + 1;
                max_f[v] = max_f[atual.v] + 1;

                pq.push({v, novo_peso});
            }

            else if (novo_peso == dist[v])
            {
                routes[v] = (routes[v] + routes[atual.v]) % MOD;
                min_f[v] = min(min_f[v], min_f[atual.v] + 1);
                max_f[v] = max(max_f[v], max_f[atual.v] + 1);
            }
        }
    }
    cout << dist[n] << " " << routes[n] << " " << min_f[n] << " " << max_f[n] << "\n";
    return 0;
}