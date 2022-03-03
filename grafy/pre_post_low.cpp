#include <iostream>
#include <vector>
#include <stack>
using namespace std;


vector<int> graph[1000001];
int pre[1000001];
int post[1000001];
int low[1000001];

int t = 1;

void dfs(int v) {
    pre[v] = t++;
    low[v] = pre[v];

    for (int u : graph[v]) {
        if (pre[u] == 0) {
            // krawedz drzewowa
            dfs(u);
            low[v] = min(low[v], low[u]);
        } else {
            // krawedz powrotna
            low[v] = min(low[v], pre[u]);
        }
    }

    post[v] = t++;
}


// czy a jest przodkiem b
bool is_predecessor(int a, int b) {
    return pre[a] <= pre[b] && post[b] <= post[a];
}


int main() {
    int n, m, a, b;
    cin >> n;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // ukorzeniamy drzewo w wierzchołku 1
    dfs(1);

    return 0;
}