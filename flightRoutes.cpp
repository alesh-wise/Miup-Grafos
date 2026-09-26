#include <bits/stdc++.h>
using namespace std;

struct aresta
{
    int v;
    long long w;
    bool operator<(const aresta &outro) const
    {
        return this->w > outro.w;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<aresta>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        aresta atual;
        int o;
        cin >> o >> atual.v >> atual.w;
        graph[o].push_back(atual);
    }

    vector<priority_queue<long long>> dist(n + 1);
    priority_queue<aresta> pq;
    pq.push({1, 0});

    while (!pq.empty())
    {
        aresta atual = pq.top();
        pq.pop();

        int o = atual.v;
        long long w = atual.w;

        if (dist[o].size() == k && w > dist[o].top())
            continue;

        for (aresta adj : graph[o])
        {
            int f = adj.v;
            long long peso = adj.w;
            long long novo_custo = peso + w;

            if (dist[f].size() < k)
            {
                dist[f].push(novo_custo);
                pq.push({f, novo_custo});
            }

            else if (novo_custo < dist[f].top())
            {
                dist[f].pop();
                dist[f].push(novo_custo);
                pq.push({f, novo_custo});
            }
        }
    }

    vector<long long> resposta;
    for (int i = 0; i < k; i++)
    {
        resposta.push_back(dist[n].top());
        dist[n].pop();
    }

    reverse(resposta.begin(), resposta.end());

    for (int i = 0; i < k; i++)
    {
        cout << resposta[i] << (i == k - 1 ? "" : " ");
    }
    cout << "\n";
    return 0;

    return 0;
}