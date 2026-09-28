#include <bits/stdc++.h>
using namespace std;
int nMax = 30;

vector<vector<int>> build(vector<int> &jump, int n)
{
    vector<vector<int>> up(nMax, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        up[0][i] = jump[i];
    }

    for (int i = 1; i < nMax; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }
    return up;
}

int binaryLifting(int current, vector<vector<int>> &up, int k)
{
    for (int i = 0; i < nMax; i++)
    {
        if ((k & (1 << i)) != 0)
        {
            current = up[i][current];
        }
    }
    return current;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> jump(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> jump[i];
    }

    vector<vector<int>> final = build(jump, n);

    for (int i = 0; i < m; i++)
    {
        int x, k;
        cin >> x >> k;
        cout << binaryLifting(x, final, k) << "\n";
    }

    return 0;
}