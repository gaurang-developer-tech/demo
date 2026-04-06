#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minRoads(int n, const vector<pair<int, int>>& roads, int src, int dst) {
    // 1. Build the adjacency list
    vector<vector<int>> adj(n);
    for (auto& r : roads) {
        adj[r.first].push_back(r.second);
        adj[r.second].push_back(r.first);
    }

    // 2. Initialize distances and queue
    vector<int> dist(n, -1);
    queue<int> q;
    
    dist[src] = 0;
    q.push(src);

    // 3. BFS Traversal
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == dst) return dist[u];

        for (int v : adj[u]) {
            if (dist[v] == -1) { // If unvisited
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return -1; // Destination unreachable
}

// --- Example Usage ---
int main() {
    vector<pair<int, int>> roads = {{0, 1}, {0, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 5}};
    cout << "Minimum roads: " << minRoads(6, roads, 0, 5) << endl;
    return 0;
}