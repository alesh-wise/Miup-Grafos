/**
 *@file mailDelivery.cpp
 *@brief Resolução do problema "Mail Delivery" do CSES.
 *@link https://cses.fi/problemset/task/1691
 *
 *@details
 *O problema pede um circuito que comece e acabe na cidade 1 e passe por cada rua exatamente uma vez.
 *Algoritmo: Circuito Euleriano com o algoritmo de Hierholzer (versão iterativa com pilha).
 *É impossível se algum nó tiver grau ímpar ou se nem todas as arestas forem alcançáveis a partir de 1.
 *Complexidade: O(n + m).
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> degree(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back({b, i});
        graph[b].push_back({a, i});
        degree[a]++;
        degree[b]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (degree[i] % 2 != 0)
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    vector<int> currPath;
    currPath.push_back(1);

    vector<int> circuit;
    vector<bool> visited(m, false);
    while (currPath.size() > 0)
    {
        int currNode = currPath[currPath.size() - 1];
        bool edge_found = false;
        while (!graph[currNode].empty())
        {
            auto [nextNode, edge_idx] = graph[currNode].back();
            graph[currNode].pop_back();

            if (!visited[edge_idx])
            {
                visited[edge_idx] = true;
                currPath.push_back(nextNode);
                edge_found = true;
                break;
            }
        }
        if (!edge_found)
        {
            circuit.push_back(currNode);
            currPath.pop_back();
        }
    }
    if (circuit.size() != m + 1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    reverse(circuit.begin(), circuit.end());

    for (int i = 0; i < circuit.size(); i++)
    {
        cout << circuit[i] << " ";
    }

    return 0;
}