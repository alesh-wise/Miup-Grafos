//
// Created by alesh-wise on 20/09/2026.
//
/**
 *@file messageRoute.cpp
 *@brief Resolução do problema "Message Route" do CSES.
 *@link https://cses.fi/problemset/result/18805235/
 *
 *@details
 *O problema pede para se possivel descobrir a rota mais curta entre dois pontos.
 */
//
// Created by alesh-wise on 20/09/2026.
//


#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <climits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> grid(n+1);
    std::queue<int> q;
    int point, connect;
    for(int i=0;i<m;i++) {
        std::cin>>point >> connect;
        grid.at(point).push_back(connect);
        grid.at(connect).push_back(point);

    }

    int ordem[n+1];
    bool exist = false;
    std::vector<int> distancia(n+1, INT_MAX);

    distancia[1] = 0;
    q.push(1);
    while(!q.empty()) {
        if (exist) {break;}
        int x = q.front();
        q.pop();
        for (int aux: grid[x]) {
            if(distancia[aux] > distancia[x] + 1) {
                distancia[aux] = distancia[x] + 1;
                ordem[aux] = x;
                if (aux == n) {
                    exist = true;
                    break;
                }
                q.push(aux);
            }

        }
    }

    if(!exist) {
        std::cout << "IMPOSSIBLE";
        return 0;
    }
    int temp = n;

    std::vector<int> caminho;
    do {
        caminho.push_back(temp);
        temp = ordem[temp];

    }while(temp!= 1);

    caminho.push_back(1);
    std::reverse(caminho.begin(), caminho.end());
    std::cout << caminho.size() << "\n";
    for (int i : caminho) {
        std::cout << i << " ";
    }
    return 0;
}
