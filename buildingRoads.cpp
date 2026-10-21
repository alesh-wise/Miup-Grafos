//
// Created by alesh-wise on 20/09/2026.
//
/**
 *@file buildingRoads.cpp
 *@brief Solution to the CSES problem "Building Roads".
 *@link https://cses.fi/problemset/result/18802671/
 *
 *@details
 *The problem asks for the number of missing edges needed to make the current graph connected, and which edges those are.
 *A breadth-first search (BFS) is used to find the separate components of the graph and create the missing edges.
 *Complexity: O(n + m).
 */



#include <iostream>
#include <queue>
#include <vector>

int main() {
    int n,m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> grid(n+1);
    int ponto,ligacao;
    for (int i = 0; i < m; i++) {
        std::cin >> ponto >> ligacao;
        grid.at(ponto).push_back(ligacao);
        grid.at(ligacao).push_back(ponto);
    }

    std::vector<int> isolados;
    std::vector visitados(n+1,false);
    std::queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (!visitados[i]) {
            q.push(i);
            isolados.push_back(i);
            while (!q.empty()) {
                int c = q.front();
                q.pop();
                if (!visitados[c]) {
                    visitados[c] = true;
                    for (int x: grid[c]) {
                        q.push(x);
                    }
                }
            }
        }
    }

    int contagem = isolados.size();
    std::cout << contagem-1 << "\n";

    for (int i = 0; i < contagem-1; i++) {
        std::cout << isolados[i] <<" " << isolados[i+1] <<"\n";
    }

    return 0;
}
