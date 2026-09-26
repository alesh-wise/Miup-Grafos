#include <bits/stdc++.h>
using namespace std;

struct aresta {
    int destino;
    long long peso;
    
};

struct estado {
    int cidade;
    long long custo;
    int usou_cupao;
    bool operator<(const estado& outra) const {
        return this->custo> outra.custo;
    }
};

int main() {

    int n,m;
    cin >> n >> m;
    vector<vector<aresta>> graph(n+1); 
    for (int i=0; i< m; i++){
        int a,b;
        long long c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }
    vector<vector<long long>> dist(n+1, vector<long long>(2,LLONG_MAX));
    priority_queue<estado> pq;
    dist[1][0]=0;
    pq.push({1,0,0});

    while(!pq.empty()){
        estado atual = pq.top();
        pq.pop();

        int u = atual.cidade;
        long long d = atual.custo;
        int estado = atual.usou_cupao;

        if(d > dist[u][estado]) continue;

        for ( aresta a : graph[u]){
            int v = a.destino;
            long long peso = a.peso;

            if( d + peso < dist[v][estado]){
                dist[v][estado] = d + peso;
                pq.push({v, dist[v][estado], estado});
            }

            if ( estado ==0){
                long long peso_desconto = peso /2;

                if ( d + peso_desconto < dist[v][1]){
                    dist[v][1] = d + peso_desconto;
                    pq.push({v, dist[v][1],1});
                }
            }
        }
    }

    cout << dist[n][1] << "\n";



    return 0;
}