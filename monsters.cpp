//
// Created by alesh-wise on 20/09/2026.
//
/**
 *@file monsters.cpp
 *@brief Resolução do problema "Monsters" do CSES.
 *@link https://cses.fi/problemset/task/1194
 *
 *@details
 *O problema pede para se possivel descobrir um caminho valido até um dos extremos da grid para o personagem A.
 *Para resolve foi usado dois BFS, um para calcular a distancia de cada ponto da grid até o monstro mais proximo e outro para calcular a distancia do personagem A até os extremos da grid.
 */ 
//
// Created by alesh-wise on 23/09/2026.
//


#include <bits/stdc++.h>
using namespace std;

class coordinates {
    public:
        int x, y;
        coordinates(int x, int y){
            this->x = x;
            this->y = y;
        }
        coordinates(){}

};

static int movimentos[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
static char movimentosChar[4] = {'U', 'D', 'L', 'R'};

int main(){
    int n, m;
    cin >> n >> m;
    char grid[n][m];
    coordinates start;
    vector<coordinates> monsters;
    coordinates origem[n][m];
    char movimentosL[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c =='A') {
                start = coordinates(i, j);
                grid[i][j] = '.';
            } else if (c == 'M') {
                monsters.push_back(coordinates(i, j));
                grid[i][j] = '.';
            }else {
                grid[i][j] = c;
            };
        }
    }
    int distanciaM[n][m];
    int distanciaA[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            distanciaM[i][j] = INT_MAX;
            distanciaA[i][j] = INT_MAX;
        }
    }
    queue<coordinates> q;
    for (int i = 0; i < monsters.size(); i++) {
        distanciaM[monsters[i].x][monsters[i].y] = 0;
        q.push(monsters[i]);
    }
    while (!q.empty()) {
        coordinates atual = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = atual.x + movimentos[i][0];
            int y = atual.y + movimentos[i][1];
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && distanciaM[x][y] > distanciaM[atual.x][atual.y] + 1) {
                distanciaM[x][y] = distanciaM[atual.x][atual.y] + 1;
                q.push(coordinates(x, y));
            }
        }
    }
    coordinates finish(-1, -1);
    bool possivel = false;
    distanciaA[start.x][start.y] = 0;
    q.push(start);
    while (!q.empty()) {
        coordinates atual = q.front();
        q.pop();
        if(atual.x == 0 || atual.x == n - 1 || atual.y == 0 || atual.y == m - 1) {
            finish.x = atual.x;
            finish.y = atual.y;
            possivel = true;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int x = atual.x + movimentos[i][0];
            int y = atual.y + movimentos[i][1];
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && distanciaA[x][y] > distanciaA[atual.x][atual.y] + 1 && distanciaA[atual.x][atual.y] + 1 < distanciaM[x][y]) {
                distanciaA[x][y] = distanciaA[atual.x][atual.y] + 1;
                movimentosL[x][y] = movimentosChar[i];
                origem[x][y] = atual;
                q.push(coordinates(x, y));
            }
        }
    }

    if (!possivel) {
            cout << "NO" << endl;
            return 0;
        } 

        string caminho = "";
        coordinates atual = finish;
        while(atual.x != start.x || atual.y != start.y) {
            caminho += movimentosL[atual.x][atual.y];
            atual = origem[atual.x][atual.y];
        }
        std::reverse(caminho.begin(), caminho.end());
        cout << "YES" << endl;
        cout << caminho.length() << endl;
        cout << caminho << endl;

    return 0;
}