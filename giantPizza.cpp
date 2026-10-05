#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> graph, graphR;
vector<bool> visited;
vector<int> order, scc_id;
int scc_count = 0;

void dfs(int start){
    visited[start] = true;
    for(int v: graph[start]){
        if(!visited[v]) dfs(v);
    }
    order.push_back(start);
}

void dfs1(int start){
    visited[start]=true;
    scc_id[start]=scc_count;
    for(int v: graphR[start]){
        if(!visited[v]) dfs1(v);
    }
}
int node(char sign,int val){
    return sign == '+' ? val : val+m;
}

int neg(int val) {
    return val > m ? val-m : val +m;
}

void two_sat(){
    scc_count = 0;
    
    for(int i =1;i<=2*m; i++){
        if(!visited[i]){
            dfs(i);
        }
    }

    visited.assign(2*m+1,false);

    for(int i = 2*m-1; i>=0;i--){
        int u = order[i];
        if(!visited[u]){
            scc_count++;
            dfs1(u);
        }
    }

    string result ="";
    for(int i = 1;i<=m;i++){
        if(scc_id[i] == scc_id[i+m]) {
            cout<< "IMPOSSIBLE\n";
            return;
        }
        if(scc_id[i] > scc_id[i+m]) {
            result += "+ ";
        }else {
            result += "- ";
        }
    }
    cout <<result << "\n";
    return;
}


int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> n >> m;
    graph.resize(2*m +1);
    graphR.resize(2*m +1);
    visited.assign(2*m+1, false);
    scc_id.resize(2*m+1);

    for(int i = 0 ; i<n;i++){
        char sign1,sign2;
        int val1,val2;
        cin >> sign1 >> val1 >> sign2 >> val2;
        int u = node(sign1,val1);
        int v = node(sign2,val2);
        int negu = neg(u);
        int negv = neg(v);

        graph[negu].push_back(v);
        graphR[v].push_back(negu);

        graph[negv].push_back(u);
        graphR[u].push_back(negv);
    }

    two_sat();

    return 0;
}