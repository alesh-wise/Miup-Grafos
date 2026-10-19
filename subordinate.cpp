/**
 *@file subordinate.cpp
 *@brief Resolução do problema "Subordinates" do CSES.
 *@link https://cses.fi/problemset/task/1674
 *
 *@details
 *O problema pede o número de subordinados (diretos e indiretos) de cada funcionário.
 *Algoritmo: DFS na árvore a partir da raiz (1) — o tamanho da subárvore de cada nó menos 1.
 *Complexidade: O(n).
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> subor;
vector<vector<int>> graph;

void dfs(int start)
{
    subor[start] = 0;
    for (int next : graph[start])
    {
        dfs(next);
        subor[start] += 1 + subor[next];
    }
}

int main()
{
    int n;
    cin >> n;
    subor.assign(n + 1, 0);
    graph.resize(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int boss;
        cin >> boss;
        graph[boss].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << subor[i] << " ";
    }
    return 0;
}