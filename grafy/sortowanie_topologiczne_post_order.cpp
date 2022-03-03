#include <iostream>
#include <vector>
#include <stack>
using namespace std;


vector<int> graph[1000001];
bool visited[1000001];
stack<int> sorted_stack;


void dfs(int v) {
    visited[v] = true;

    for (int u : graph[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }

    sorted_stack.push(v);
}


int main() {
    int n, m, a, b;
    cin >> n;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    while (!sorted_stack.empty()) {
        cout << sorted_stack.top() << " ";
        sorted_stack.pop();
    }

}