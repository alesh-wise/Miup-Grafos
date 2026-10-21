/**
 *@file planetsCycles.cpp
 *@brief Solution to the CSES problem "Planets Cycles".
 *@link https://cses.fi/problemset/task/1751
 *
 *@details
 *The problem asks, for each planet, how many teleports are made until a planet repeats.
 *Algorithm: walk the functional graph (each node has exactly one outgoing edge) while storing the current path;
 *when a node already on the path is found, the cycle is identified (all its nodes have answer = cycle length),
 *and the "tail" nodes get the answer of the next node + 1, filled in from back to front.
 *Complexity: O(n).
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> graph(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> graph[i];
    }

    vector<int> t(n + 1, 0);
    vector<int> visitado(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (t[i] != 0)
            continue;
        vector<int> viagem;
        int atual = i;
        while (t[atual] == 0 && visitado[atual] == 0)
        {
            viagem.push_back(atual);
            visitado[atual] = viagem.size();
            atual= graph[atual];
        }

        int distancia_base = 0;

        if(t[atual] !=0){
            distancia_base=t[atual];
        }else{
            int inicio_ciclo = visitado[atual] -1;
            int tamanho_ciclo =viagem.size() - inicio_ciclo;
            for(int j = inicio_ciclo; j < viagem.size(); j++){
                t[viagem[j]] =tamanho_ciclo;
            }

            viagem.resize(inicio_ciclo);
            distancia_base = tamanho_ciclo;
        }
        for(int j = (int)viagem.size() -1; j >= 0; j--) {
            distancia_base++;
            t[viagem[j]] = distancia_base;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << t[i] << " ";
    }
    cout << "\n";
    return 0;
}