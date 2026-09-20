//
// Created by alexa on 20/09/2026.
//


#include <algorithm>
#include <iostream>
#include <queue>
#include <climits>
#include <variant>

class coordinate {
    public:
    int x, y;
    coordinate(int x, int y) {
        this->x = x;
        this->y = y;
    }


    coordinate() {
        this->x = -1; this->y = -1;
    }
};
static char movimentosLetra[] = {'D', 'R', 'U', 'L'};
static coordinate movimentos[] = {{1,0},{0,1},{-1,0},{0,-1}};
int main() {
    int n,m;
    std::cin >> n >> m;
    char matriz[n][m]; /*representa o mapa*/
    char movimentosL[n][m]; /* movimentos com L,R,D,U*/
    coordinate origem[n][m]; /*guarda a coordenada de origem do ponto atual para conseguir criar o caminho de volta*/
    int dist[n][m]; /*distancia acumulada de cada ponto*/
    bool vis[n][m];
    std::queue<coordinate> q;
    coordinate start(-1,-1),finish(-1,-1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matriz[i][j];
            if (matriz[i][j] == 'A') {
                start.x = i;
                start.y = j;
                q.push(start);
            }
            if (matriz[i][j] == 'B') {
                finish.x = i;
                finish.y = j;
            }
            dist[i][j] = INT_MAX;
            vis[i][j] = false;
        }
    }

    if ((start.x==-1 && start.y==-1) || (finish.x==-1 && finish.y==-1)) {
        std::cout << "NO";
        return 0;
    }
    bool existe = false;
    dist[start.x][start.y] = 0;
    while (!q.empty()) {
        if (existe) break;
        coordinate c = q.front();
        q.pop();
        vis[c.x][c.y] = true;
        for (int i = 0; i < 4; i++) {
            coordinate move = movimentos[i];
            coordinate cAux = coordinate(c.x+move.x, c.y+move.y);
            if (cAux.x < n && cAux.y < m && cAux.x >= 0 && cAux.y >= 0 && matriz[cAux.x][cAux.y] !='#' && dist[cAux.x][cAux.y] > dist[c.x][c.y]+1) {
                origem[cAux.x][cAux.y] = c;
                dist[cAux.x][cAux.y] = dist[c.x][c.y]+1;
                q.push(cAux);
                movimentosL[cAux.x][cAux.y] = movimentosLetra[i];
                if (cAux.x == finish.x && cAux.y == finish.y) {
                    existe = true;
                    break;
                }
            }
        }
    }
    if (existe) {
        std::cout << "YES\n";
        coordinate atual = finish;
        std::string caminho ="";
        while (atual.x != start.x || atual.y != start.y) {
            caminho += movimentosL[atual.x][atual.y];
            atual = origem[atual.x][atual.y];
        }

        std::reverse(caminho.begin(), caminho.end());
        std::cout<<caminho.length() << "\n";
        std::cout<<caminho<<"\n";
    }
    else {
        std::cout << "NO\n";
    }


    return 0;
}
