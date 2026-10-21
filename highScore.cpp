/**
 *@file highScore.cpp
 *@brief Solution to the CSES problem "High Score".
 *@link https://cses.fi/problemset/task/1673
 *
 *@details
 *The problem asks for the maximum score from 1 to n, or -1 if the score can be arbitrarily large.
 *Algorithm: Bellman-Ford with negated weights (longest path = shortest path with negative weights).
 *After n-1 iterations, another n iterations are run to propagate -INF to every node affected
 *by a negative cycle; if n is affected, the answer is -1.
 *Complexity: O(n·m).
 */

#include <bits/stdc++.h>
using namespace std;
const long long NINF = -1e17;
struct aresta
{
    int origem, destino;
    long long peso;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<aresta> grafo(m);

    for ( int i=0; i<m;i++){
        cin >> grafo[i].origem >> grafo[i].destino >> grafo[i].peso;

        grafo[i].peso = -grafo[i].peso;
    }

    vector<long long> dist(n+1 ,LLONG_MAX);
    dist[1]=0;

    for ( int i=1; i<n; i++){
        for ( aresta a: grafo) {
            if(dist[a.origem] != LLONG_MAX && dist[a.origem] +a.peso < dist[a.destino]) {
                dist[a.destino] = dist[a.origem] +a.peso;
            }
        }
    }

    for(int i=1; i<=n ;i++){
        for ( aresta a: grafo){
            if(dist[a.origem] !=LLONG_MAX && dist[a.origem] + a.peso < dist[a.destino]){
                dist[a.destino] = NINF;
            }
        }
    }

    if( dist[n] == NINF){
        cout << -1 << "\n";
    } else {
        cout << -dist[n] << "\n";
    }
    return 0;
}