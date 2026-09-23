//
// Created by alesh-wise on 23/09/2026.
//
/**
 *@file shortestRoute1.cpp
 *@brief Resolução do problema "Shortest Route II" do CSES.
 *@link https://cses.fi/problemset/result/18837199/
 *
 *@details
 *O problema pede a distancia minima entre diferentes trajetos, sendo necessario calcular o trajeto minimo de cada um dos pontos do grafo para todos os outros pontos.
 *Foi usado o algortimo de Fçoyd-Warshall.
 */
//
// Created by alesh-wise on 23/09/2026.
//



#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    long long grid[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            grid[i][j] = LLONG_MAX;
        }
        grid[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        grid[a - 1][b - 1] = min(grid[a - 1][b - 1], c);
        grid[b - 1][a - 1] = min(grid[b - 1][a - 1], c);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (grid[j][i] != LLONG_MAX && grid[i][k] != LLONG_MAX)
                {
                    grid[j][k] = min(grid[j][k], grid[j][i] + grid[i][k]);
                }
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        if(grid[a-1][b-1] == LLONG_MAX) {
            cout << -1 << "\n";
        } else {  
            cout << grid[a - 1][b - 1] << "\n";
        }
    }
    cout << "\n";
    return 0;
}