//
// Created by alesh-wise on 20/09/2026.
//
/**
 *@file shortestRoute1.cpp
 *@brief Resolução do problema "Shortest Route I" do CSES.
 *@link https://cses.fi/problemset/task/1671
 *
 *@details
 *O problema pede a distancia minima de um determinado ponto para todos os outros pontos do grafo.
 */
//
// Created by alesh-wise on 20/09/2026.
//

#include <bits/stdc++.h>
using namespace std;

class node {
    public:
    int lig;
    long long weight;
    node(int lig, long long weight){
        this->lig = lig;
        this->weight = weight;
    }
    node(){}

    bool operator<(const node &other) const {
        return weight > other.weight;
    }
};


int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<node>> graph(n+1);

    for( int i =0; i< m; i++){
        int a,b;
        long long w;
        cin >> a >> b >> w;
        graph[a].push_back(node(b,w));
    }
    vector<long long> dist(n+1, LLONG_MAX);
    priority_queue<node> pq;        
    dist[1] = 0;
    pq.push(node(1,0));
    while(!pq.empty()){
        node current = pq.top();
        pq.pop();
        int v = current.lig;
        long long d = current.weight;
        if (d > dist[v]) continue;
        for (node adj: graph[v]) {
            int v_adj = adj.lig;
            long long w_adj = adj.weight;
            if(dist[v_adj] > d + w_adj){
                dist[v_adj] = d + w_adj;
                pq.push(node(v_adj, dist[v_adj]));
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
    cout << "\n";
    return 0;
}