#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

struct aresta
{
    int s, f;
};

class DSU
{
private:
    vector<int> parent, rank, tamanho;

public:
    int nMax, nComponents;

    DSU(int size)
    {
        parent.resize(size + 1);
        rank.assign(size + 1, 0);
        tamanho.assign(size + 1, 1);
        for (int i = 0; i <= size; i++)
        {
            parent[i] = i;
        }
        nMax = 0;
        nComponents = size;
    }

    int find(int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void uniao(int i, int j)
    {
        int iRoot = find(i);
        int jRoot = find(j);
        if (jRoot == iRoot)
            return;
        if (rank[iRoot] < rank[jRoot])
        {
            int parentIroot = parent[iRoot];
            parent[iRoot] = jRoot;
            tamanho[jRoot] += tamanho[parentIroot];
            nMax = nMax < tamanho[jRoot] ? tamanho[jRoot] : nMax;
        }
        else if (rank[iRoot] > rank[jRoot])
        {
            int parentJRoot = parent[jRoot];
            parent[jRoot] = iRoot;
            tamanho[iRoot] += tamanho[parentJRoot];
            nMax = nMax < tamanho[iRoot] ? tamanho[iRoot] : nMax;
        }
        else
        {
            int parentIRoot = parent[iRoot];
            parent[iRoot] = jRoot;
            tamanho[jRoot] += tamanho[parentIRoot];
            nMax = nMax < tamanho[jRoot] ? tamanho[jRoot] : nMax;
            rank[jRoot]++;
        }
        nComponents--;
    }

public:
    int getnComponents()
    {
        return nComponents;
    }

public:
    int getnMax()
    {
        return nMax;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<aresta> arestas;
    for (int i = 0; i < m; i++)
    {
        aresta atual;
        cin >> atual.s >> atual.f;
        arestas.push_back(atual);
    }
    DSU dsu(n);
    for (int i = 0; i < m; i++)
    {
        dsu.uniao(arestas[i].s, arestas[i].f);
        cout << dsu.getnComponents() << " " << dsu.getnMax() << "\n";
    }
    return 0;
}