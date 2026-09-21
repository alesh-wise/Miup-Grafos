//
// Created by alesh-wise on 20/09/2026.
//
/**
 *@file messageRoute.cpp
 *@brief Resolução do problema "Building Teams" do CSES.
 *@link https://cses.fi/problemset/result/18810287/
 *
 *@details
 *O problema pede para verificar se o grafo, é um grafo bipartido
 */
//
// Created by alexa on 20/09/2026.
//




#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >>m;
    vector<vector<int>> friends(n+1);
    int pupil,connection;
    for(int i=0;i<m;i++) {
        cin >> pupil >> connection;
        friends[pupil].push_back(connection);
        friends[connection].push_back(pupil);
    }
    bool possible = true;
    vector<int> team(n+1,0);
    queue<int> q;
    team[1]=1;

    for(int i=1;i<=n;i++) {

        if (!possible) break;
        if (team[i]==0) { team[i]=1;}
        q.push(i);
        while(!q.empty()) {
            if (!possible) {break;}
            int v = q.front();
            q.pop();
            for (int f: friends[v]) {
                if (team[f] ==0) {
                    team[f]= (team[v] ==1) ? 2 : 1;
                    q.push(f);
                }
                else if (team[f]==team[v]) {
                    possible = false;
                    break;
                }
               }
        }
    }



    if (!possible) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for (int i =1;i<=n;i++) {
        cout << team[i] << " ";
    }



    return 0;
}
