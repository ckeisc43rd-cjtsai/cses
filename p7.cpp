#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define piii pair<pair<int, int>, int>
#define ff first
#define ss second
using namespace std;
int n;
vector<int> Dijkstra(vector< vector<pii> >& graph, int source) {
    vector<pii> distance(graph.size(), {INT32_MAX, INT32_MAX});
    distance[source] = {0, 0};

    vector<bool> visited(graph.size(), 0);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = 1;

        for (auto& [w, v]: graph[u]) {
            if (distance[v].ff <= distance[u].ff + w) continue;

            distance[v] = distance[u] + w;
            pq.push({distance[v], v});
        }
    }

    return distance;
}

int main(){

}