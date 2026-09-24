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