//
// Created by alesh-wise on 20/09/2026.
//
/**
 *@file countingRooms.cpp
 *@brief Resolução do problema "Counting Rooms" do CSES.
 *@link https://cses.fi/problemset/task/1192
 *
 *@details
 *O problema pede para encontrar o numero de "rooms", ou seja o numero de componentes conexas do Grafo.
 *Foi utilizada uma busca em largura (BFS) com uma queue.
 */

#include <iostream>
#include <queue>



struct coordinate {
    int x;
    int y;
};

int main() {
    int n,m;

    std::cin >> n >> m;
    char map[n][m];
    bool vis[n][m];
    std::queue <coordinate> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> map[i][j];
            vis[i][j] = false;
            if (map[i][j] == '.') {
                q.push({i,j});
            }
        }
    }

    coordinate movimentos[] = {
        {1,0}, {0,1}, {0,-1}, {-1,0}
    };

    int contagem =0;
    while (!q.empty()) {
        coordinate c = q.front();
        q.pop();
        if (vis[c.x][c.y]) { continue;}
        contagem++;
        std::queue<coordinate> aux;
        aux.push(c);
        while (!aux.empty()) {
            coordinate c = aux.front();
            aux.pop();
            if (vis[c.x][c.y]) { continue; }
            vis[c.x][c.y] = true;
            for (coordinate vizinho : movimentos) {
                coordinate newC = coordinate{c.x+vizinho.x, c.y+vizinho.y};
                if (newC.x >= 0 && newC.x < n && newC.y >= 0 && newC.y < m && map[newC.x][newC.y] == '.') {
                    aux.push(newC);
                }
            }
        }
    }
    std::cout << contagem;
    return 0;
}
