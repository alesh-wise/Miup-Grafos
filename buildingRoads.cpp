//
// Created by alesh-wise on 20/09/2026.
//
/**
 *@file buildingRoads.cpp
 *@brief Resolução do problema "Building Roads" do CSES.
 *@link https://cses.fi/problemset/result/18802671/
 *
 *@details
 *O problema pede para descobrir o numero de arestas em falta para tornar o grafo atual, num grafo conexo e também quais são essas arestas
 *Foi utilizada uma busca em largura (BFS) para encontrar as diferentes componentes separadas do grafo e criar as arestas em falta.
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
