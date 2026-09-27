#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    vector<int> indegree(n + 1,0);
    queue<int> q;
    vector<int> result;
    for (int i = 1; i <= n; i++) {
        for(int next: graph[i] ) {
            indegree[next]++;
        }
    }

    for ( int i = 1; i <=n; i++){
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int top = q.front();
        q.pop();
        result.push_back(top);
        for ( int next: graph[top]){
            indegree[next]--;
            if (indegree[next] ==0){
                q.push(next);
            }
        }
    }
    if(result.size() == 0 || result.size() != n ){
        cout << "IMPOSSIBLE\n";
    }else {
        for (int i = 0 ; i< result.size() ; i++) {
            cout << result[i] << " ";
        }
    }
    cout << "\n";

        return 0;
}