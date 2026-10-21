/**
 *@file schoolDance.cpp
 *@brief Solution to the CSES problem "School Dance".
 *@link https://cses.fi/problemset/task/1696
 *
 *@details
 *The problem asks for the largest set of (boy, girl) pairs such that each person dances at most once,
 *given a set of compatible pairs.
 *Algorithm: Bipartite Matching (Kuhn's algorithm) — for each boy, try to find a free girl
 *through augmenting paths, reassigning existing matches when needed.
 *Complexity: O(n·m) in the worst case (n girls, m edges).
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
