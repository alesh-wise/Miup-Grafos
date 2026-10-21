//
// Created by alesh-wise on 20/09/2026.
//
/**
 *@file roundTrip.cpp
 *@brief Solution to the CSES problem "Round Trip".
 *@link https://cses.fi/problemset/result/18812072/
 *
 *@details
 *The problem asks to find a cycle in an undirected graph. If one exists, it must be printed.
 *Algorithm: DFS ignoring the edge to the parent — finding an already visited neighbor means a cycle (back edge),
 *which is rebuilt using the path vector.
 *Complexity: O(n + m).
 */
//
// Created by alesh-wise on 20/09/2026.
//


#include <bits/stdc++.h>
using namespace std;


static int inicio = -1, fim = -1;
static vector<bool> visited;
static vector<int> path;
static vector<vector<int>> graph;

static void dfs(int current, int parent) {
    visited[current] = true;

    for (int neighbor : graph[current]) {
        if (neighbor == parent) continue;

        if (!visited[neighbor]) {
            path[neighbor] = current;
            dfs(neighbor, current);
            if (inicio != -1) return; 
        } 
        else {
            
            inicio = neighbor;
            fim = current;
            return;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    
    graph.resize(n + 1);
    visited.assign(n + 1, false);
    path.assign(n + 1, -1);
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i, -1);
            if(inicio != -1) break;
        }
    }

    if(inicio == -1){
        cout << "IMPOSSIBLE\n";
    } else {
    
        vector<int> ciclo;
        ciclo.push_back(inicio);
        
        for (int v = fim; v != inicio; v = path[v]) {
            ciclo.push_back(v);
        }
        ciclo.push_back(inicio); 
        
        reverse(ciclo.begin(), ciclo.end());
        
        cout << ciclo.size() << "\n";
        for (int i = 0; i < ciclo.size(); i++) {
            cout << ciclo[i] << (i == ciclo.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}