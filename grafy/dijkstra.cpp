#include <iostream>
#include <vector>
#include <queue>

using namespace std;


const long long INF = 1000000000000009LL;
vector<pair<int, int>> graph[1000001];
long long dist[1000001];
int n;


void dijkstra(int s) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[s] = 0;

    priority_queue<pair<long long, int>> p_queue;
    p_queue.push(make_pair(0, s));

    while (!p_queue.empty()) {
        pair<long long, int> node_dist = p_queue.top();
        p_queue.pop();

        int v = node_dist.second;
        // odległość była dodana z przeciwną wartością
        // należy ją odwrócić
        long long v_dist = -node_dist.first;

        if (v_dist > dist[v]) {
            // nieistotna, powtórzona para na kolejce, 
            // wierzchołek dostał już kiedyś lepszą odległość
            continue;
        }

        for (pair<int, int> neigbour_dist : graph[v]) {
            int u = neigbour_dist.second;
            long long vu_dist = neigbour_dist.first;

            if (v_dist + vu_dist < dist[u]) {
                dist[u] = v_dist + vu_dist;
                // odległości dodajemy z przeciwną wartością
                // dzięki temu kolejka sortuje je w odwrotnej kolejności
                p_queue.push(make_pair(-dist[u], u));
            } 
        } 
    }

}


int main() {
    int m, a, b, c;
    cin >> n >> m;


    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;

        graph[a].push_back(make_pair(b, c));
    }

    dijkstra(1);

    return 0;
}