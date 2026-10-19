/**
 *@file planetsCycles.cpp
 *@brief Resolução do problema "Planets Cycles" do CSES.
 *@link https://cses.fi/problemset/task/1751
 *
 *@details
 *O problema pede, para cada planeta, quantos teleportes são feitos até se repetir um planeta.
 *Algoritmo: percorrer o grafo funcional (cada nó tem exatamente uma saída) guardando o trajeto atual;
 *ao encontrar um nó já visitado no trajeto, identifica-se o ciclo (todos os seus nós têm resposta = tamanho do ciclo),
 *e os nós da "cauda" recebem a resposta do nó seguinte + 1, preenchida de trás para a frente.
 *Complexidade: O(n).
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> graph(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> graph[i];
    }

    vector<int> t(n + 1, 0);
    vector<int> visitado(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (t[i] != 0)
            continue;
        vector<int> viagem;
        int atual = i;
        while (t[atual] == 0 && visitado[atual] == 0)
        {
            viagem.push_back(atual);
            visitado[atual] = viagem.size();
            atual= graph[atual];
        }

        int distancia_base = 0;

        if(t[atual] !=0){
            distancia_base=t[atual];
        }else{
            int inicio_ciclo = visitado[atual] -1;
            int tamanho_ciclo =viagem.size() - inicio_ciclo;
            for(int j = inicio_ciclo; j < viagem.size(); j++){
                t[viagem[j]] =tamanho_ciclo;
            }

            viagem.resize(inicio_ciclo);
            distancia_base = tamanho_ciclo;
        }
        for(int j = (int)viagem.size() -1; j >= 0; j--) {
            distancia_base++;
            t[viagem[j]] = distancia_base;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << t[i] << " ";
    }
    cout << "\n";
    return 0;
}