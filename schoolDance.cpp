/**
 *@file schoolDance.cpp
 *@brief Resolução do problema "School Dance" do CSES.
 *@link https://cses.fi/problemset/task/1696
 *
 *@details
 *O problema pede o maior conjunto de pares (rapaz, rapariga) tal que cada pessoa dance no máximo uma vez,
 *dado um conjunto de pares compatíveis.
 *Algoritmo: Emparelhamento Bipartido (algoritmo de Kuhn) — para cada rapaz, tenta-se encontrar uma rapariga
 *livre através de caminhos de aumento (augmenting paths), remarcando emparelhamentos já feitos quando necessário.
 *Complexidade: O(n·m) no pior caso (n raparigas, m arestas).
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> matchGirl;
vector<bool> visitado;

bool tentarEmparelhar(int rapaz)
{
    for (int rapariga : adj[rapaz])
    {
        if (visitado[rapariga])
            continue;
        visitado[rapariga] = true;

        if (matchGirl[rapariga] == 0 || tentarEmparelhar(matchGirl[rapariga]))
        {
            matchGirl[rapariga] = rapaz;
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    adj.assign(n + 1, {});
    matchGirl.assign(m + 1, 0);

    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    int pares = 0;
    for (int rapaz = 1; rapaz <= n; rapaz++)
    {
        visitado.assign(m + 1, false);
        if (tentarEmparelhar(rapaz))
            pares++;
    }

    cout << pares << "\n";
    for (int rapariga = 1; rapariga <= m; rapariga++)
    {
        if (matchGirl[rapariga] != 0)
            cout << matchGirl[rapariga] << " " << rapariga << "\n";
    }

    return 0;
}
