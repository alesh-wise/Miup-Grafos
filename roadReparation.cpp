#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

class DSU
{
private:
    vector<int> parent, rank;

public:
    DSU(int size)
    {
        parent.resize(size +1);
        rank.assign(size+1,0);
        for (int i = 0; i <= size; i++)
        {
            parent[i] = i;
        }
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
            parent[iRoot] = jRoot;
        }
        else if (rank[iRoot] > rank[jRoot])
        {
            parent[jRoot] = iRoot;
        }
        else
        {
            parent[iRoot] = jRoot;
            rank[jRoot]++;
        }
    }
};

struct aresta
{
    int s,e;
    long long w;
    bool operator<(aresta &outro) const
    {
        return this->w > outro.w;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<aresta> graph(m);
    for (int i = 0; i < m; i++)
    {
        aresta atual;
        cin >> atual.s >> atual.e >> atual.w;
        graph[i]=atual;
       }

    long long cost = 0, count = 0;
    bool possible = false;
    sort(graph.begin(), graph.end(), [](const aresta &a, const aresta &b)
         { return a.w < b.w; });
    DSU dsu(n);

    for(aresta row: graph) {
        int s = (int) row.s;
        int e = (int) row.e;
        long long w = (long long)row.w;

        if(dsu.find(s) != dsu.find(e)) {
            dsu.uniao(s,e);
            cost +=w;
            if(++count == n-1) {
                possible = true;
                break;
            }
        }
    }
    if(possible) {cout <<cost << "\n";}
    else {cout << "IMPOSSIBLE\n";}
    return 0;
}