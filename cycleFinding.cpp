/**
 *@file cycleFinding.cpp
 *@brief Solution to the CSES problem "Cycle Finding".
 *@link https://cses.fi/problemset/task/1197
 *
 *@details
 *The problem asks whether the graph has a negative-weight cycle and, if so, to print it.
 *Algorithm: Bellman-Ford with all distances initialized to 0 (equivalent to a super-source connected to every node).
 *If a relaxation still happens on the n-th iteration, there is a negative cycle; walking back n times through parent guarantees
 *that we are inside the cycle, which is then rebuilt by following the parents.
 *Complexity: O(n·m).
 */

#include <bits/stdc++.h>
using namespace std;

struct aresta
{
    int o, f;
    long long w;
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<aresta> list;
    for (int i = 0; i < m; i++)
    {
        aresta atual;
        cin >> atual.o >> atual.f >> atual.w;
        list.push_back(atual);
    }

    vector<int> parent(n + 1);
    vector<long long> dist(n + 1, 0);
    bool flag = false;
    int ciclo = -1;
    for (int i = 0; i < n; i++)
    {
        for (aresta atual : list)
        {
            int o = atual.o;
            int f = atual.f;
            long long w = atual.w;

            if (dist[f] > dist[o] + w)
            {
                dist[f] = dist[o] + w;
                parent[f] = o;
                if (i == n - 1)
                {
                    ciclo = f;
                    flag = true;
                    break;
                }
            }
        }
    }

    if(flag) {
        cout << "YES\n";
        for (int i =0; i<n; i++){
            ciclo = parent[ciclo];
        }

        vector<int> loop;
        int atual = ciclo;
        while(true){
            loop.push_back(atual);
            atual= parent[atual];
            if(atual == ciclo && loop.size() > 1){
                loop.push_back(atual);
                break;
            }
        }
        reverse(loop.begin(), loop.end());
        for(int v: loop){
            cout << v << " ";
        }
        cout << "\n";
    }
    return 0;
}